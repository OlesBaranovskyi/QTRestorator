#ifndef Q_RESTORATOR_MAIN_WINDOW_H
#define Q_RESTORATOR_MAIN_WINDOW_H
#include <memory>
#include <QMainWindow>
#include <widget.h>
#include <qkitchen.h>
#include "order_place.h"

class QKitchen;
class Order_place;
class Q_Restorator_main_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Q_Restorator_main_window(QWidget *parent = 0);

    QTabWidget* tab_widget;
    Widget* widget_storage;
    QKitchen* widget_qkitchen;
    Order_place* orders;




Widget* get_widget_storage(){
    return widget_storage;
}
QKitchen* get_widget_Qkitchen(){
    return widget_qkitchen;
}
void refresh_pointer_qkithen();
void refresh_pointer_order_place();
signals:

public slots:
void slot_refresh_pointer(){
    refresh_pointer_qkithen();

}
void slot_refresh_pointer_order_place(){
    refresh_pointer_order_place();
}

};

#endif // Q_RESTORATOR_MAIN_WINDOW_H
