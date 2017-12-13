#include <QtTest/QTest>
#include "widget.h"
#include <QApplication>
#include "product.h"
#include<q_restorator_main_window.h>
#include<qkitchen.h>
#include <QDebug>
#include "QDish.h"
#include <iostream>
#include "menu.h"
#include <order_place.h>
#include "order.h"
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
std::shared_ptr<Menu> ret_shared(){


    std::shared_ptr<Menu> mn(new Menu);

    Product salt("Salt","",1.5);
    Product pepper ("pepper","",2.5);
    Product milk ("Milk","",1.5);
    Product popcorn("Popcorn","",2.5);
 /*.....................................................*/
    QDish dish("dish");
    dish.add_ingridient(salt,2);
    dish.add_ingridient(pepper,1.5);
    dish.add_ingridient(milk,0.5);
    dish.add_ingridient(popcorn,2);
    mn->push_back(dish);



    return mn;
}
void test_Menu_QDishes(){



    Product salt("Salt","",1.5);
    Product pepper ("pepper","",2.5);
    Product milk ("Milk","",1.5);
    Product popcorn("Popcorn","",2.5);
 /*.....................................................*/
    QDish dish("dish");
    dish.add_ingridient(salt,2);
    dish.add_ingridient(pepper,1.5);
    dish.add_ingridient(milk,0.5);
    dish.add_ingridient(popcorn,2);


    QDish dish2("popcorn");

    dish.add_ingridient(popcorn,2);
    /*.......................................................*/

std::shared_ptr<Menu> menu(new Menu);
    //Menu* menu = new Menu;
  std::shared_ptr<Menu> menptr= ret_shared();
 // std::make_shared<menu>;
   // menptr->push_back(dish);
    qDebug()<<"Pointr conteins "<<menptr->size();

    qDebug()<<menptr->operator [](0);
    qDebug()<<menptr->contains(dish);
  qDebug()<<menptr->contains(dish2);
}

void test_Order_Place(){

    Order_place* ord=NULL;
    ord = new Order_place;

    ord->show();
//qDebug()<<ord->menuptr->size();
}
void test_order(){
    Product salt("Salt","",1.5);
    Product pepper ("pepper","",2.5);
    Product milk ("Milk","",1.5);
    Product popcorn("Popcorn","",2.5);
 /*.....................................................*/
    QDish dish("dish");
    dish.add_ingridient(salt,200);
    dish.add_ingridient(pepper,150);
    dish.add_ingridient(milk,500);
    dish.add_ingridient(popcorn,200);

//   //dish.set_price();
//     dish.set_weght();
    QDish dish2("popcorn");

    dish2.add_ingridient(popcorn,2);

//    //QPair<QDish,int> dish_pair_1 (dish,2);
//    //auto dish_pair2 (std::make_pair(dish,3));

//    /*.......................................................*/

//    std::shared_ptr<Order> ord (new Order);

//    ord->push_back(dish_pair_1);
//   // ord.push_back(dish_pair2);
//    ord->set_total();
//    ord->set_time();
Order ord;
ord[dish]+=1;
ord[dish2]+=1;
ord[dish2]+=1;

ord.set_time();
ord.set_total();
for(auto it = ord.begin();it!=ord.end();++it){

    qDebug()<<it.key();
    qDebug()<<it.value();
   // qDebug()<<ord.get_time();
   // qDebug()<<ord.get_total();
     qDebug()<<ord.get_total();

    qDebug()<<"----------------------";
}




}
}

