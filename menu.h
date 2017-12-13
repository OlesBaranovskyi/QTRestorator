#ifndef MENU_H
#define MENU_H
#include <QVector>
#include "QDish.h"

class Menu : public QVector<QDish>
{
    double price;

public:


   void  set_price(){
   for(auto i = this->begin();i!=this->end();++i){
       price+=i->get_price();
    }
   }
double get_price(){
return this->price;
}
    QStringList to_string_list(){
        QStringList lst;
        for(int i=0;i<this->size();++i){
            lst<<this->at(i).get_name();
        }
    return lst;
    }

    Menu();
};

#endif // MENU_H
