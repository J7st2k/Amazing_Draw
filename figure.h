#ifndef FIGURE_H
#define FIGURE_H
#include <QPainter>
#include <QtMath>

class figure
{
    int n;
    float x0, y0, z0;
    float ** Ver;
    float ** VerNa;
    float ** VerKa;
    float ** VerEk;
public:
    figure(float X0, float Y0, float Z0, float** ver, int N):x0(X0), y0(Y0), z0(Z0), Ver(ver), n(N){
        VerNa = new float*[N];
        VerKa = new float*[N];
        VerEk = new float*[N];
        for (int i = 0; i < N; i++) {
            VerNa[i] = new float[3]{ 0 };
            VerKa[i] = new float[2]{ 0 };
            VerEk[i] = new float[2]{ 0 };
        }
    }
    ~figure() {
        for (int i = 0; i < n; i++) {
            delete VerNa[i];
            delete VerKa[i];
            delete VerEk[i];
        }
    }

    float * TS(float *coord); //матрицы
    float * R90x(float *coord);
    float * Ruy(float *coord);
    float * Rwx(float *coord);
    float * comp(float *coord);

    void rotate(float alpha) {
        float tmpX = x0*qCos(alpha) - z0*qSin(alpha);
        float tmpZ = x0*qSin(alpha) + z0*qCos(alpha);
        x0 = tmpX; z0 = tmpZ;
    }

    void toCKH() {
        for (int i = 0; i < n; i++) // to CKH
            VerNa[i] = comp(Ver[i]);
    }

    void toCKK() {
        for (int i = 0; i < n; i++) // to CKK
            for (int j = 0; j < 2; j++)
                VerKa[i][j] = VerNa[i][j];
    }

    void toCKE(int P, int xc, int yc, int xe, int ye) {
        for (int i = 0; i < n; i++) {
            VerEk[i][0] = (VerKa[i][0] / P)*xe + xc;
            VerEk[i][1] = (VerKa[i][1] / P)*ye + yc;
        }
    }

    void draw(QPainter* p) {
        toCKH();
        toCKK();
        toCKE(4, 250, 175, 200, 200);
        p->drawLine(VerEk[0][0], VerEk[0][1], VerEk[1][0], VerEk[1][1]);
        p->drawLine(VerEk[0][0], VerEk[0][1], VerEk[2][0], VerEk[2][1]);
        p->drawLine(VerEk[0][0], VerEk[0][1], VerEk[3][0], VerEk[3][1]);
        p->drawLine(VerEk[1][0], VerEk[1][1], VerEk[2][0], VerEk[2][1]);
        p->drawLine(VerEk[1][0], VerEk[1][1], VerEk[3][0], VerEk[3][1]);
        p->drawLine(VerEk[2][0], VerEk[2][1], VerEk[3][0], VerEk[3][1]);
    }
};

#endif // FIGURE_H
