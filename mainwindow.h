#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QStandardItem>
#include<QStringListModel>

namespace Ui {
class MainWindow;
}

class MainWindow :  public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();







private slots:

    void focusCombo();
    void on_listView_1_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_actionopen_triggered();





    void on_splitter_2_splitterMoved(int pos, int index);

    void on_actionSearch_list_triggered();

private:

    QSettings *settings;



    void on_load_data(QString str);

    QStringList list;
    QStringList list_index;
    QStringList list_select;
    QStandardItemModel *model;
    QStringListModel *model_index;
    QStringList select_index;

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
