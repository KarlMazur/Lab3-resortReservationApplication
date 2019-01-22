#include "resortreservation.h"
#include "ui_resortreservation.h"

ResortReservation::ResortReservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResortReservation)
{
    ui->setupUi(this);
}

ResortReservation::~ResortReservation()
{
    delete ui;
}
