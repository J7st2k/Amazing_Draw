#include "area.h"
#include <QPainter>

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(500,500));
    float ** Ver;
    Ver = new float*[4];
    Ver[0] = new float[3]{ 0,-2,0 };
    Ver[1] = new float[3]{ 0,2,0 };
    Ver[2] = new float[3]{ 2,0,0 };
    Ver[3] = new float[3]{ 0,0,4 };

    mypyramid = new figure(6, 6, 5, Ver, 4);
}

void Area::showEvent(QShowEvent*)
{
    myTimer=startTimer(1.2); // создать таймер
}

void Area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    mypyramid->draw(&painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer)    // если наш таймер
    {
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
    delete mypyramid;
}
