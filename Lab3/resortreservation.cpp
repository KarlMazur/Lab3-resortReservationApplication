#include "resortreservation.h"
#include "ui_resortreservation.h"
#include "iostream"
#include "string"
#include <QMessageBox>
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
ui->startDateCalander->setMinimumDate(QDate::currentDate());
 newDate=issueDate.addDays(8);
ui->endDateCalander->setMaximumDate(newDate);
QString backgroundFileName=":/images/Resort Background.jpg";
QPixmap background;
background.load(backgroundFileName);
background = background.scaled(this->size(),Qt::KeepAspectRatioByExpanding);

QPalette palette;
palette.setBrush(QPalette::Background,background);
this->setPalette(palette);
this->show();
 ui->estimatecostLabel->setText("0");




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
ui->roomReservation->setCurrentIndex(1);
    double finalCost=0;
double costOfRoomOneNight=0;
double costOfRoom=0;
double tax=0;
double resortFee=15;
double firstDay=0;
double lastDay=0;
double days=0;
double vechileCost=0;
QString stringCostOfRoom;
QString stringtaxCost;
QString stringResortFee;
QString stringfinalCost;
QString finalvechileCost;
QString reservationName=ui->reservationNameText->toPlainText();
ui->nameOnReservation->setText(reservationName);


QString roomType= ui->roomTypeSelection->currentText();
ui->roomTypeLabel->setText(roomType);
QString costOfRoomText=ui->actualPriceLabel->text();
costOfRoomOneNight=costOfRoomText.toInt();
bool parking=ui->vechicleParkingCheckBox->checkState();

QDate beginningDate=ui->startDateCalander->date();
QDate endDate=ui->endDateCalander->date();
firstDay=beginningDate.day();
lastDay=endDate.day();
days =lastDay-firstDay;
if(parking==1){
    vechileCost=12.75*days;
    finalCost=finalCost+vechileCost;
    finalvechileCost=QString::number(vechileCost);
    ui->parkingCostLabel->setText(finalvechileCost);
}
else{
    ui->parkingCostLabel->setText("$0");
}
resortFee=resortFee*days;
costOfRoom=costOfRoomOneNight*days;
tax=costOfRoom*.15;
finalCost=finalCost+tax+costOfRoom+resortFee;
stringCostOfRoom=QString::number(costOfRoom);
stringtaxCost=QString::number(tax,'f',2);
stringResortFee=QString::number(resortFee,'f',2);
stringfinalCost=QString::number(finalCost,'f',2);
ui->priceForRoomLabel->setText(stringCostOfRoom);
ui->taxCostLabel->setText(stringtaxCost);
ui->ResortCostLabel->setText(stringResortFee);
ui->totalCostLabel->setText(stringfinalCost);
ui->creditCardNumber->setInputMask("9999-999999-99999;_");
ui->expDateLineEdit->setInputMask("99/9999;_");
}

void ResortReservation::on_roomTypeSelection_activated(const QString &arg1)
{
    QString standardTwoQueenRoom  ="A Standard 2-queen room";
  QString standardOneKingRoom ="A Standard 1-king room";
  QString atriumTwoQueenRoom ="An Atrium 2-queen room";
QString atriumOneKingRoom  ="An Atrium 1-king room";
 ui->estimatecostLabel->setText("0");

if(arg1==standardTwoQueenRoom){
  ui->actualPriceLabel->setText("284");

  ui->numberOfAdultsSpinBox->setMaximum(4);
  ui->numberOfChildrenSpinBox->setMaximum(3);
  QDate beginDate= ui->startDateCalander->date();
  QDate endDate=ui->endDateCalander->date();
  int days= endDate.day()-beginDate.day();
  int costOfRoom=0;
  int finalEstimateCost=0;
  QString finalEstimateCostString;
 QString costOfRoomString=ui->actualPriceLabel->text();
  costOfRoom=costOfRoomString.toInt();
 finalEstimateCost=costOfRoom*days;
 finalEstimateCostString=QString::number(finalEstimateCost);
    ui->estimatecostLabel->setText(finalEstimateCostString);

}
else if(arg1==standardOneKingRoom){
  ui->actualPriceLabel->setText("290");

  ui->numberOfAdultsSpinBox->setMaximum(3);
  ui->numberOfChildrenSpinBox->setMaximum(2);
  QDate beginDate= ui->startDateCalander->date();
  QDate endDate=ui->endDateCalander->date();
  int days= endDate.day()-beginDate.day();
  int costOfRoom=0;
  int finalEstimateCost=0;
  QString finalEstimateCostString;
 QString costOfRoomString=ui->actualPriceLabel->text();
  costOfRoom=costOfRoomString.toInt();
 finalEstimateCost=costOfRoom*days;
 finalEstimateCostString=QString::number(finalEstimateCost);
    ui->estimatecostLabel->setText(finalEstimateCostString);
}
else if(arg1==atriumTwoQueenRoom){
    ui->actualPriceLabel->setText("325");

    ui->numberOfAdultsSpinBox->setMaximum(4);
    ui->numberOfChildrenSpinBox->setMaximum(3);
    QDate beginDate= ui->startDateCalander->date();
    QDate endDate=ui->endDateCalander->date();
    int days= endDate.day()-beginDate.day();
    int costOfRoom=0;
    int finalEstimateCost=0;
    QString finalEstimateCostString;
   QString costOfRoomString=ui->actualPriceLabel->text();
    costOfRoom=costOfRoomString.toInt();
   finalEstimateCost=costOfRoom*days;
   finalEstimateCostString=QString::number(finalEstimateCost);
      ui->estimatecostLabel->setText(finalEstimateCostString);
}

else if(arg1==atriumOneKingRoom){
    ui->actualPriceLabel->setText("350");
    QDate beginDate= ui->startDateCalander->date();
    QDate endDate=ui->endDateCalander->date();
    int days= endDate.day()-beginDate.day();
    int costOfRoom=0;
    int finalEstimateCost=0;
    QString finalEstimateCostString;
   QString costOfRoomString=ui->actualPriceLabel->text();
    costOfRoom=costOfRoomString.toInt();
   finalEstimateCost=costOfRoom*days;
   finalEstimateCostString=QString::number(finalEstimateCost);
      ui->estimatecostLabel->setText(finalEstimateCostString);
     ui->estimatecostLabel->setText(finalEstimateCostString);
    ui->numberOfAdultsSpinBox->setMaximum(4);
    ui->numberOfChildrenSpinBox->setMaximum(3);

}
}

