#ifndef DIALOGSEARCH_H
#define DIALOGSEARCH_H

#include <QDialog>
#include<mainwindow.h>

namespace Ui {
class DialogSearch;
}

class DialogSearch : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSearch(QWidget *parent = nullptr);
    ~DialogSearch();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

private:
    MainWindow *uim;
    Ui::DialogSearch *ui;
};

#endif // DIALOGSEARCH_H
