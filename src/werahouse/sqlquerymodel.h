#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H

#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlQuery>



class SqlQueryModel : public QStandardItemModel
{
    Q_OBJECT
public:
    SqlQueryModel(QObject *parent = 0):QStandardItemModel(parent){};
    void setQuery(QSqlQuery query);

    Qt::ItemFlags flags(const QModelIndex &index) const override;
};

#endif // SQLQUERYMODEL_H
