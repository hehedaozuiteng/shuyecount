#ifndef WERAHOUSE_H
#define WERAHOUSE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QSettings>
#include <QVector>
#include <QSqlQuery>
#include <QSqlError>
#include <QComboBox>
#include "supporttool.h"
#include <QSqlQueryModel>
#include "sqlquerymodel.h"
#include <QSqlRecord>
#include <QLabel>
#include <QTableView>
#include "boxdelegate.h"

#if defined(WERAHOUSE_LIBRARY)
#  define WERAHOUSE_EXPORT Q_DECL_EXPORT
#else
#  define WERAHOUSE_EXPORT Q_DECL_IMPORT
#endif


namespace Ui {
class Werahouse;
}

class Werahouse : public QWidget
{
    Q_OBJECT

public:
    explicit Werahouse(QSqlDatabase db,QString tablename,QString werahousename,QWidget *parent = nullptr);
    ~Werahouse();


private slots:
    void on_query_clicked();



    void on_updateButton_clicked();

private:
    Ui::Werahouse *ui;


    int page = 0;
    int RowPerPage = 20;
    bool fullpage = false;



    QSqlDatabase db;
    QString tablename;
    QString werahousename;
    QVector<QVector <QString>> werahouseVector;
    QTableView *tableView;
    SqlQueryModel *model;
    void intiVector();
};

#endif // WERAHOUSE_H
