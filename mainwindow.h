#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include "area.h"
class Window:public QWidget
{
protected:
    Area * area; // область отображения рисунка
    QPushButton * exitbtn;
    QPushButton * animbtn;
public:
    Window();
};
#endif // MAINWINDOW_H
