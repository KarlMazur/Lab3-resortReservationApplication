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
}

ResortReservation::~ResortReservation()
{
    delete ui;
}

void ResortReservation::on_NextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void ResortReservation::on_radioButton_clicked()
{
    ui->nextButton->show();
}

void ResortReservation::on_comboBox_activated(const QString &arg1)
{
        QString standardTwoQueenRoom  ="A Standard 2-queen room";
      QString standardOneKingRoom ="A Standard 1-king room";
      QString atriumTwoQueenRoom ="An Atrium 2-queen room";
  QString atriumOneKingRoom  ="An Atrium 1-king room";

  if(arg1==standardTwoQueenRoom){
      ui->ActualPriceLabel->setText("$284");
  }
  else if(arg1==standardOneKingRoom){
      ui->ActualPriceLabel->setText("$290");
  }
  else if(arg1==atriumTwoQueenRoom){
        ui->ActualPriceLabel->setText("$325");
    }

    else if(arg1==atriumOneKingRoom){

        ui->ActualPriceLabel->setText("$350");
}
}
