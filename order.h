#ifndef ORDER_H
#define ORDER_H
#include <QVector>
#include <QObject>
#include"menu.h"
#include<QDateTime>
class Order : public QObject,public QMap<QDish,int>
{
    Q_OBJECT

   QDateTime time;
   double total_amount;



public:
    void add_dish(QDish _dish);
    explicit Order(QObject *parent = nullptr);


   void set_time();
   void set_total();

   double get_total(){return total_amount;}
   QDateTime get_time(){return time;}



signals:

public slots:
};

#endif ORDER_H
