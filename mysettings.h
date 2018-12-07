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
    void setColorSelectButton(const QColor &col);
    void setFont1(const QFont &fint);
    void getfontDialog( QWidget *parent);
    QFont getFont1();
    QColor getColorselectBackground();
    void setColorselectBackground(const QColor &color);

    QColor getColorselectetedText();
    void setColorselectetedText(const QColor &color);

    QColor getColorBackground();
    void setColorBackground(const QColor &color);

    QColor getColorText();
    void setColorText(const QColor &color);

    double getValueHeigcht();
    void setValueHeigcht(double value);

    QList<QString> getLastOpeningFiles();
    void addOpenFiles(const QString &str);

    bool getUseRemote();
    void setUseRemote(bool b);

    QString getRemoteUrl();
    void setRemoteUrl(const QString &s);

    int getTimerIntervalRemote();
    void setTimerIntervalRemote(int i);

    bool getUseNumber();
    void setUseNumber(bool i);


};

#endif // MYSETTINGS_H
