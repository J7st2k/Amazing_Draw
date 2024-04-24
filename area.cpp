#include "area.h"
#include <QPainter>
#include <QTransform>

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(200,200));
    mytrngl=new MyTrngl(100,150,150,50,50,100);
    myrect=new MyRect(50,150,150,150,150,50,50,50);
    alpha=0;
    h=1;
}

void Area::showEvent(QShowEvent*)
{
    myTimer=startTimer(1.2); // создать таймер
}

void Area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    QTransform trans1, trans2;

    painter.save();
    trans1.translate(100, 100);
    trans1.rotate(alpha);
    trans1.scale(h,h);
    trans1.translate(-100, -100);
    painter.setTransform(trans1);
    mytrngl->draw(&painter);
    painter.restore();

    painter.save();
    trans2.translate(100, 100);
    trans2.scale(2-h,2-h);
    trans2.translate(-100, -100);
    painter.setTransform(trans2);
    myrect->draw(&painter);
    painter.restore();
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer)    // если наш таймер
    {
        alpha+=0.2;
        h*=0.9999;
        //mytrngl->rotate(alpha);
        update();   // обновить внешний вид
    }
    else
        QWidget::timerEvent(event);     // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer);     // уничтожить таймер
}

Area::~Area()
{
    delete mytrngl;
    delete myrect;
}
