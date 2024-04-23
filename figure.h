#ifndef FIGURE_H
#define FIGURE_H
#include <QPainter>

class MyTrngl
{
    float x0,y0,x1,y1,x2,y2;
public:
    MyTrngl(float X0, float Y0, float X1, float Y1, float X2, float Y2):
        x0(X0),y0(Y0),x1(X1),y1(Y1),x2(X2),y2(Y2){}
    void draw(float Alpha, float h, QPainter *Painter);
};

class MyRect
{
    float x0,y0,x1,y1,x2,y2,x3,y3;
public:
    MyRect(float X0, float Y0, float X1, float Y1, float X2, float Y2, float X3, float Y3):
        x0(X0),y0(Y0),x1(X1),y1(Y1),x2(X2),y2(Y2),x3(X3),y3(Y3){}
    void draw(float h, QPainter *Painter);
};

#endif // FIGURE_H
