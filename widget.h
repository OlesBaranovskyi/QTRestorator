#ifndef WIDGET_H
#define WIDGET_H
#include <QPair>
#include <QWidget>
#include "product.h"
#include <QListView>
#include <QListWidget>
#include<QFile>
#include<QHBoxLayout>
#include <QSizePolicy>
#include "mydialogadd.h"
#include<QPushButton>
#include<algorithm>
#include<QMessageBox>
#include<qiodevice.h>
#include<QDebug>
#include<memory>
#include<QString>
#include"QDish.h"
#include "Storage.h"
#include<QLCDNumber>
class MyDialogAdd;
//class Storage:public QDish{};
namespace Ui {
class Widget;
}

struct sort_name
{
    bool operator()(const QPair<Product,double> &x,const QPair<Product,double>& y)const
    {
        if(x.first.get_prdct_name()[0].toUpper()<y.first.get_prdct_name()[0].toUpper())return true;
        return false;
    }
};


struct sort_price{
    bool operator()(const QPair<Product,double> &x,const QPair<Product,double>& y)const{
        if(x.first.get_prdct_price()<y.first.get_prdct_price())return true;
        return false;
    }
};
struct sort_amount{
    bool operator()(const QPair<Product,double> &x,const QPair<Product,double>& y)const{
        if(x.second<y.second)return true;
        return false;
    }
};

class Widget : public QWidget
{
    Q_OBJECT

 Storage* storage;

QListWidget* list_product;
public:

QPushButton* sort_by_name_button;
QPushButton* sort_by_price_button;
QPushButton* sort_by_amount_button;
QPushButton* create_new_product_button;
QPushButton* del_product_button;
QPushButton* save_in_file_button;
QPushButton* load_from_file_button;
QPushButton* add_amount_product_button;



MyDialogAdd* dialog_add;

QHBoxLayout* labels_lay;
QHBoxLayout* top_h_lay;
QVBoxLayout* buttons_lay;
QVBoxLayout* labels_and_viewlist_lay;
QLabel* labelheders;


public slots:
void slot_add_new_product();
void slot_delete_product();
void slot_sort_by_name();
void slot_sort_by_price();
void slot_sort_by_amount();
void slot_save_in_file();
void slot_load_from_file();
void slot_add_amount_product();
public:
explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

public:

    void create_view_list();
    void delete_product(int);
    void load_from_file();
    void save_in_file();
    void add_amount_product();
  Storage* get_storage(){
      return storage;
  }

};

#endif // WIDGET_H
