#ifndef QDISH_H
#define QDISH_H
#include <QVector>
#include"product.h"
#include<QPair>
#include<memory>
#include<QDebug>
#include <algorithm>
#include<QFile>
#include<QMessageBox>
#include<QList>
#include<QInputDialog>
#include <algorithm>
#include <iomanip>
struct sort_name_qdish
{
    bool operator()(const QPair<Product,double> &x,const QPair<Product,double>& y)const
    {
        if(x.first.get_prdct_name()[0].toUpper()<y.first.get_prdct_name()[0].toUpper())return true;
        return false;
    }
};

struct sort_price_qdish{
    bool operator()(const QPair<Product,double> &x,const QPair<Product,double>& y)const{
        if(x.first.get_prdct_price()<y.first.get_prdct_price())return true;
        return false;
    }
};
struct sort_amount_qdish{
    bool operator()(const QPair<Product,double> &x,const QPair<Product,double>& y)const{
        if(x.second<y.second)return true;
        return false;
    }
};
enum class typeDish{first=0,secind,dessert,drnik,other};



class QDish
{
protected:
    QString name;
    QVector <QPair<Product,double>> ind;
    double weight;
    double price;
    typeDish type;
public:
    QPair<Product,double>& operator[](int i){
if(i<0 || i>ind.size())
    {
    return ind.last();
    }
return ind.operator [](i);
}
  friend  QDebug operator<<(QDebug dbg, const QDish &_dish)
    {
        for(auto i=_dish.ind.begin();i!=_dish.ind.end();i++){
        dbg.nospace()<< i->first.get_prdct_name()<<"  "<<i->second;
   }


        return dbg.space();
    }


  friend std::ostream & operator << (std::ostream & os,const QDish _dish){
      for(auto i=_dish.ind.begin();i!=_dish.ind.end();i++){
      os<<std::setw(10)<<std::setfill(' ')<< i->first.get_prdct_name().toStdString()<<"  "<<i->second;
 }


      return os;
  }



/////////////////sort

  void sort_by_name()
  {
    std::sort(ind.begin(),ind.end(),sort_name_qdish());

   }
  void sort_by_price()
  {
    std::sort(ind.begin(),ind.end(),sort_price_qdish());
  }
  void sort_by_amount()
  {
    std::sort(ind.begin(),ind.end(),sort_amount_qdish());
  }
/////////////////
    double get_weight()const{return weight;}
    double get_price()const{return price;}
   typeDish get_type();
    void set_weght();
    void set_price();
    void set_name(QString);
    bool set_type(int);
    void reset_dish();
    QString get_name()const{return name;}
    //////////////////
    QDish operator =(QDish);
    bool operator == (QDish _dish)const{
        return this->get_name() == _dish.get_name();
    }

    bool operator <(const QDish _dish)const{
        return this->get_price()<_dish.get_price();
    }


    QStringList to_string_list();
    bool add_ingridient(Product,double);

    bool delete_ingridient(int);
    bool operator -(QDish _Dish);
   virtual bool save_in_file();
    virtual bool load_from_file(QString);
    void clear(){ind.clear();}
    bool add_amount(int,double);
    const QPair<Product,double> get_pair_product_and_amount(int);
     QVector <QPair<Product,double>> get_ptr_ingridients(){
    QVector <QPair<Product,double>> tmp_ptr=ind;
    return tmp_ptr;
}
int size(){return this->ind.size();}
public:
    QDish();
    QDish(QString);
   // QDish(const QDish& _dish);
};

#endif // QDISH_H
