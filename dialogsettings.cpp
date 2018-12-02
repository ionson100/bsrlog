#include "dialogsettings.h"
#include "ui_dialogsettings.h"
#include "mainwindow.h"
#include"QColorDialog"
#include"mysettings.h"
#include"utils.h"

#include <QFontDialog>

DialogSettings::DialogSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettings)
{
    MySettings sett;
    ui->setupUi(this);
    uim= dynamic_cast<MainWindow*>(parent);
    ui->textEditStyle1->setText(sett.getStyle1());

    refrashButton(ui->pushButton_color,sett.getColorSelectButton());
    refrashButton(ui->pushButton_sbc,sett.getColorselectBackground());
    refrashButton(ui->pushButton_stxc,sett.getColorselectetedText());
    refrashButton(ui->pushButton_background,sett.getColorBackground());
    refrashButton(ui->pushButton_color_text,sett.getColorText());
    ui->doubleSpinBox1->setValue(sett.getValueHeigcht());
    QObject::connect(ui->textEditStyle1,SIGNAL(textChanged()),this,SLOT(on_textChangedStyle1()));

    QList<QString> list=Utils::getColeList();
    for (int var = 0; var < list.size(); ++var) {
        ui->comboBox->addItem(list[var]);
    }

    ui->comboBox->setCurrentIndex(sett.getSettings()->value("charset",0).toInt());
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),SLOT(on_setcharsrt(int)));

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

    if(newColor !=oldColor&&newColor.isValid()){
        MySettings sett;
        sett.setColorSelectButton(newColor);
        refrashButton(ui->pushButton_background,newColor);

    }
}

void DialogSettings::on_pushButton_style1_save_clicked()
{
    Utils::setStyle1(ui->textEditStyle1->toPlainText());


}

void DialogSettings::on_pushButton_rolback_base_clicked()
{
    ui->textEditStyle1->setText(MySettings::getStyleString1());
}

void DialogSettings::on_textChangedStyle1()
{
    uim->checkStyle1List(ui->textEditStyle1->toPlainText());

}

void DialogSettings::on_pushButton_2_clicked()
{
    this->close();
}

void DialogSettings::on_pushButton_font_dialog_clicked()
{
    MySettings d;
    d.getfontDialog(this);
    ui->textEditStyle1->setText(d.getStyle1());
    uim->refrashstyleList1();
}

void DialogSettings::on_pushButton_sbc_clicked()
{
    MySettings sett;
    QColor oldColor = sett.getColorselectBackground();
    QColor newColor = QColorDialog::getColor(oldColor,parentWidget());

    if(newColor !=oldColor&&newColor.isValid()){

        sett.setColorselectBackground(newColor);
        refrashButton(ui->pushButton_sbc,newColor);

        ui->textEditStyle1->setText(sett.getStyle1());
        uim->refrashstyleList1();
    }
}


void DialogSettings::on_pushButton_sel_text_color_clicked()
{

}

void DialogSettings::on_pushButton_stxc_clicked()
{
    MySettings sett;
    QColor oldColor = sett.getColorselectetedText();
    QColor newColor = QColorDialog::getColor(oldColor,parentWidget());

    if(newColor !=oldColor&&newColor.isValid()){

        sett.setColorselectetedText(newColor);
        refrashButton(ui->pushButton_stxc,newColor);
        ui->textEditStyle1->setText(sett.getStyle1());
        uim->refrashstyleList1();
    }
}

void DialogSettings::refrashButton( QPushButton *button, const QColor & color){

    QPalette pal2 =  button->palette();
    pal2.setColor(QPalette::Button, color);
    button->setAutoFillBackground(true);
    button->setPalette(pal2);
    button->update();
    button->setFlat(true);
}

void DialogSettings::on_pushButton_background_clicked()
{
    MySettings sett;
    QColor oldColor = sett.getColorBackground();
    QColor newColor = QColorDialog::getColor(oldColor,parentWidget());

    if(newColor !=oldColor&&newColor.isValid()){

        sett.setColorBackground(newColor);
        refrashButton(ui->pushButton_stxc,newColor);
        ui->textEditStyle1->setText(sett.getStyle1());
        uim->refrashstyleList1();
    }
}

void DialogSettings::on_pushButton_color_text_clicked()
{
    MySettings sett;
    QColor oldColor = sett.getColorText();
    QColor newColor = QColorDialog::getColor(oldColor,parentWidget());

    if(newColor !=oldColor&&newColor.isValid()){

        sett.setColorText(newColor);
        refrashButton(ui->pushButton_color_text,newColor);
        ui->textEditStyle1->setText(sett.getStyle1());
        uim->refrashstyleList1();
    }
}



void DialogSettings::on_doubleSpinBox1_valueChanged(double arg1)
{
    MySettings sett;
    sett.setValueHeigcht(arg1);
    uim->refrashstyleList1();
}
