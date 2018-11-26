#include "dialogsettings.h"
#include "ui_dialogsettings.h"
#include "mainwindow.h"
#include"QColorDialog"

DialogSettings::DialogSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettings)
{
    ui->setupUi(this);
    uim= dynamic_cast<MainWindow*>(parent);
    // const QString NAME1=,NAME2="bsrion4";
    settings=new QSettings("bsr4","bsrion4");
     QColor oldColor = settings->value("colorrow", QColor(Qt::darkYellow)).value<QColor>();
     QPalette pal =  ui->pushButton_color->palette();
     pal.setColor(QPalette::Button, oldColor);
     ui->pushButton_color->setAutoFillBackground(true);
     ui->pushButton_color->setPalette(pal);
     ui->pushButton_color->update();
     ui->pushButton_color->setFlat(true);

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
    QColor oldColor = settings->value("colorrow", QColor(Qt::darkYellow)).value<QColor>();
    QColor newColor = QColorDialog::getColor(oldColor,parentWidget());
    if(newColor !=oldColor){
        settings->setValue("colorrow",newColor);
        settings->sync();

        QPalette pal =  ui->pushButton_color->palette();
        pal.setColor(QPalette::Button, newColor);
        ui->pushButton_color->setAutoFillBackground(true);
        ui->pushButton_color->setPalette(pal);
        ui->pushButton_color->update();
        ui->pushButton_color->setFlat(true);


    }
}
