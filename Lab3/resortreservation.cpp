#include "resortreservation.h"
#include "ui_resortreservation.h"
#include "iostream"
ResortReservation::ResortReservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResortReservation)
{
    ui->setupUi(this);
    std::cout<<"helloWorld"<<std::endl;
}

ResortReservation::~ResortReservation()
{
    delete ui;
}
