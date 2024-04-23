#include <math.h>
#include "figure.h"

// void Figure::move(float Alpha,QPainter *Painter)
// {
//     dx=halflen*cos(Alpha);
//     dy=halflen*sin(Alpha);
//     //draw(Painter);
// }

void MyTrngl::draw(float Alpha, float h, QPainter *Painter)
{
    Painter->drawLine(x0,y0,x1,y1);
    Painter->drawLine(x1,y1,x2,y2);
    Painter->drawLine(x2,y2,x0,y0);
}

void MyRect::draw(float h, QPainter *Painter)
{
    Painter->drawLine(x0,y0,x1,y1);
    Painter->drawLine(x1,y1,x2,y2);
    Painter->drawLine(x2,y2,x3,y3);
    Painter->drawLine(x3,y3,x0,y0);
}
