#ifndef RESORTRESERVATION_H
#define RESORTRESERVATION_H

#include <QMainWindow>

namespace Ui {
class ResortReservation;
}

class ResortReservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResortReservation(QWidget *parent = nullptr);
    ~ResortReservation();

private:
    Ui::ResortReservation *ui;
};

#endif // RESORTRESERVATION_H
