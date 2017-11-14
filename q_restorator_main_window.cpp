#include "q_restorator_main_window.h"

Q_Restorator_main_window::Q_Restorator_main_window(QWidget *parent) : QMainWindow(parent)
{



tab_widget=new QTabWidget(this);
widget_storage=new Widget(this);
widget_qkitchen=new QKitchen(this);
widget_qkitchen->refresh_pointer(this);
tab_widget->addTab(widget_qkitchen,"Кухня");
tab_widget->addTab(widget_storage,"Склад");
tab_widget->resize(this->width(),this->height());

connect(tab_widget,SIGNAL(currentChanged(int)),this,SLOT(slot_refresh_pointer()));

this->resize(800,600);
}

void Q_Restorator_main_window::refresh_pointer_qkithen()
{
    //if(!tab_widget->isHidden())
widget_qkitchen->refresh_pointer(this);
        widget_qkitchen->create_list_widget_avaible_product();


}
