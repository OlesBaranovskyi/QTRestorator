#include "mydialogadd.h"

#include <QValidator>
#include<QDebug>

MyDialogAdd::MyDialogAdd()
{
    QStringList listitems;
    listitems<<"Фрукт"<<"Овощь"<<"Напиток"<<"Мясо"<<"Рыба"<<"Специи"<<"Молочные прдукты"<<"Крупа"<<"Колбасные изделия"<<"Кондитерские изделия";
    choise_type=new QListWidget(this);
    choise_type->addItems(listitems);
    name_product=new QLineEdit;
   price_product= new QLineEdit;
   amount_product= new QLineEdit;

pbAdd=new QPushButton("&Добавить",this);
//pbcancel=new QPushButton("&cancel",this);
pbok=new QPushButton("&Ok",this);
   ////////////
  QLabel* nametxt=new QLabel("&Название");
  QLabel* pricetxt=new QLabel("&Цена");
  QLabel* amounttxt=new QLabel("&Количество");
amounttxt->setBuddy(amount_product);
  nametxt->setBuddy(name_product);
 pricetxt->setBuddy(price_product);

/////////////////////LAyouts
   name_lay=new QHBoxLayout;
   price_lay=new QHBoxLayout;
   all_lay=new QVBoxLayout;
amount_lay=new QHBoxLayout;
   buttons_lay=new QHBoxLayout;
   listwidget=new QHBoxLayout;

listwidget->addWidget(choise_type);

//buttons_lay->addWidget(pbcancel);
buttons_lay->addWidget(pbAdd);
buttons_lay->addWidget(pbok);
name_lay->addWidget(nametxt);
   name_lay->addWidget(name_product);
   price_lay->addWidget(pricetxt);
   price_lay->addWidget(price_product);
   amount_lay->addWidget(amounttxt);
   amount_lay->addWidget(amount_product);
   all_lay->addLayout(name_lay);
   all_lay->addLayout(price_lay);
   all_lay->addLayout(amount_lay);
  all_lay->addLayout(listwidget);
  all_lay->addLayout(buttons_lay);
   this->setLayout(all_lay);
//name_product->
/////////////////////////////////////

connect(pbAdd,SIGNAL(pressed()),this,SLOT(set_all_fields()));
connect (pbok,SIGNAL(pressed()),this,SLOT(hide_add_dalog()));
    QDoubleValidator* valid_price=new QDoubleValidator;
    price_product->setValidator(valid_price);

    QDoubleValidator* valid_amount=new QDoubleValidator;


    amount_product->setValidator(valid_amount);




    QRegExp rx_name("[а-я|\s|\. А-Я]*");
     QValidator *validator_name = new QRegExpValidator(rx_name);
name_product->setValidator(validator_name);


}
QString MyDialogAdd::get_name_product()const
{
    return name_product->text();
}

QString MyDialogAdd::get_type_product()const
{
    return choise_type->currentItem()->text();
}

double MyDialogAdd::get_price_product()const
{QLocale locale;

    locale.setDefault(QLocale::German); // Decimal point is Comma: 000.000,00
    locale.setNumberOptions(QLocale::OmitGroupSeparator);


    bool ok;
    double d;
    d = locale.toDouble(price_product->text(), &ok );
    if(ok) {
    return d;
    }
    return 0.0;
}

double MyDialogAdd::get_amont_product() const
{
    QLocale locale;

        locale.setDefault(QLocale::German); // Decimal point is Comma: 000.000,00
        locale.setNumberOptions(QLocale::OmitGroupSeparator);


        bool ok;
        double d;
        d = locale.toDouble(amount_product->text(), &ok );
        if(ok) {
        return d;
        }
        return 0.0;



}
void MyDialogAdd::setProduct()
{
    temp_product.set_name_product(this->get_name_product());
    temp_product.set_type_product(this->get_type_product());
    temp_product.set_price_product(this->get_price_product());

}
void MyDialogAdd::set_all_fields()
{
    setProduct();
//qDebug()<<temp_product.get_prdct_name()<<" "<<temp_product.get_type_product()<<"  "<<temp_product.get_prdct_price();

}
void MyDialogAdd::hide_add_dalog(){
      this->hide();
}
