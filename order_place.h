#ifndef ORDER_PLACE_H
#define ORDER_PLACE_H

#include <QWidget>
#include "menu.h"
#include "q_restorator_main_window.h"
class Q_Restorator_main_window;
class Order_place : public QWidget
{
    Q_OBJECT


QListWidget* list_widget_avaible_dishes;
std::shared_ptr<Menu> dishes_shared_ptr;
public:

void refresh_pointer(Q_Restorator_main_window *prntwdgt);
    Order_place(Q_Restorator_main_window* prntwdgt);
    explicit Order_place(QWidget *parent = nullptr);

signals:

public slots:
    void slot_refresh_pointers(Q_Restorator_main_window *prntwdgt){
        refresh_pointer(prntwdgt);
    }
};

#endif // ORDER_PLACE_H
