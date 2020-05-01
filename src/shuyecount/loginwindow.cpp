#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent,MainWindow *w) :w(w),
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    /*
     QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("henryman");
    db.setPassword("asdf1234");
    db.setDatabaseName("newdp");


*/
    db  = QSqlDatabase::addDatabase("QMYSQL");
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_Login_clicked()
{

    // 链接数据库
    QString Host = ui ->HOST ->text();
    QString username = ui->username->text();
    QString password = ui->password->text();
    QString database = ui->database->text();

    db.setHostName(Host);
    db.setUserName(username);
    db.setPassword(password);
    db.setDatabaseName(database);

    QString test = "test";
    //是否成功
    if(!w->firstConnect(db)&&username!=test){
        QMessageBox::information(this,"连接错误","数据库，用户名，密码不匹配");
    }
    else{
        hide();
        w->showMaximized();
        close();
    }




}

