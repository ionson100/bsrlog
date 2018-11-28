#ifndef UTILS_H
#define UTILS_H

#include <QListView>
#include <QSettings>
#include<QString>
#include<mainwindow.h>
#include<mysettings.h>



class Utils
{

protected:
    Utils();
public:

    static QString getName1(){
        return "bsr4";
    }

    static QString getName2(){
        return "bsrion4";
    }



    static  void  getStyle1( QListView *s){
        MySettings settings;
        QString style=settings.getStyle1();
        s->setStyleSheet(style);
        s->show();
    }

    static  void  setStyle1(const QString str){
        MySettings settings;

        settings.getSettings()->setValue("style1",str);
        settings.getSettings()->sync();
    }
};

#endif // UTILS_H
