#include "order_place.h"
#include "menu.h"
void Order_place::refresh_pointer(Q_Restorator_main_window *prntwdgt)
{

    this->dishes_shared_ptr =  prntwdgt->get_widget_Qkitchen()->get_menu();
    list_widget_avaible_dishes = new QListWidget(this);
    list_widget_avaible_dishes->clear();
    QStringList list_dishes_names;
 for (int i=0;i<dishes_shared_ptr->size();++i){
       list_dishes_names<<dishes_shared_ptr->at(i).get_name();
    }

    list_widget_avaible_dishes->addItems(list_dishes_names);

}

Order_place::Order_place(Q_Restorator_main_window *prntwdgt)
{
refresh_pointer(prntwdgt);

}

Order_place::Order_place(QWidget *parent) : QWidget(parent)
{

}
