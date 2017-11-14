#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>
#include<fstream>
#include<iostream>
#include<QDatastream>
#include <QTextStream>
#include<iomanip>
class Product
{private:

   QString type_product;
     QString name;
    double price;
public:
    Product();
Product(const Product& );
    Product(QString ,QString ,double );
    QString get_type_product()const{return this->type_product;}
    QString get_prdct_name()const{return name;}
    double get_prdct_price()const{return price;}
    //Product getPrdct() const(){return *this;}'
void set_type_product(QString);
void set_price_product(double);
void set_name_product(QString);

friend QTextStream& operator <<(QTextStream& os,const Product& _product)
    {
QString tmp_name=_product.get_prdct_name()+'\n';

QString tmp_type=_product.get_type_product()+'\n';

QString price=QString::number(_product.get_prdct_price(),'g',3)+'\n';

os<<tmp_name<<tmp_type<<price;
     return os;
     }

};


#endif // PRODUCT_H
