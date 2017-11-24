#include "qkitchen.h"
#include"menu.h"


QKitchen::QKitchen(Q_Restorator_main_window *parentwidg)
{
    std::shared_ptr<Menu> tmp(new Menu);
    dishes= tmp;
    avaible_product_lay=new QHBoxLayout;
    lay_button_add_del=new QVBoxLayout;
    lay_name_dish=new QHBoxLayout;
    lay_all_layots=new QVBoxLayout;
    list_widget_avaible_product=new QListWidget(this);
    list_widget_avaible_dishes=new QListWidget(this);
    button_add_product_in_dish=new QPushButton("->");
    button_delete_product_from_dish= new QPushButton("<-");
    button_create_new_dish = new QPushButton("&Создать блюдо");
    button_save_all= new QPushButton("&Сохранить изменения");
    button_delete_dish= new QPushButton("&Удалить блюдо");


    list_widget_new_dish=new QListWidget(this);
    lay_price_weight= new QHBoxLayout;
    lay_nwdish_labels= new QVBoxLayout;
    line_edit_price_dish=new QLCDNumber;
    line_edit_price_dish->display(temp_dish.get_price());
    combobox_types=new QComboBox;
    QStringList lsttypes{"Первое","Второе","Десерт","Напиток","Дргое"};
    combobox_types->addItems(lsttypes);
    line_edit_name_dish=new QLineEdit;
    line_edit_name_dish->setFixedWidth(100);
    lcd_numb_weight_dish=new QLCDNumber;
    lcd_numb_weight_dish->setSegmentStyle(QLCDNumber::Flat);
    line_edit_price_dish->setSegmentStyle(QLCDNumber::Flat);
    lcd_numb_weight_dish->display(temp_dish.get_weight());
    lay_main_buttons=new QVBoxLayout;

    lay_name_dish->addWidget(line_edit_name_dish);
    lay_name_dish->addWidget(new QLabel("Название блюда"));



    ////////////////////////////////////////
    refresh_pointer(parentwidg);
    lay_price_weight->addWidget(line_edit_price_dish);
    lay_price_weight->addWidget(new QLabel("Цена"));
    lay_price_weight->addWidget(lcd_numb_weight_dish);
    lay_price_weight->addWidget(new QLabel("Вес"));
    lay_nwdish_labels->addLayout(lay_name_dish);
    lay_nwdish_labels->addWidget(list_widget_new_dish);
    lay_nwdish_labels->addWidget(combobox_types);
    lay_nwdish_labels->addLayout(lay_price_weight);
    lay_button_add_del->addWidget(button_add_product_in_dish);
    lay_button_add_del->addWidget(button_delete_product_from_dish);
    lay_main_buttons->addWidget(button_create_new_dish);
    lay_main_buttons->addWidget(button_save_all);
    lay_main_buttons->addWidget(button_delete_dish);

    avaible_product_lay->addWidget(list_widget_avaible_product);
    avaible_product_lay->addLayout(lay_button_add_del);

    avaible_product_lay->addLayout(lay_nwdish_labels);
    avaible_product_lay->addLayout(lay_main_buttons);

    lay_all_layots->addLayout(avaible_product_lay);
    lay_all_layots->addWidget(list_widget_avaible_dishes);

    setLayout(lay_all_layots);


connect(button_add_product_in_dish,SIGNAL(pressed()),this,SLOT(slot_add_product_in_new_dish()));
connect(button_create_new_dish,SIGNAL(pressed()),this,SLOT(slot_add_new_dish()));
connect(button_delete_product_from_dish,SIGNAL(pressed()),this,SLOT(slot_delete_product_from_dish()));
connect(button_save_all,SIGNAL(pressed()),this,SLOT(slot_save_changes()));
connect(button_delete_dish,SIGNAL(pressed()),this,SLOT(slot_delete_dish()));
connect(list_widget_avaible_dishes,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(slot_edit_dish()));
//connect(button_edit_dish,SIGNAL(pressed()),this,SLOT(slot_edit_dish()));
load_dishes_titles();
load_dishes();
create_list_avaible_dishes();
}

void QKitchen::create_list_widget_avaible_product()
{

    QString str;
    QTextStream txt_stream(&str);

    txt_stream.setFieldWidth(25);
    txt_stream.setPadChar(' ') ;
    txt_stream.setRealNumberPrecision(4);
    txt_stream.setFieldAlignment(QTextStream::AlignLeft);


    for(int i=0;i<avaible_product->size();i++){
        txt_stream<<avaible_product->get_pair_product_and_amount(i).first.get_prdct_name();

       list_widget_avaible_product->addItem(str);
        str.clear();
    }


}

void QKitchen::create_list_avaible_dishes()
{
    list_widget_avaible_dishes->clear();
    list_widget_avaible_dishes->addItems(dishes_title.toList());
}

void QKitchen::refresh_pointer(Q_Restorator_main_window* parentwidg)
{
    list_widget_avaible_product->clear();
    avaible_product=parentwidg->get_widget_storage()->get_storage();

}

void QKitchen::save_dishes_titles()
{
    QFile file_dishes("dishes.txt");
    file_dishes.open(QIODevice::Truncate|QIODevice::WriteOnly);
    QTextStream ostream_dishes(&file_dishes);
    if(!file_dishes.isOpen())
    {
        QMessageBox::information(0,"Eror","Ошибка открытия файла для сохранения");

    }

    for(auto it=dishes->begin();it!=dishes->end();++it){

        ostream_dishes<<it->get_name()<<'\n';
    }

}

