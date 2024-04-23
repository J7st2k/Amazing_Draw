#ifndef FIGURE_H
#define FIGURE_H
#include <QPainter>

class Figure
{
protected:
    int x0, y0, x1, y1;
    float h;
    virtual void draw(float Alpha, float h, QPainter *Painter)=0;
public:
    Figure(int X0,int Y0,int X1,int Y1):x0(X0),y0(Y0),x1(X1),y1(Y1){}
};

class MyTrngl:public Figure
{
public:
    MyTrngl(int X0,int Y0,int X1,int Y1):Figure(x0,y0,x1,y1){}
    void draw(float Alpha, float h, QPainter *Painter);
};

class MyRect:public Figure
{
public:
    MyRect(int X0,int Y0,int X1,int Y1):Figure(x0,y0,x1,y1){}
    void draw(float Alpha, float h, QPainter *Painter);
};

#endif // FIGURE_H
