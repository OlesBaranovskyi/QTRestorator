#ifndef QKITCHEN_H
#define QKITCHEN_H
#include<widget.h>
#include <QWidget>
#include <memory>
#include <q_restorator_main_window.h>
#include <QLineEdit>
#include <QComboBox>
#include <memory>
#include "menu.h"
#include <QVector>
class Q_Restorator_main_window;
class QKitchen : public QWidget
{
    Q_OBJECT

private:
    //Menu* dishes = new Menu;

    std::shared_ptr<Menu> dishes;
    QVector<QString> dishes_title;
    QDish temp_dish;
public:
     QKitchen(QWidget *parent=0);
     QKitchen(Q_Restorator_main_window*);
     QKitchen();
/////////////////buttons

     QPushButton* button_create_new_dish;
     QPushButton* button_delete_dish;
     QPushButton* button_add_product_in_dish;
     QPushButton* button_delete_product_from_dish;
     QPushButton* button_save_all;
     /////////////////

    QHBoxLayout* avaible_product_lay;
    QVBoxLayout* lay_button_add_del;
    QHBoxLayout* lay_price_weight;
    QVBoxLayout* lay_nwdish_labels;
    QVBoxLayout* lay_main_buttons;
    QVBoxLayout* lay_all_layots;
    QHBoxLayout* lay_name_dish;
    ///////////////////////


     QLineEdit* line_edit_name_dish;

     QLabel* label_avaible_product;
     QLabel* label_avaible_dishes;
     QLabel* label_price_dish;
     QLabel* label_name_dish;
     QLCDNumber* lcd_numb_weight_dish;
     QLCDNumber* line_edit_price_dish;
     QComboBox* combobox_types;
     ///////////////////////////////widgets
     Storage* avaible_product;
     QListWidget* list_widget_avaible_product;
     QListWidget* list_widget_new_dish;
     QListWidget* list_widget_avaible_dishes;


    void create_list_widget_avaible_product();
    void create_list_avaible_dishes();
    void refresh_pointer(Q_Restorator_main_window*);
    void save_dishes_titles();
    void load_dishes_titles();
    bool add_new_dish();
    bool save_chages();
    bool add_product_in_new_dish();
    bool delete_product_from_dish();
    void reset_list_and_labels();
    void load_dishes();
    void delete_dish();
    void edit_dish();
     std::shared_ptr<Menu> get_menu(){
//qDebug()<<this->dishes.size();

        return dishes;
    }
signals:

public slots:
void slot_add_product_in_new_dish();
void slot_add_new_dish();
void slot_delete_product_from_dish();
void slot_save_changes();
void slot_delete_dish();
void slot_edit_dish();
};

#endif // QKITCHEN_H
