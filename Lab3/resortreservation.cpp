#include "resortreservation.h"
#include "ui_resortreservation.h"
#include "iostream"
#include "string"
ResortReservation::ResortReservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResortReservation)
{
    ui->setupUi(this);

ui->nextButton->hide();
QDate issueDate=QDate::currentDate();
QDate newDate=issueDate.addDays(1);

ui->endDateCalander->setDate(newDate);
ui->startDateCalander->setDate(QDate::currentDate());


}

ResortReservation::~ResortReservation()
{
    delete ui;
}





void ResortReservation::on_numberOfAdultsSpinBox_valueChanged(int arg1)
{
    int maximumNumberOfAdults=ui->numberOfAdultsSpinBox->value();
    if(arg1==1&&arg1<=maximumNumberOfAdults){
        ui->numberOfChildrenSpinBox->setMaximum(3);
        ui->nextButton->show();
    }
    else if(arg1==2&&arg1<=maximumNumberOfAdults){
        ui->numberOfChildrenSpinBox->setMaximum(2);
        ui->nextButton->show();
    }
   else if(arg1==3&&arg1<=maximumNumberOfAdults){
        ui->numberOfChildrenSpinBox->setMaximum(1);
        ui->nextButton->show();
    }
    else if(arg1==4&&arg1<=maximumNumberOfAdults){
         ui->numberOfChildrenSpinBox->setMaximum(0);
         ui->nextButton->show();
}
}
void ResortReservation::on_numberOfChildrenSpinBox_valueChanged(int arg1)
{
    int maximumNumberOfAdults=ui->numberOfAdultsSpinBox->value();
    if(arg1==1&&arg1<=maximumNumberOfAdults){
        ui->numberOfAdultsSpinBox->setMaximum(3);
        ui->nextButton->show();
    }
    else if(arg1==2&&arg1<=maximumNumberOfAdults){
        ui->numberOfAdultsSpinBox->setMaximum(2);
        ui->nextButton->show();
    }
    else if(arg1==3&&arg1<=maximumNumberOfAdults){
        ui->numberOfAdultsSpinBox->setMaximum(1);
        ui->nextButton->show();
    }
}







void ResortReservation::on_startDateCalander_dateChanged(const QDate &date)
{


    QDate newDate=date.addDays(1);

ui->endDateCalander->setDate(newDate);
}


void ResortReservation::on_startDateCalander_userDateChanged(const QDate &date)
{

    QDate maxDate=date.addDays(8);
    QDate minDate=ui->startDateCalander->date();
            minDate=minDate.addDays(1);
    ui->endDateCalander->setMinimumDate(minDate);
  ui->endDateCalander->setMaximumDate(maxDate);
}






void ResortReservation::on_nextButton_clicked()
{
int finalCost=0;
int tax=0;
ui->roomReservation->setCurrentIndex(1);
QString roomType= ui->roomTypeSelection->currentText();


}

void ResortReservation::on_roomTypeSelection_activated(const QString &arg1)
{
    QString standardTwoQueenRoom  ="A Standard 2-queen room";
  QString standardOneKingRoom ="A Standard 1-king room";
  QString atriumTwoQueenRoom ="An Atrium 2-queen room";
QString atriumOneKingRoom  ="An Atrium 1-king room";

if(arg1==standardTwoQueenRoom){
  ui->actualPriceLabel->setText("$284");
  ui->numberOfAdultsSpinBox->setMaximum(4);
  ui->numberOfChildrenSpinBox->setMaximum(3);
}
else if(arg1==standardOneKingRoom){
  ui->actualPriceLabel->setText("$290");
  ui->numberOfAdultsSpinBox->setMaximum(3);
  ui->numberOfChildrenSpinBox->setMaximum(2);
}
else if(arg1==atriumTwoQueenRoom){
    ui->actualPriceLabel->setText("$325");
    ui->numberOfAdultsSpinBox->setMaximum(4);
    ui->numberOfChildrenSpinBox->setMaximum(3);
}

else if(arg1==atriumOneKingRoom){
    ui->actualPriceLabel->setText("$350");
    ui->numberOfAdultsSpinBox->setMaximum(4);
    ui->numberOfChildrenSpinBox->setMaximum(3);
}
}

void ResortReservation::on_roomTypeSelection_currentIndexChanged(const QString &arg1)
{
    QString defaultText = "------------------------------------------";
    if(arg1==defaultText)
        ui->nextButton->hide();
    else
        ui->nextButton->show();

}
