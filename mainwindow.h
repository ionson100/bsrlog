#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QStandardItem>
#include<QStringListModel>
#include <qdir.h>
#include <qfile.h>
#include <qtextstream.h>

namespace Ui {
class MainWindow;
}

class MainWindow :  public QMainWindow
{

    Q_OBJECT

public:
    //const QString NAME1="bsr4",NAME2="bsrion4";
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 void addComboBox();

private slots:
    void on_actionSsettings_triggered(bool b);
    void focusCombo();
    void on_listView_1_clicked( const QModelIndex &index);

    void on_pushButton_clicked();

    void on_actionopen_triggered();





    void on_splitter_2_splitterMoved(int pos, int index);

    void on_actionSearch_list_triggered();


private:
     Ui::MainWindow *ui;


    QSettings *settings;



    void on_load_data(QString str);

    QStringList list;
    QStringList list_index;
    QStringList list_select;
    QStandardItemModel *model;
    QStringListModel *model_index;
    QStringList select_index;



};

#endif // MAINWINDOW_H
