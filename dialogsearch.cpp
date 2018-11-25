#include "dialogsearch.h"
#include "ui_dialogsearch.h"
#include<mainwindow.h>

DialogSearch::DialogSearch(QWidget *parent) :
    QDialog(parent),
     ui(new Ui::DialogSearch)
{
   uim= dynamic_cast<MainWindow*>(parent);
    ui->setupUi(this);
}

DialogSearch::~DialogSearch()
{
    delete ui;
}

void DialogSearch::on_pushButton_save_clicked()
{

    accept();
}

void DialogSearch::on_pushButton_cancel_clicked()
{
   reject ();
}
