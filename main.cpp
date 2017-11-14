#include "widget.h"
#include <QApplication>
#include "product.h"
#include<QInputDialog>
#include <QRegExp>
#include<QValidator>
#include <QDoubleSpinBox>
#include <QPair>
#include<q_restorator_main_window.h>
#include<qkitchen.h>
#include <QDebug>
#include "QDish.h"
#include <QLCDNumber>
#include<QCamera>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



    Q_Restorator_main_window mainwind;
    mainwind.show();






    return a.exec();
}
