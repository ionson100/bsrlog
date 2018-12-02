#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include "mysettings.h"

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

    void refrashButton(const QPushButton *button, QColor color, MySettings sett);
    void refrashButton(QPushButton *button, const QColor & color);
private slots:
    void on_setcharsrt(int i){
        MySettings sett;
        sett.getSettings()->setValue("charset",i);
        if(uim->currentOpenFile!=""){
            uim->on_load_data(uim->currentOpenFile);
        }
    }
    void on_pushButton_3_clicked();

    void on_pushButton_color_clicked();

    void on_pushButton_style1_save_clicked();

    void on_pushButton_rolback_base_clicked();
    void on_textChangedStyle1();

    void on_pushButton_2_clicked();

    void on_pushButton_font_dialog_clicked();

    void on_pushButton_sbc_clicked();

    void on_pushButton_sel_text_color_clicked();

    void on_pushButton_stxc_clicked();

    void on_pushButton_background_clicked();

    void on_pushButton_color_text_clicked();



    void on_doubleSpinBox1_valueChanged(double arg1);

private:
    void refrashButton(const QPushButton button,QColor color, MySettings sett);


    Ui::DialogSettings *ui;
};

#endif // DIALOGSETTINGS_H
