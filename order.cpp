#include "order.h"

void Order::add_dish(QDish _dish)
{
   this->operator [](_dish)+=1;
}

Order::Order(QObject *parent) : QObject(parent)
{
//this->time = QDateTime::currentDateTime();
//    this->total_amount = 0;

}

void Order::set_time()
{
        this->time = QDateTime::currentDateTime();


}

void Order::set_total()
{

double tmp_total=0;
        for (auto it = this->begin();it!=this->end();++it){

            tmp_total += it.key().get_price()*it.value();
     //  qDebug()<<tmp_total;
        }

this->total_amount=tmp_total;
}
