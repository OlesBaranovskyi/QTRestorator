#include "qdish.h"




typeDish QDish::get_type()
{
    return this->type;
}

void QDish::set_weght()
{
    double tmpwht=0;

for(auto it=ind.begin();it!=ind.end();it++)
    {

    tmpwht+=it->second;
    }

    this->weight=tmpwht;
}

void QDish::set_price()
{
double tmpprc=0;

    for(auto it=ind.begin();it!=ind.end();it++){
       tmpprc+=it->first.get_prdct_price()/1000*it->second;
     }

price=tmpprc;
}

void QDish::set_name(QString _name)
{
 name.clear();
 name=_name;
}

bool QDish::set_type(int _type)
{
    if(_type<int(typeDish::first) || int(typeDish::other)<_type ){
        return false;
    }
    type=typeDish(_type);
    return true;
}

void QDish::reset_dish()
{
    this->name="";
    this->ind.clear();
    this->set_price();
    this->set_weght();
}

QDish QDish::operator =( QDish  _dish)
{

    this->set_name(_dish.get_name());
    for(auto i=0;i<_dish.size();++i){

        this->add_ingridient(_dish.get_pair_product_and_amount(i).first,_dish.get_pair_product_and_amount(i).second);

    }

    set_weght();
    set_price();
    type=_dish.type;
    return *this;
}

QStringList QDish::to_string_list()
{
    QString str;
    QTextStream txt_stream(&str);

    txt_stream.setFieldWidth(25);
    txt_stream.setPadChar(' ') ;
    txt_stream.setRealNumberPrecision(4);
   txt_stream.setFieldAlignment(QTextStream::AlignLeft);
   QStringList temp_list;

    for(auto  i=ind.begin();i!=ind.end();i++){

    txt_stream<<i->first.get_prdct_name()<<i->first.get_type_product()<<i->first.get_prdct_price()<<i->second;
    temp_list<<str;
    str.clear();
}


   return temp_list;




}

bool QDish::add_ingridient(Product _prd, double _amount)
{if (_amount>0)

    ind.push_back(qMakePair(_prd,_amount));
   this->set_price();
   this->set_weght();
        return true;
    return false;




}




bool QDish::delete_ingridient(int i)
{
    if(i<0 || i>ind.size())return false;
    ind.remove(i);
    return true;
}

bool QDish::operator -(QDish _Dish){
    bool fnd=false;
    auto tempind = this->ind;                               //Создал временный вектор ингридиентов для
    for (int i=0;i<this->size();++i){                        //обеспечеия строгой гарантии не изменности основного
        for(int j=0;j<_Dish.ind.size();++j){                   //вектора прине достаточном количестве продукта на складе
            if( tempind[i].first==_Dish.ind[j].first){
                if(tempind[i].second>=_Dish.ind[j].second){
                    tempind[i].second-=_Dish.ind[j].second;
                    fnd=true;
                }
                else {
                    qDebug()<<"Amount not enought"<<endl;
                    return false;}
              }

        }

    }
    this->ind=tempind;
    return fnd;
}
bool QDish::save_in_file()
{


        QFile file_products(this->get_name());
        file_products.open(QIODevice::Truncate|QIODevice::WriteOnly);
        QTextStream ostreamProduct(&file_products);
        if(!file_products.isOpen())
        {
            QMessageBox::information(0,"Eror","Ошибка открытия файла для сохранения");
            return false;
        }
qDebug()<<int(this->get_type());
        ostreamProduct<<int(this->get_type())<<'\n';


           for(auto i=ind.begin();i!=ind.end();++i)
          {

            ostreamProduct<<i->first<<" "<<i->second<<'\n';

          }

           QMessageBox::information(0,"OK!","Сохранение прошло успешно");
           return true;
}

bool QDish::load_from_file(QString name)
{


    QFile file_products(name);
    file_products.open(QIODevice::ReadOnly);
    if(!file_products.isOpen()){
         QMessageBox::information(0,"Eror","Ошибка открытия файла для загрузки");
         return false;
    }
ind.clear();

   QTextStream istream_product(&file_products);
int tmptype=istream_product.readLine(40).toInt();

qDebug()<<tmptype;
while(!istream_product.atEnd()){
   QString name=istream_product.readLine(40);
QString type=istream_product.readLine(40);
   double prc=istream_product.readLine(6).toDouble();
   double amnt= istream_product.readLine(6).toDouble();


   Product tmp(name,type,prc);
   this->add_ingridient(tmp,amnt);
  }
   this->set_type(tmptype);
this->set_name(name);
return true;
   //qDebug()<<tmp;


}

bool QDish::add_amount(int index, double _amount)
{if(_amount>0){
auto qpair_temp=get_pair_product_and_amount(index);
qpair_temp.second+=_amount;
ind.replace(index,qpair_temp);
return true;
    }
return false;
}

const QPair<Product, double> QDish::get_pair_product_and_amount(int index)
{

    return ind.at(index);
}



QDish::QDish()
{


}

QDish::QDish(QString _name):name(_name)
{
set_type(4);
}


