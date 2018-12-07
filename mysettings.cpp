#include "mysettings.h"

#include <QFontDialog>
#include <qfontdialog.h>

MySettings::MySettings()
{
    this->settings=new  QSettings();

}

QString MySettings::getStyle1()
{
    QFont f=getFont1();
    QColor sbc=getColorselectBackground();
    QColor sdt=getColorselectetedText();
    QColor bg=getColorBackground();
    QColor text=getColorText();
    QString style = "QListView "
                    "\n"
                    "{"
                    "\n"
                    "color: "+text.name()+";"
                    "\n"
                    "selection-background-color:"+sbc.name()+";"
                    "\n"
                    "selection-color: "+sdt.name()+";"
                    "\n"
                    "background: "+bg.name()+";"
                    "\n"
                    "font-family: "+f.family()+";font-size: "+QString::number(f.pointSize())+"pt;"
                    "\n"
                    "}"
                    "\n"
                   ;
    return  style;
}

QColor MySettings::getColorSelectButton()
{
    return settings->value("colorrow", QColor(Qt::darkYellow)).value<QColor>();
}

void MySettings::setColorSelectButton(const QColor &col)
{
   settings->setValue("colorrow",col);
   settings->sync();
}

void MySettings::setFont1(const QFont &fint)
{
    settings->setValue("font1", fint);

    settings->sync();
}

void MySettings::getfontDialog( QWidget *parent)
{
    bool ok;
    QFont f=settings->value("font1",QFont()).value<QFont>();
    int size=settings->value("font1size",14).toInt();
    QFont font = QFontDialog::getFont(
                    &ok, QFont(f.family(),size), parent);
    if (ok) {
        int d=font.pointSize();
        settings->setValue("font1",font);
        settings->setValue("font1size",d);
        settings->sync();
    }
}

QFont MySettings::getFont1()
{
    QFont f=settings->value("font1",QFont()).value<QFont>();
    int size=settings->value("font1size",14).toInt();
    f.setPointSize(size);
    return f;
}

QColor MySettings::getColorselectBackground()
{
    return settings->value("colorsbc", QColor(Qt::darkYellow)).value<QColor>();
}

void MySettings::setColorselectBackground(const QColor &color)
{
    settings->setValue("colorsbc",color);
    settings->sync();
}

QColor MySettings::getColorselectetedText()
{
    return settings->value("colorsbt", QColor(Qt::black)).value<QColor>();
}

void MySettings::setColorselectetedText(const QColor &color)
{
    settings->setValue("colorsbt",color);
    settings->sync();

}

QColor MySettings::getColorBackground()
{
    return settings->value("colorbg", QColor(Qt::white)).value<QColor>();
}

void MySettings::setColorBackground(const QColor &color)
{
    settings->setValue("colorbg",color);
    settings->sync();
}

QColor MySettings::getColorText()
{
    return settings->value("colortext", QColor(Qt::black)).value<QColor>();
}

void MySettings::setColorText(const QColor &color)
{
    settings->setValue("colortext",color);
    settings->sync();
}

double MySettings::getValueHeigcht()
{
    return  settings->value("heigcht", 1.0).toDouble();
}

void MySettings::setValueHeigcht(double value)
{
      settings->setValue("heigcht",value);
      settings->sync();

}

QList<QString> MySettings::getLastOpeningFiles()
{
    QList<QString> myList = settings->value("openfiles").value<QList<QString> >();
    return myList;
}

void MySettings::addOpenFiles(const QString &str)
{
     QList<QString> myList = settings->value("openfiles").value<QList<QString> >();
     bool r=false;
     for (auto & elem : myList){
         if(elem==str){
             r=true;
             break;
         }
     }

     if(r){
         return;
     }
     myList.append(str);
     settings->setValue("openfiles", QVariant::fromValue(myList));
     settings->sync();
}

bool MySettings::getUseRemote()
{
     bool b = settings->value("usermote",false).toBool();
     return b;
}

void MySettings::setUseRemote(bool b)
{
    settings->setValue("usermote",b);
    settings->sync();
}

QString MySettings::getRemoteUrl()
{
    return settings->value("urlremote","").toString();
}

void MySettings::setRemoteUrl(const QString &s)
{
    settings->setValue("urlremote",s);
    settings->sync();
}

int MySettings::getTimerIntervalRemote()
{
    return settings->value("timerremote",60).toInt();
}

void MySettings::setTimerIntervalRemote(int i)
{
    settings->setValue("timerremote",i);
    settings->sync();
}

bool MySettings::getUseNumber()
{
    return settings->value("usenumber",false).toBool();
}

void MySettings::setUseNumber(bool i)
{
    settings->setValue("usenumber",i);
}


