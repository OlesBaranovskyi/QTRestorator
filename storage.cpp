#include "storage.h"

//override Storage::QDish::save_in_file()
//{
//    QFile file_products("storage.txt");
//    file_products.open(QIODevice::Truncate|QIODevice::WriteOnly);
//    QTextStream ostreamProduct(&file_products);
//    if(!file_products.isOpen())
//    {
//        QMessageBox::information(0,"Eror","Ошибка открытия файла для сохранения");
//        return false;
//    }


//       for(auto i=ind->begin();i!=ind->end();++i)
//      {

//        ostreamProduct<<i->first<<" "<<i->second<<'\n';

//      }

//       QMessageBox::information(0,"OK!","Сохранение прошло успешно");
//       return true;
//}

//override Storage::QDish::load_from_file()
//{

//    QFile file_products("storage.txt");
//    file_products.open(QIODevice::ReadOnly);
//    if(!file_products.isOpen()){
//         QMessageBox::information(0,"Eror","Ошибка открытия файла для загрузки");
//         return false;
//    }
//ind->clear();
//   QTextStream istream_product(&file_products);
//while(!istream_product.atEnd()){
//   QString name=istream_product.readLine(40);
//QString type=istream_product.readLine(40);
//   double prc=istream_product.readLine(6).toDouble();
//   double amnt= istream_product.readLine(6).toDouble();


//   Product tmp(name,type,prc);
//   this->add_ingridient(tmp,amnt);
//  }
//   return true;
//   //qDebug()<<tmp;


//}

//Storage::Storage()
//{

//}
