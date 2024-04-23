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

}

void MyRect::draw(float Alpha, float h, QPainter *Painter)
{
    dx=halflen*cos(Alpha);
    dy=halflen*sin(Alpha);
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
