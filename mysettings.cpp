#include "mysettings.h"

#include <QFontDialog>
#include <qfontdialog.h>

MySettings::MySettings()
{
    this->settings=new  QSettings("bsr4","bsrion4");

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

void MySettings::setColorSelectButton(QColor col)
{
   settings->setValue("colorrow",col);
   settings->sync();
}

void MySettings::setFont1(QFont fint)
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

void MySettings::setColorselectBackground(QColor color)
{
    settings->setValue("colorsbc",color);
    settings->sync();
}

QColor MySettings::getColorselectetedText()
{
    return settings->value("colorsbt", QColor(Qt::black)).value<QColor>();
}

void MySettings::setColorselectetedText(QColor color)
{
    settings->setValue("colorsbt",color);
    settings->sync();

}

QColor MySettings::getColorBackground()
{
    return settings->value("colorbg", QColor(Qt::white)).value<QColor>();
}

void MySettings::setColorBackground(QColor color)
{
    settings->setValue("colorbg",color);
    settings->sync();
}

QColor MySettings::getColorText()
{
    return settings->value("colortext", QColor(Qt::black)).value<QColor>();
}

void MySettings::setColorText(QColor color)
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

//int MySettings::getValueHeigcht()
//{
//
//}

//void MySettings::setValueHeigcht(double value)
//{
;
//}
