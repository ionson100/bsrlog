#ifndef MYSETTINGS_H
#define MYSETTINGS_H

#include <QMainWindow>
#include <QSettings>

class MySettings
{

private:
    QSettings *settings;
public:
    MySettings();
    QSettings* getSettings(){
        return this->settings;
    }
    QString getStyle1();
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

    QColor getColorSelectButton();
    void setColorSelectButton(QColor col);


};

#endif // MYSETTINGS_H
