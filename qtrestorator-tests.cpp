#include <QtTest/QTest>
#include "widget.h"
#include <QApplication>
#include "product.h"
#include<q_restorator_main_window.h>
#include<qkitchen.h>
#include <QDebug>
#include "QDish.h"
#include <iostream>
namespace test_rest {
void test_operator_for_QDish(){

    Product salt("Salt","",1.5);
    Product pepper ("pepper","",2.5);
    Product milk ("Milk","",1.5);
    Product popcorn("Popcorn","",2.5);
/*....................................................*/
    Storage strge("Storage");
    strge.add_ingridient(salt,2.3);
    strge.add_ingridient(pepper,5);
    strge.add_ingridient(milk,1);
/*.....................................................*/


   qDebug()<<strge;

/*.....................................................*/
   QDish dish("dish");
   dish.add_ingridient(salt,2);
   dish.add_ingridient(pepper,1.5);
   dish.add_ingridient(milk,0.5);
   dish.add_ingridient(popcorn,2);
 /*....................................................*/
 strge - dish;


   qDebug()<<strge;
   qDebug()<<"..............................................";
}





}

