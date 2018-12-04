#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mysettings.h"
#include "sslnetworkaccessmanager.h"

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QSet>
#include <QSettings>
#include <QStandardItem>
#include<QStringListModel>
#include <qdir.h>
#include <qfile.h>
#include <qlabel.h>
#include <qtextstream.h>

namespace Ui {
class MainWindow;
}
static  QSet<int> *setselect;
class MainWindow :  public QMainWindow
{

    Q_OBJECT

public:

    //const QString NAME1="bsr4",NAME2="bsrion4";
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 void addComboBox();
 void checkStyle1List(const QString &s);
 void refrashstyleList1();
 static QSet<int>* getSetSelect(){
     return setselect;
 }
 QString currentOpenFile;
  void on_load_data(const QString &str);
public slots:

private slots:
  void replyFinished(QNetworkReply* r);
    void onAction();
    void on_actionSsettings_triggered();
    void focusCombo();
    void on_listView_1_clicked( const QModelIndex &index);
    void on_pushButton_clicked();
    void on_actionopen_triggered();
    void on_splitter_2_splitterMoved();
    void on_actionSearch_list_triggered();
    void on_lineEdit_fast_finder_textChanged(const QString &arg1);
    void on_pushButton_previous_clicked();
    void on_pushButton_nex_clicked();
    void closeEvent(QCloseEvent *event)
    {
        MySettings settings;
        settings.getSettings()->setValue("geometry", saveGeometry());
        settings.getSettings()->setValue("windowState", saveState());
        QMainWindow::closeEvent(event);
    }



    void on_actionLast_opening_files_hovered();

    void on_action_download_data_triggered();

private:
    void on_Reguest();
    SslNetworkAccessManager *manager;
    QLabel *labelfile;
     Ui::MainWindow *ui;
    QSettings *settings;

    QStringList list;
    QStringList list_index;
    QStringList list_select;
    QStandardItemModel *model;
    QStringListModel *model_index;
    QStringList select_index;
};

#endif // MAINWINDOW_H
