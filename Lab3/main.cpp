#include "resortreservation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ResortReservation w;
    w.show();

    return a.exec();
}
