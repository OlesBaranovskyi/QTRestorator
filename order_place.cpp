#include "order_place.h"
#include "menu.h"
bool Order_place::refresh_pointer(Q_Restorator_main_window *prntwdgt)
{

    this->dishes_shared_ptr =  prntwdgt->get_widget_Qkitchen()->get_menu();
   if(!dishes_shared_ptr){
   return false;
   }

    list_widget_avaible_dishes->clear();
    QStringList list_dishes_names;
 for (int i=0;i<dishes_shared_ptr->size();++i){
       list_dishes_names<<dishes_shared_ptr->at(i).get_name();
    }

    list_widget_avaible_dishes->addItems(list_dishes_names);
return true;
}

Order_place::Order_place(Q_Restorator_main_window *prntwdgt)
{
    list_widget_avaible_dishes = new QListWidget(this);
if(!refresh_pointer(prntwdgt));
push_button_add = new QPushButton("ADD",this);
list_widget_order = new QListWidget(this);
h_layout = new QHBoxLayout;
h_layout->addWidget(list_widget_avaible_dishes);
h_layout->addWidget(push_button_add);
h_layout->addWidget(list_widget_order);
setLayout(h_layout);

connect(push_button_add,SIGNAL(pressed()),this,SLOT(slot_add_dish_in_order()));


}

Order_place::Order_place(QWidget *parent) : QWidget(parent)
{

}

void Order_place::add_dish_in_order()
{list_widget_order->clear();
    temp_order.add_dish(dishes_shared_ptr->operator [](list_widget_avaible_dishes->currentRow()));
    for(auto it =temp_order.begin();it!=temp_order.end();++it){

QString str(it.key().get_name()+"  "+QString::number(it.key().get_price())+"   x"+QString::number(it.value())+"  =  "+QString::number(it.key().get_price()*it.value()));
qDebug()<<str;
   list_widget_order->addItem(str);
    }

}
