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

private slots:
    void on_NextButton_clicked();



    void on_radioButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::ResortReservation *ui;
};

#endif // RESORTRESERVATION_H
