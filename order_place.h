#ifndef ORDER_PLACE_H
#define ORDER_PLACE_H

#include <QWidget>
#include "menu.h"
#include "q_restorator_main_window.h"
#include "order.h"
#include <QHBoxLayout>
class Q_Restorator_main_window;
class Order_place : public QWidget
{
    Q_OBJECT


QListWidget* list_widget_avaible_dishes;
QListWidget* list_widget_order;
QPushButton* push_button_add;
QHBoxLayout* h_layout;
std::shared_ptr<Menu> dishes_shared_ptr;
QVector <Order> orders;
Order temp_order;
public:

bool refresh_pointer(Q_Restorator_main_window *prntwdgt);
    Order_place(Q_Restorator_main_window* prntwdgt);
    explicit Order_place(QWidget *parent = nullptr);
    void add_dish_in_order();

signals:

public slots:
    void slot_refresh_pointers(Q_Restorator_main_window *prntwdgt){
        refresh_pointer(prntwdgt);
    }
    void slot_add_dish_in_order(){
        add_dish_in_order();
    }
};

#endif // ORDER_PLACE_H
