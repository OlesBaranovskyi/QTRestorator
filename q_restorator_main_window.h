#ifndef Q_RESTORATOR_MAIN_WINDOW_H
#define Q_RESTORATOR_MAIN_WINDOW_H
#include <memory>
#include <QMainWindow>
#include <widget.h>
#include <qkitchen.h>
class QKitchen;
class Q_Restorator_main_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Q_Restorator_main_window(QWidget *parent = 0);

    QTabWidget* tab_widget;
 Widget* widget_storage;
    QKitchen* widget_qkitchen;





Widget* get_widget_storage(){
    return widget_storage;
}
void refresh_pointer_qkithen();

signals:

public slots:
void slot_refresh_pointer(){
    refresh_pointer_qkithen();
}
};

#endif // Q_RESTORATOR_MAIN_WINDOW_H
