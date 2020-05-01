#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <mainwindow.h>
namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr,MainWindow *w = nullptr);
    MainWindow *w;
    ~loginWindow();


private slots:
    void on_Login_clicked();

private:
    Ui::loginWindow *ui;
    QSqlDatabase db;
    bool  connect;

};

#endif // LOGINWINDOW_H
