#include "widget.h"
#include <QApplication>
#include "product.h"
#include<q_restorator_main_window.h>
#include<qkitchen.h>
#include <QDebug>
#include "QDish.h"
#include "qtrestorator-tests.cpp"
#include "menu.h"
#include "order_place.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

//test_rest::test_operator_for_QDish();
//test_rest::test_Menu_QDishes();
   //test_rest::test_Order_Place();
    Q_Restorator_main_window mainwind;
    mainwind.show();






    return a.exec();
}
