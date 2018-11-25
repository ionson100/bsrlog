#include "dialogsearch.h"
#include "ui_dialogsearch.h"
#include <QDir>
#include<mainwindow.h>
#include <qtextstream.h>

DialogSearch::DialogSearch(QWidget *parent) :
    QDialog(parent),
     ui(new Ui::DialogSearch)
{
   uim= dynamic_cast<MainWindow*>(parent);
    ui->setupUi(this);
    QFile f(QDir::homePath()+"/.bsrlog");
    if (f.open(QIODevice::ReadWrite))
    {
        QTextStream in(&f);
           while (!in.atEnd())
           {
               ui->plainTextEdit->appendPlainText(in.readLine());

           }

    }
    f.close();
}

DialogSearch::~DialogSearch()
{
    delete ui;
}

void DialogSearch::on_pushButton_save_clicked()
{

    QFile f(QDir::homePath()+"/.bsrlog");
    if (f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QString data = ui->plainTextEdit->toPlainText();
        QStringList strList = data.split(QRegExp("[\n]"),QString::SkipEmptyParts);
        QTextStream s(&f);
           for (int i = 0; i < strList.size(); ++i)
             s << strList.at(i) << '\n';
    }
    f.close();
    uim->addComboBox();
    accept();
}

void DialogSearch::on_pushButton_cancel_clicked()
{
   reject ();
}
