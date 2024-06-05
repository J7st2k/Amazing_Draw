#include "area.h"
#include <QPainter>

Area::Area(QWidget *parent):QWidget(parent)
{
    x = 6; y = 6; z = 6;
    alpha = 0;
    setFixedSize(QSize(500,500));
    float ** Ver;
    Ver = new float*[4];
    Ver[0] = new float[3]{ 0,-2,0 };
    Ver[1] = new float[3]{ 0,2,0 };
    Ver[2] = new float[3]{ 2,0,0 };
    Ver[3] = new float[3]{ 0,0,4 };

    mypyramid = new figure(x, y, z, Ver, 4);
}

void Area::showEvent(QShowEvent*)
{
    myTimer=startTimer(10); // создать таймер
}

void Area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    mypyramid->rotate(0.01);
    mypyramid->draw(&painter);

}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer)    // если наш таймер
    {
        //if(alpha < 15) alpha += 0.01;
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