void QKitchen::load_dishes_titles()
{

    QFile file_dishes("dishes.txt");
    file_dishes.open(QIODevice::ReadOnly);
    if(!file_dishes.isOpen()){
       QMessageBox::information(0,"Eror","Ошибка открытия файла для загрузки");
    }

    QString name;
    QTextStream istream_dishes(&file_dishes);

    while(!istream_dishes.atEnd()){

        name=istream_dishes.readLine();
        this->dishes_title.push_back(name);
        name.clear();
    }
}

bool QKitchen::add_new_dish()
{
    if(!temp_dish.size()  )
     {
        QMessageBox::information(0,"Eror","Блюдо пустое");
        return false;
    }

    if(!line_edit_name_dish->text().size()){
        QMessageBox::information(0,"Eror","Не задано название блюда");
        return false;
    }
    temp_dish.set_name(line_edit_name_dish->text());
    temp_dish.set_type(combobox_types->currentIndex());

    this->dishes->push_back(temp_dish);

    this->dishes_title.push_back(temp_dish.get_name());
    QMessageBox::information(0,"OK)","Блюдо добавлено");
    list_widget_avaible_dishes->clear();
    create_list_avaible_dishes();
    reset_list_and_labels();
    temp_dish.reset_dish();
    return true;

}

bool QKitchen::save_chages()
{
 save_dishes_titles();
 for(int i=0;i<dishes->size();++i){
     dishes->operator [](i).save_in_file();
 }
return true;
}

bool QKitchen::add_product_in_new_dish()
{
    QInputDialog input_dialog;
    input_dialog.setDoubleDecimals(4);

    double temp_amount=input_dialog.getDouble(this,"Сколько добавить","Сюда");
    if(!temp_amount){
        QMessageBox::information(0,"Eror","Неправильное количество");
        return false;
        }
    auto temp_dish_pair(avaible_product->get_pair_product_and_amount(list_widget_avaible_product->currentRow()));
    temp_dish.add_ingridient(temp_dish_pair.first,temp_amount);
    temp_dish.set_price();
    temp_dish.set_weght();
    list_widget_new_dish->clear();
    list_widget_new_dish->addItems(temp_dish.to_string_list());
    line_edit_price_dish->display(temp_dish.get_price());
    lcd_numb_weight_dish->display(temp_dish.get_weight());

    return true;
}

bool QKitchen::delete_product_from_dish()
{
    if(list_widget_new_dish->currentRow()>=0){

        temp_dish.delete_ingridient(list_widget_new_dish->currentRow());
        list_widget_new_dish->clear();
        temp_dish.set_price();
        temp_dish.set_weght();
        line_edit_price_dish->display(temp_dish.get_price());
        lcd_numb_weight_dish->display(temp_dish.get_weight());

        list_widget_new_dish->addItems(temp_dish.to_string_list());
        return true;
    }

    QMessageBox::information(0,"Eror","Не выбран продукт для удаления");
    return false;

}

void QKitchen::reset_list_and_labels()
{
    line_edit_name_dish->clear();
    line_edit_price_dish->display(0.0);
    lcd_numb_weight_dish->display("00.00");
    list_widget_new_dish->clear();

}

void QKitchen::load_dishes()
{
    QDish new_dish;
    for(int i =0;i<dishes_title.size();++i){
     new_dish.load_from_file(dishes_title[i]);
     dishes->push_back(new_dish);
    }
}

void QKitchen::delete_dish()
{
    if(list_widget_avaible_dishes->currentRow()>=0){
   QFile::remove(dishes_title[list_widget_avaible_dishes->currentRow()]);
        dishes->remove(list_widget_avaible_dishes->currentRow());
    dishes_title.remove(list_widget_avaible_dishes->currentRow());
    create_list_avaible_dishes();
    }
    
    save_chages();
}

void QKitchen::edit_dish()
{
    if(list_widget_avaible_dishes->currentRow()>=0){
    temp_dish=dishes->operator [](list_widget_avaible_dishes->currentRow());

    list_widget_new_dish->clear();
    list_widget_new_dish->addItems(dishes->operator [](list_widget_avaible_dishes->currentRow()).to_string_list());

    line_edit_name_dish->setText(dishes->operator [](list_widget_avaible_dishes->currentRow()).get_name());
    line_edit_price_dish->display(dishes->operator[](list_widget_avaible_dishes->currentRow()).get_weight());

    lcd_numb_weight_dish->display(dishes->operator [](list_widget_avaible_dishes->currentRow()).get_weight());

    dishes->remove(list_widget_avaible_dishes->currentRow());
    dishes_title.remove(list_widget_avaible_dishes->currentRow());


    save_dishes_titles();

    create_list_avaible_dishes();

}

}



void QKitchen::slot_add_product_in_new_dish()
{

 add_product_in_new_dish();
}

void QKitchen::slot_add_new_dish()
{
    add_new_dish();
}

void QKitchen::slot_delete_product_from_dish()
{
    delete_product_from_dish();
}

void QKitchen::slot_save_changes()
{
    save_chages();

}

void QKitchen::slot_delete_dish()
{
    delete_dish();
}

void QKitchen::slot_edit_dish()
{
    edit_dish();
}



