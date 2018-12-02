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

    static QList<QString> getColeList(){
        QList<QString> list={"UTF-8"
                             ,"Big5"
                             ,"Big5-HKSCS"
                             ,"CP949"
                             ,"EUC-JP"
                             ,"EUC-KR"
                             ,"GB18030"
                             ,"HP-ROMAN8"
                             ,"IBM 850"
                             ,"IBM 866"
                             ,"IBM 874"
                             ,"ISO 2022-JP"
                             ,"ISO 8859-1"
                             ,"ISO 8859-13"
                             ,"Iscii-Bng"
                             ,"KOI8-R"
                             ,"KOI8-U"
                             ,"Macintosh"
                             ,"Shift-JIS"
                             ,"TIS-620"
                             ,"TSCII"
                             ,"UTF-16"
                             ,"UTF-16BE"
                             ,"UTF-16LE"
                             ,"UTF-32"
                             ,"UTF-32BE"
                             ,"UTF-32LE"
                             ,"Windows-1250"
                             ,"Windows-1258"};
        return list;
    }
    static QString getCharset(int i){
        return getColeList()[i];
    }
};

#endif // UTILS_H
