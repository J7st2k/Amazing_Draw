#include "mainwindow.h"
#include <QLayout>
//#include <QVBoxLayout>


Window::Window()
{
    this->setWindowTitle("Обработка событий");
    area = new Area(this);
    exitbtn = new QPushButton("Завершить", this);
    animbtn = new QPushButton("Крутить", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(animbtn);
    layout->addWidget(exitbtn);
    connect(exitbtn, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(animbtn, &QPushButton::clicked, area, &Area::startTime);
}
