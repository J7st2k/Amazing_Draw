#include <math.h>
#include "figure.h"

// void Figure::move(float Alpha,QPainter *Painter)
// {
//     dx=halflen*cos(Alpha);
//     dy=halflen*sin(Alpha);
//     //draw(Painter);
// }

MyTrngl::MyTrngl(float X0, float Y0, float X1, float Y1, float X2, float Y2)
{
    x[0]=(X0);
    y[0]=(Y0);
    x[1]=(X1);
    y[1]=(Y1);
    x[2]=(X2);
    y[2]=(Y2);
}

void MyTrngl::draw(QPainter *Painter)
{
    Painter->drawLine(x[0],y[0],x[1],y[1]);
    Painter->drawLine(x[1],y[1],x[2],y[2]);
    Painter->drawLine(x[2],y[2],x[0],y[0]);
}

void MyTrngl::rotate(float Alpha)
{

    // for(int i=0; i < 3; i++) {
    //     y[i]*=(-1.);
    //     // x[i]+=200;
    //     // y[i]+=200;
    // }

    for(int i=0; i < 3; i++) {
        x[i]+=100;
        y[i]+=100;
    }

    for(int i=0; i < 3; i++) {
        x[i]=x[i]*cos(Alpha)-y[i]*sin(Alpha);
        y[i]=x[i]*sin(Alpha)+y[i]*cos(Alpha);
    }

    for(int i=0; i < 3; i++) {
        x[i]+=100;
        y[i]+=100;
    }

    // for(int i=0; i < 3; i++) {
    //     // x[i]-=200;
    //     // y[i]-=200;
    //     y[i]*=(-1.);
    // }
}

MyRect::MyRect(float X0, float Y0, float X1, float Y1, float X2, float Y2, float X3, float Y3)
{
    x[0]=(X0);
    y[0]=(Y0);
    x[1]=(X1);
    y[1]=(Y1);
    x[2]=(X2);
    y[2]=(Y2);
    x[3]=(X3);
    y[3]=(Y3);
}

void MyRect::draw(QPainter *Painter)
{
    Painter->drawLine(x[0],y[0],x[1],y[1]);
    Painter->drawLine(x[1],y[1],x[2],y[2]);
    Painter->drawLine(x[2],y[2],x[3],y[3]);
    Painter->drawLine(x[3],y[3],x[0],y[0]);
}
