#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    {
    ui->setupUi(this);
    list_product=new QListWidget;
    dialog_add = new MyDialogAdd;
storage=new Storage;
    labelheders=new QLabel("Наименование             цена                     тип                      количество",this);
    }



    create_new_product_button = new QPushButton("&Создать новый продукт",this);
add_amount_product_button=new QPushButton("&Добавить количетво продукта",this);
del_product_button= new QPushButton("&Удалить продукт",this);
sort_by_name_button=new QPushButton("&Сортировать по имени",this);
sort_by_price_button=new QPushButton("&Сортировать по цене",this);
sort_by_amount_button=new QPushButton("&Сортировать по количеству",this);
save_in_file_button=new QPushButton("&Сохранить",this);
load_from_file_button= new QPushButton("&Загрузить ",this);

connect(create_new_product_button,SIGNAL(pressed()),dialog_add,SLOT(show()));
connect(dialog_add->pbAdd,SIGNAL(pressed()),this,SLOT(slot_add_new_product()));
connect(del_product_button,SIGNAL(pressed()),this,SLOT(slot_delete_product()));
connect(sort_by_name_button,SIGNAL(pressed()),this,SLOT(slot_sort_by_name()));
connect(sort_by_price_button,SIGNAL(pressed()),this,SLOT(slot_sort_by_price()));
connect(sort_by_amount_button,SIGNAL(pressed()),this,SLOT(slot_sort_by_amount()));
connect(save_in_file_button,SIGNAL(pressed()),this,SLOT(slot_save_in_file()));
connect(load_from_file_button,SIGNAL(pressed()),this,SLOT(slot_load_from_file()));
connect(add_amount_product_button,SIGNAL(pressed()),this,SLOT(slot_add_amount_product()));


top_h_lay= new QHBoxLayout;
buttons_lay=new QVBoxLayout;
labels_lay=new QHBoxLayout;

labels_and_viewlist_lay=new QVBoxLayout;
//for(int i=0;i<labels.size();i++){
 //labels_lay->addWidget(labels[i]);
//}

labels_and_viewlist_lay->addWidget(labelheders);
buttons_lay->addWidget(save_in_file_button);
buttons_lay->addWidget(create_new_product_button);
buttons_lay->addWidget(del_product_button);
buttons_lay->addWidget(sort_by_name_button);
buttons_lay->addWidget(sort_by_price_button);
buttons_lay->addWidget(sort_by_amount_button);
buttons_lay->addWidget(load_from_file_button);
buttons_lay->addWidget(add_amount_product_button);
//labels_lay->addWidget(labelheders);
//labels_and_viewlist_lay->addLayout(labels_lay);
labels_and_viewlist_lay->addWidget(list_product);
top_h_lay->addLayout(labels_and_viewlist_lay);
top_h_lay->addLayout(buttons_lay);
storage->load_from_file();
create_view_list();


 this->setLayout(top_h_lay);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::create_view_list()
{
    QString str;
    QTextStream txt_stream(&str);

    txt_stream.setFieldWidth(25);
    txt_stream.setPadChar(' ') ;
    txt_stream.setRealNumberPrecision(4);
    txt_stream.setFieldAlignment(QTextStream::AlignLeft);
    list_product->clear();
    for(int i=0;i<storage->size();i++){
        txt_stream<<storage->get_pair_product_and_amount(i).first.get_prdct_name()<<
                    storage->get_pair_product_and_amount(i).first.get_prdct_price()<<
                    storage->get_pair_product_and_amount(i).first.get_type_product()<<
                    storage->get_pair_product_and_amount(i).second;
        list_product->addItem(str);
        str.clear();
    }

}

void Widget::delete_product(int index)
{
    storage->delete_ingridient(index);
}

void Widget::load_from_file()
{

    storage->clear();
storage->load_from_file();

create_view_list();

}

void Widget::save_in_file()
{
    storage->save_in_file();

}

void Widget::add_amount_product()
{
    if(list_product->currentRow()>=0)
    {
    storage->add_amount(list_product->currentRow(),0.500);
    create_view_list();
    }

}

void Widget::slot_add_new_product(){

Product tpr(dialog_add->temp_product.get_prdct_name(),
          dialog_add->temp_product.get_type_product(),
           dialog_add->temp_product.get_prdct_price());
double amt=dialog_add->get_amont_product();
storage->add_ingridient(tpr,amt);
create_view_list();

}

void Widget::slot_delete_product()
{if(list_product->currentRow()>=0){
    delete_product(list_product->currentRow());
    create_view_list();
    }
}

void Widget::slot_sort_by_name()
{
storage->sort_by_name();
create_view_list();
}

void Widget::slot_sort_by_price()
{

    storage->sort_by_price();
    create_view_list();

}

void Widget::slot_sort_by_amount()
{
    storage->sort_by_amount();
    create_view_list();
}

void Widget::slot_save_in_file()
{
 save_in_file();

}

void Widget::slot_load_from_file()
{
    load_from_file();
}

void Widget::slot_add_amount_product()
{
add_amount_product();
}
