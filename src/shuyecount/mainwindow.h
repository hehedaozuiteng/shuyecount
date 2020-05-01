#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "supporttool.h"
#include "werahouse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

   //void resizeEvent(QResizeEvent *event);

    bool firstConnect(QSqlDatabase testDb); //测试是否链接数据库


    ~MainWindow();




private slots:

    void on_pushButtonMainPage_clicked();//首页按钮

    void on_sqlquary_triggered();

    void on_generalQueryPushButton_clicked();

    void on_generalQueryPushButtonClean_clicked();

    void on_generalQueryPushButtonPaste_clicked();

    void on_generalQueryPushButtonCopy_clicked();





    void on_pushButtonReports_clicked();



    void on_jianyanUpdatePushButton_clicked();

    void on_jianyanSizeComboBox_editTextChanged(const QString &arg1);

    void on_jianyanPaihaoComboBox_editTextChanged(const QString &arg1);

    void on_jianyanBianhaoComboBox_editTextChanged(const QString &arg1);

    void on_jianyanJianyanComboBox_editTextChanged(const QString &arg1);

    void on_jianyanBiaozhunComboBox_editTextChanged(const QString &arg1);

    void on_jianyanTianbiaoComboBox_editTextChanged(const QString &arg1);

    void on_jianyanReupdatepushButton_clicked();

    void on_jianyanResetPushButton_clicked();


    void on_reportTabWidget_tabBarClicked(int index);

    void on_bangcairibaobiaoPushButton_clicked();



    void on_bangcairibaobiaoBancicomboBox_editTextChanged(const QString &arg1);



    void on_bangcairibaobiaoPaihaoComboBox_editTextChanged(const QString &arg1);

    void on_bangcairibaobiaoSizeComboBox_editTextChanged(const QString &arg1);

    void on_bangcairibaobiaoChangduComboBox_editTextChanged(const QString &arg1);

    void on_bangcairibaobiaoPandingComboBox_editTextChanged(const QString &arg1);




    void on_bangcairibaobiaoReupdatePushButton_clicked();

    void on_bangcairibaobiaoResetPushButton_clicked();

    void on_gaoxianribaobiaoPinmingComboBox_editTextChanged(const QString &arg1);

    void on_gaoxianribaobiaoBancicomboBox_editTextChanged(const QString &arg1);

    void on_gaoxianribaobiaoPaihaoComboBox_editTextChanged(const QString &arg1);

    void on_gaoxianribaobiaoSizeComboBox_editTextChanged(const QString &arg1);

    void on_gaoxianribaobiaoChangduComboBox_editTextChanged(const QString &arg1);

    void on_gaoxianribaobiaoPandingComboBox_editTextChanged(const QString &arg1);


    void on_gaoxianribaobiaoPushButton_clicked();

    void on_gaoxianribaobiaoReupdatePushButton_clicked();

    void on_gaoxianribaobiaoResetPushButton_clicked();

    void on_pushButtonWarehouse_clicked();

private:
    bool db_setted = false; //是否设置过 数据库
    QSqlDatabase db;
    Ui::MainWindow *ui;

    QString jianyanUpdate();

    int depart = 0;

    void initjianyan();//初始化检验报告单
    void initbangcairibaobiao();//初始化棒材日报表
    QString bangcairibaobiaoUpdate();


    QString jianyanReupdate();
    QString bangcairibaobiaoReupdate();
    void initgaoxianribaobiao();
    QString gaoxianribaobiaoUpdate();

    QString gaoxianribaobiaoReupdate();

};
#endif // MAINWINDOW_H
