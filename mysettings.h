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
    void setFont1(QFont fint);
    void getfontDialog( QWidget *parent);
    QFont getFont1();
    QColor getColorselectBackground();
    void setColorselectBackground(QColor color);

    QColor getColorselectetedText();
    void setColorselectetedText(QColor color);

    QColor getColorBackground();
    void setColorBackground(QColor color);

    QColor getColorText();
    void setColorText(QColor color);

    double getValueHeigcht();
    void setValueHeigcht(double value);


};

#endif // MYSETTINGS_H
