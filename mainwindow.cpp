#include "findercolordelegate.h"
#include "htmldelegate.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
#include <QStandardItem>
#include <QStringListModel>
#include<QTextStream>
#include <QLineEdit>
#include <QSplitter>
#include <dialogsearch.h>
#include<dialogsettings.h>
#include<utils.h>
#include <qlabel.h>
#include <QCoreApplication>
#include <QTextCodec>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
     qRegisterMetaTypeStreamOperators<QList<QString> >("QList<QStrinf>");
    QCoreApplication::setOrganizationName("bsr");
    QCoreApplication::setOrganizationDomain("bsr.com");
    QCoreApplication::setApplicationName("bsrion");
    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
   // on_load_data("/home/bsr/aa.txt");
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_F), this, SLOT(focusCombo()));
    connect(ui->comboBox->lineEdit(), SIGNAL(returnPressed()),this, SLOT(on_pushButton_clicked()));

    settings= MySettings().getSettings();
    int f1 = settings->value("f1",400).toInt();
    int f2 = settings->value("f2",400).toInt();

    ui->splitter_2->setSizes({f1,f2});

    addComboBox();

    connect(ui->actionSettings,SIGNAL(triggered()),this,SLOT(on_actionSsettings_triggered()));
    connect(ui->actionclose, SIGNAL(triggered()), this, SLOT(onAction()));


    Utils::getStyle1(ui->listView);
    ui->listView->setItemDelegate(new HtmlDelegate("-~~~-"));
    this->labelfile=new QLabel(this);
    labelfile->setText(" No selected file ");
    ui->statusBar->addWidget(labelfile);
    setselect=new QSet<int>();

    restoreGeometry(settings->value("geometry").toByteArray());
    restoreState(settings->value("windowState").toByteArray());
    QStringList argumentList = QCoreApplication::arguments();
    if(argumentList.size()>1){
        on_load_data(argumentList[1]);
    }







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::focusCombo()
{
    ui->comboBox->lineEdit()->selectAll();
 ui->comboBox->setFocus();
}


void MainWindow::on_load_data(const QString &str)
{

    QFile file(str);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, "error", file.errorString());
        return;
    }
   // model->clear();

    currentOpenFile=str;
    MySettings set;
    set.addOpenFiles(str);
    labelfile->setText(str);
    QTextStream in(&file);
    const QString d=Utils::getCharset(set.getSettings()->value("charset",0).toInt());
    QTextCodec *codec = QTextCodec::codecForName(QString(d).toUtf8());
    in.setCodec(codec);
    list_index.clear();
    list.clear();
    int i=0;
    while(!in.atEnd()) {
        QString line = in.readLine();
        list_index.append(QString::number(i++));
        list.append(line.trimmed());
    }

    model = new QStandardItemModel(ui->listView);

    for(int i=0;i<list.size();i++){
       auto *s=new QStandardItem(list[i]);

        model->setItem( i, s );
    }


    ui->listView->setUniformItemSizes(true);
    ui->listView->setModel(model);

    file.close();
    Utils::getStyle1(ui->listView);

    ui->listView_1->setModel(static_cast<QAbstractItemModel*>(new QStandardItemModel()));

}





void MainWindow::on_listView_1_clicked(const QModelIndex &index)
{
        int indexs=select_index[index.row()].toInt();
       // QMessageBox::information(0, "info", select_index[index.row()]);
        QModelIndex indexOfTheCellIWant = model->index(indexs, 0);
        ui->listView->setCurrentIndex(indexOfTheCellIWant);
}

void MainWindow::on_pushButton_clicked()
{
    auto str=ui->comboBox->currentText();
    if(str.trimmed().size()==0){
        return;
    }
    list_select.clear();


    for(int i=0;i<select_index.size();i++){
        int d=select_index[i].toInt();
        QModelIndex vIndex = ui->listView->model()->index(d,0);
        ui->listView->model()->setData(vIndex, QBrush(Qt::transparent), Qt::BackgroundColorRole);
    }
  select_index.clear();
    for(int i=0;i<list.size();i++){
        QString s=list[i];
        if(s.contains(str)){
            list_select.append(s);
            select_index.append(QString::number(i));
        }
    }
    auto * m = new QStringListModel(this);
    m->setStringList(list_select);
    ui->listView_1->setUniformItemSizes(true);
    ui->listView_1->setModel(m);
    for(int i=0;i<select_index.size();i++){
        int d=select_index[i].toInt();
        QModelIndex vIndex = ui->listView->model()->index(d,0);
         QColor oldColor = settings->value("colorrow", QColor(Qt::darkYellow)).value<QColor>();
        ui->listView->model()->setData(vIndex, QBrush(oldColor), Qt::BackgroundColorRole);
    }
}



//нажатие на меню выбора файла
void MainWindow::on_actionopen_triggered()
{
    QString dir=QDir::homePath();
    if(settings->value("fileopen","")!=""){
        dir=settings->value("fileopen").toString();
    }
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), dir,
       tr("All Files (*.*)"));

       if (fileName != "") {
           auto info = QFileInfo(fileName);
          settings->setValue("fileopen",info.absoluteFilePath());
          settings->sync();
          on_load_data(fileName);
       }
}


////перемещение сплиттера


void MainWindow::on_splitter_2_splitterMoved()
{
    QList<int> d= ui->splitter_2->sizes();
    settings->setValue("f1", d[0]);
    settings->setValue("f2", d[1]);
    settings->sync();

}

void MainWindow::on_actionSearch_list_triggered()
{
    DialogSearch s(this);

    switch( s.exec() ) {
        case QDialog::Accepted:

            break;
        case QDialog::Rejected:

            break;
    default:{
    }

    }
}

void MainWindow::on_actionSsettings_triggered()
{
    DialogSettings d(this);
    d.exec();
}

void MainWindow::addComboBox()
{
    ui->comboBox->clear();
            QFile f(QDir::homePath()+"/.bsrlog");
            if (f.open(QIODevice::ReadWrite))
            {

                QTextStream in(&f);
                   while (!in.atEnd())
                   {
                       ui->comboBox->addItem(in.readLine());
                   }
            }
            f.close();
}

void MainWindow::checkStyle1List(const QString &s)
{
    ui->listView->setStyleSheet(s);
    ui->listView_1->show();
}

void MainWindow::on_lineEdit_fast_finder_textChanged(const QString &arg1)
{
    ui->listView->setItemDelegate(new HtmlDelegate(arg1));

}

void MainWindow::refrashstyleList1()
{

    Utils::getStyle1(ui->listView);
  ui->listView->setItemDelegate(new HtmlDelegate("-~~~-"));

}

void MainWindow::onAction()
{
    QObject *obj = sender();
       QString objName = obj->objectName();
       if(objName==ui->actionclose->objectName()){
          QCoreApplication::exit(0) ;
       }else{
          on_load_data(objName);
       }

}

void MainWindow::on_pushButton_previous_clicked()
{


}

void MainWindow::on_pushButton_nex_clicked()
{

}

void MainWindow::on_actionLast_opening_files_hovered()
{
    MySettings set;
    QList<QString> list=set.getLastOpeningFiles();
    //
    if(list.empty())return;
     QMenu * menu=new QMenu("sdsd",this);

     for(const QString &f:list){
         if(currentOpenFile==f)continue;
         auto *action=new QAction(f,this);


         action->setObjectName(f);
         connect(action, SIGNAL(triggered()), this, SLOT(onAction()));
         menu->addAction(action);
     }


    ui->actionLast_opening_files->setMenu(menu);
}
