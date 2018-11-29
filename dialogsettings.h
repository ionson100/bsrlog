#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QDialog>
#include<mainwindow.h>
#include<QSettings>

namespace Ui {
class DialogSettings;
}

class DialogSettings : public QDialog
{
    Q_OBJECT

public:
    MainWindow *uim;
    explicit DialogSettings(QWidget *parent = 0);
    ~DialogSettings();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_color_clicked();

    void on_pushButton_style1_save_clicked();

    void on_pushButton_rolback_base_clicked();
    void on_textChangedStyle1();

    void on_pushButton_2_clicked();

private:


    Ui::DialogSettings *ui;
};

#endif // DIALOGSETTINGS_H
