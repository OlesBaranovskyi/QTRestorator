#ifndef MYDIALOGADD_H
#define MYDIALOGADD_H
#include <widget.h>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QInputDialog>
#include <QLabel>
#include<QListView>
#include "widget.h"
#include<QPushButton>
#include<QDoubleSpinBox>
class MyDialogAdd : public QDialog
{Q_OBJECT
public:
    QPushButton* pbAdd;
   // QPushButton* pbcancel;
    QPushButton*  pbok;
    QListWidget* choise_type;
    QLineEdit* name_product;
    QLineEdit* price_product;
    QLineEdit* amount_product;
///////////////////
  //layouts
    QHBoxLayout* name_lay;
    QHBoxLayout* price_lay;
    QHBoxLayout* listwidget;
    QHBoxLayout* buttons_lay;
    QHBoxLayout* amount_lay;
    QVBoxLayout* all_lay;
public:
    MyDialogAdd();
    Product temp_product;
    QString get_name_product()const;
    QString get_type_product()const;
    double get_price_product()const;
    double get_amont_product()const;
    void setProduct();

public slots:
   void set_all_fields();
void hide_add_dalog();
};

#endif // MYDIALOGADD_H
