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










    void on_numberOfAdultsSpinBox_valueChanged(int arg1);

    void on_numberOfChildrenSpinBox_valueChanged(int arg1);







    void on_startDateCalander_dateChanged(const QDate &date);



    void on_startDateCalander_userDateChanged(const QDate &date);





    void on_nextButton_clicked();

    void on_roomTypeSelection_activated(const QString &arg1);

    void on_roomTypeSelection_currentIndexChanged(const QString &arg1);



    void on_creditCardType_currentIndexChanged(const QString &arg1);

    void on_goBackButton_clicked();

    void on_confirmationButton_clicked();


    void on_exitButton_clicked();



    void on_endDateCalander_dateChanged(const QDate &date);








    void on_reservationNameText_copyAvailable(bool b);

private:
    Ui::ResortReservation *ui;
};

#endif // RESORTRESERVATION_H
