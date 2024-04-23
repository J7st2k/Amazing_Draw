#include "area.h"
#include <QPainter>

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(500,300));
    mytrngl=new MyTrngl(100,150,150,50,50,100);
    myrect=new MyRect(50,150,150,150,150,50,50,50);
    alpha=0;
}

void Area::showEvent(QShowEvent*)
{
    myTimer=startTimer(50); // создать таймер
}

void Area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    mytrngl->draw(alpha, h, &painter);
    myrect->draw(h, &painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer)    // если наш таймер
    {
        alpha+=0.3;
        mytrngl->rotate(alpha);
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
