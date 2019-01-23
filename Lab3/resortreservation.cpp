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
ui->StartDateEdit->setDate(QDate::currentDate());
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
      ui->numberOfAdultsSpinBox->setMaximum(4);
      ui->numberOfChildrenSpinBox->setMaximum(3);
  }
  else if(arg1==standardOneKingRoom){
      ui->ActualPriceLabel->setText("$290");
      ui->numberOfAdultsSpinBox->setMaximum(3);
      ui->numberOfChildrenSpinBox->setMaximum(2);
  }
  else if(arg1==atriumTwoQueenRoom){
        ui->ActualPriceLabel->setText("$325");
        ui->numberOfAdultsSpinBox->setMaximum(4);
        ui->numberOfChildrenSpinBox->setMaximum(3);
    }

    else if(arg1==atriumOneKingRoom){
        ui->ActualPriceLabel->setText("$350");
        ui->numberOfAdultsSpinBox->setMaximum(4);
        ui->numberOfChildrenSpinBox->setMaximum(3);
}
}



void ResortReservation::on_numberOfAdultsSpinBox_valueChanged(int arg1)
{
    int maximumNumberOfAdults=ui->numberOfAdultsSpinBox->value();
    if(arg1==1&&arg1<=maximumNumberOfAdults){
        ui->numberOfChildrenSpinBox->setMaximum(3);
    }
    else if(arg1==2&&arg1<=maximumNumberOfAdults){
        ui->numberOfChildrenSpinBox->setMaximum(2);
    }
   else if(arg1==3&&arg1<=maximumNumberOfAdults){
        ui->numberOfChildrenSpinBox->setMaximum(1);
    }
    else if(arg1==4&&arg1<=maximumNumberOfAdults){
         ui->numberOfChildrenSpinBox->setMaximum(0);
}
}
void ResortReservation::on_numberOfChildrenSpinBox_valueChanged(int arg1)
{
    int maximumNumberOfAdults=ui->numberOfAdultsSpinBox->value();
    if(arg1==1&&arg1<=maximumNumberOfAdults){
        ui->numberOfAdultsSpinBox->setMaximum(3);
    }
    else if(arg1==2&&arg1<=maximumNumberOfAdults){
        ui->numberOfAdultsSpinBox->setMaximum(2);
    }
    else if(arg1==3&&arg1<=maximumNumberOfAdults){
        ui->numberOfAdultsSpinBox->setMaximum(1);
    }
}



void ResortReservation::on_StartDateEdit_userDateChanged(const QDate &date)
{
   ui-set
}
