#ifndef FIGURE_H
#define FIGURE_H
#include <QPainter>

class MyTrngl
{
    float x[3];
    float y[3];
public:
    MyTrngl(float X0, float Y0, float X1, float Y1, float X2, float Y2);
    void draw(float Alpha, float h, QPainter *Painter);
    void rotate(float Alpha);
};

class MyRect
{
    float x[4];
    float y[4];
public:
    MyRect(float X0, float Y0, float X1, float Y1, float X2, float Y2, float X3, float Y3);
    void draw(float h, QPainter *Painter);
};

#endif // FIGURE_H
