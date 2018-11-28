#ifndef UTILS_H
#define UTILS_H

#include <QListView>
#include <QSettings>
#include<QString>
#include<mainwindow.h>



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

    static  QString getStyleString1(){
        QString style = "QListView "
                        "\n"
                        "{"
                        "\n"
                        "color: #3F412C;"
                        "\n"
                        "selection-background-color: blue;"
                        "\n"
                        "selection-color: #0E0E06;"
                        "\n"
                        "background: #F2F3E7;"
                        "\n"
                        "font-family: Times New Roman;font-size: 13pt;"
                        "\n"
                        "}"
                        "\n"
                        "QListView::item { "
                        "\n"
                        "height: 20px;"
                        "\n"
                        "}";
        return style;


    }

    static  void  setStyle1( QListView *s){

        QSettings settings(getName1(),getName2());
        QString style=settings.value("style1",getStyleString1()).toString();
        s->setStyleSheet(style);
        s->show();

    }
};

#endif // UTILS_H
