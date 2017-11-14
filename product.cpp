#include "product.h"
Product::Product()
{
    type_product="untyped";
    name="product";
    price=0.0;
}

Product::Product(const Product& _product)
{
    name=_product.get_prdct_name();
    price=_product.get_prdct_price();
    type_product=_product.get_type_product();
}

Product::Product(QString _name,QString _type,double _price)
{
    name=_name;
    price=_price;
    type_product=_type;
}

void Product::set_type_product(QString _type)
{
    type_product=_type;
}

void Product::set_price_product(double _price)
{
    price=_price;
}

void Product::set_name_product(QString _name)
{
    name=_name;
}
