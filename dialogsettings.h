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

private:
    QSettings *settings;

    Ui::DialogSettings *ui;
};

#endif // DIALOGSETTINGS_H
