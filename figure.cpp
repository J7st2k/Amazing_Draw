
#include <math.h>
#include "figure.h"


float *figure::TS(float *coord) {
    float * res = new float[3]{ 0 };
    res[0] = coord[0] - x0;
    res[1] = coord[1] - y0;	//T
    res[2] = coord[2] - z0;

    res[0] = -res[0];		//S

    return res;
}

float *figure::R90x(float *coord)
{
    float * res = new float[3]{ 0 };
    res[0] = coord[0];
    res[1] = coord[2];
    res[2] = -coord[1];

    return res;
}

float *figure::Ruy(float *coord)
{
    float * res = new float[3]{ 0 };
    float cosu = y0 / sqrt(x0*x0 + y0 * y0);
    float sinu = x0 / sqrt(x0*x0 + y0 * y0);
    res[0] = coord[0] * cosu - coord[2] * sinu;
    res[1] = coord[1];
    res[2] = coord[0] * sinu + coord[2] * cosu;

    return res;
}

float *figure::Rwx(float *coord)
{
    float * res = new float[3]{ 0 };
    float cosw = sqrt(x0*x0 + y0 * y0) / sqrt(x0*x0 + y0 * y0 + z0 * z0);
    float sinw = z0 / sqrt(x0*x0 + y0 * y0 + z0 * z0);
    res[0] = coord[0];
    res[1] = coord[1] * cosw + coord[2] * sinw;
    res[2] = -coord[1] * sinw + coord[2] * cosw;

    return res;
}

float *figure::comp(float *coord)
{
    float * res = new float[3]{ 0 };
    res = TS(coord);
    res = R90x(res);
    res = Ruy(res);
    res = Rwx(res);

    return res;
}
