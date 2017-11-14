#ifndef STORAGE_H
#define STORAGE_H
#include"QDish.h"

class Storage:public QDish
{ //using QDish::QDish;
public:

   bool save_in_file() override{


       QFile file_products("storage.txt");
       file_products.open(QIODevice::Truncate|QIODevice::WriteOnly);
       QTextStream ostreamProduct(&file_products);
       if(!file_products.isOpen())
       {
           QMessageBox::information(0,"Eror","Ошибка открытия файла для сохранения");
           return false;
       }


          for(auto i=ind.begin();i!=ind.end();++i)
         {

           ostreamProduct<<i->first<<" "<<i->second<<'\n';

         }
   //file_products.close();
//          QMessageBox::information(0,"OK!","Сохранение прошло успешно");
          return true;


   }
   bool load_from_file(QString name=" ") override{


       QFile file_products("storage.txt");
       file_products.open(QIODevice::ReadOnly);
       if(!file_products.isOpen()){
            QMessageBox::information(0,"Eror","Ошибка открытия файла для загрузки");
            return false;
       }
   ind.clear();
      QTextStream istream_product(&file_products);
   while(!istream_product.atEnd()){
      QString name=istream_product.readLine(40);
   QString type=istream_product.readLine(40);
      double prc=istream_product.readLine(6).toDouble();
      double amnt= istream_product.readLine(6).toDouble();


      Product tmp(name,type,prc);
      this->add_ingridient(tmp,amnt);
     }
      return true;

   }
  // Storage(): QDish(){}
   //Storage(QString i):QDish(i){}
};

#endif // STORAGE_H