void ResortReservation::on_roomTypeSelection_currentIndexChanged(const QString &arg1)
{
    QString defaultText = "------------------------------------------";
    QString currentInformation=ui->reservationNameText->toPlainText();


    if(currentInformation!=""&&arg1!=defaultText){
        ui->nextButton->show();
    }
    else
          ui->nextButton->hide();

}



void ResortReservation::on_creditCardType_currentIndexChanged(const QString &arg1)
{
    if(arg1=="American Express"){
ui->creditCardNumber->setInputMask("9999-999999-99999;_");
    }
    else if(arg1=="Visa"||arg1=="Mastercard"||arg1=="Discover"){
ui->creditCardNumber->setInputMask("9999-9999-9999-9999;_");
    }


}

void ResortReservation::on_goBackButton_clicked()
{
    ui->roomReservation->setCurrentIndex(0);
    ui->creditCardNumber->clear();
    ui->expDateLineEdit->clear();

}

void ResortReservation::on_confirmationButton_clicked()
{
    QMessageBox comfirm;
    QString reservationName= ui->reservationNameText->toPlainText();
    QString checkInDate=ui->startDateCalander->text();
    QString checkOutDate=ui->endDateCalander->text();
    QString roomType=ui->roomTypeSelection->currentText();
    QString numberOfAdults=ui->numberOfAdultsSpinBox->text();
    QString numberOfChildren=ui->numberOfChildrenSpinBox->text();
    QString finalCostAmount=ui->totalCostLabel->text();
    QString creditCardNumber=ui->creditCardNumber->text();
    int lengthOfcreditCard=creditCardNumber.length();
    int firstPositionOfFourdigits=lengthOfcreditCard-3;
    QString finalFourDigits=creditCardNumber.mid(firstPositionOfFourdigits,lengthOfcreditCard);

    bool parkingChecked=ui->vechicleParkingCheckBox->checkState();
    comfirm.setText("Are you sure you want to continue?");
        comfirm.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        comfirm.setDefaultButton(QMessageBox::Yes);
        int comfirmationIndex=comfirm.exec();
        if(comfirmationIndex==QMessageBox::Yes){
    ui->roomReservation->setCurrentIndex(2);
ui->finalReservationName->setText(reservationName);
ui->finalCheckInDate->setText(checkInDate);
ui->finalCheckOutDate->setText(checkOutDate);
ui->finalRoomType->setText(roomType);
ui->finalNumberOfAdults->setText(numberOfAdults);
ui->finalNumberOfChildren->setText(numberOfChildren);
ui->finalCostAmount->setText(finalCostAmount);
ui->finalLastFourDigits->setText(finalFourDigits);
if(parkingChecked==0)
    ui->finalParking->setText("No");
else {
    ui->finalParking->setText("Yes");
}
        }
        else
            ui->roomReservation->setCurrentIndex(3);

}


void ResortReservation::on_exitButton_clicked()
{
    QApplication::quit();

}




void ResortReservation::on_endDateCalander_dateChanged(const QDate &date)
{
    QDate beginDate= ui->startDateCalander->date();
    int days= date.day()-beginDate.day();
    int costOfRoom=0;
    int finalEstimateCost=0;
    QString finalEstimateCostString;
   QString costOfRoomString=ui->actualPriceLabel->text();
    costOfRoom=costOfRoomString.toInt();
   finalEstimateCost=costOfRoom*days;
   finalEstimateCostString=QString::number(finalEstimateCost);
     ui->estimatecostLabel->setText(finalEstimateCostString);
}







void ResortReservation::on_reservationNameText_copyAvailable(bool b)
{
    QString currentInformation=ui->reservationNameText->toPlainText();
    QString currentSelectedRoom=ui->roomTypeSelection->currentText();
    QString defaultText = "------------------------------------------";
    if((currentInformation!="")&&(currentSelectedRoom!=defaultText)){
        ui->nextButton->show();
    }
}
