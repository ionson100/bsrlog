#include "mysettings.h"

MySettings::MySettings()
{
    this->settings=new  QSettings("bsr4","bsrion4");

}

QString MySettings::getStyle1()
{
    return  settings->value("style1",getStyleString1()).toString();
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
