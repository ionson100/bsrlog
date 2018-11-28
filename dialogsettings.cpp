#include "dialogsettings.h"
#include "ui_dialogsettings.h"
#include "mainwindow.h"
#include"QColorDialog"
#include"mysettings.h"
#include"utils.h"

DialogSettings::DialogSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettings)
{
    ui->setupUi(this);
    uim= dynamic_cast<MainWindow*>(parent);
    // const QString NAME1=,NAME2="bsrion4";

    MySettings sett;
     QColor oldColor = sett.getColorSelectButton();
     QPalette pal =  ui->pushButton_color->palette();
     pal.setColor(QPalette::Button, oldColor);
     ui->pushButton_color->setAutoFillBackground(true);
     ui->pushButton_color->setPalette(pal);
     ui->pushButton_color->update();
     ui->pushButton_color->setFlat(true);
     ui->textEditStyle1->setText(sett.getStyle1());

}

DialogSettings::~DialogSettings()
{
    delete ui;
}
// edit color
void DialogSettings::on_pushButton_3_clicked()
{

}

void DialogSettings::on_pushButton_color_clicked()
{

    MySettings sett;
    QColor oldColor = sett.getColorSelectButton();
    QColor newColor = QColorDialog::getColor(oldColor,parentWidget());
    if(newColor !=oldColor){
        MySettings sett;
        sett.setColorSelectButton(newColor);
        QPalette pal =  ui->pushButton_color->palette();
        pal.setColor(QPalette::Button, newColor);
        ui->pushButton_color->setAutoFillBackground(true);
        ui->pushButton_color->setPalette(pal);
        ui->pushButton_color->update();
        ui->pushButton_color->setFlat(true);


    }
}

void DialogSettings::on_pushButton_style1_save_clicked()
{
    Utils::setStyle1(ui->textEditStyle1->toPlainText());


}

void DialogSettings::on_pushButton_rolback_base_clicked()
{
    MySettings s;
    ui->textEditStyle1->setText(s.getStyleString1());
}
