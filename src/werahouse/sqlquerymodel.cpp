#include "sqlquerymodel.h"
#include "QDebug"

void SqlQueryModel::setQuery(QSqlQuery query){
    QSqlQueryModel model;
    model.setQuery(query);
    this->insertColumns(0,model.columnCount());
    this->insertRows(0,model.rowCount());

    for(int i = 0;i < model.columnCount();i++){
        QString columnName1 = model.headerData(i, Qt::Horizontal, Qt::DisplayRole).toString();
        this->setHeaderData(i, Qt::Horizontal,columnName1);


    }

    for(int i = 0;i<model.rowCount();i++){
        for (int j = 0;j < model.columnCount();j++){
            QModelIndex index = model.index(i,j, QModelIndex());
            QModelIndex index_n = this->index(i,j, QModelIndex());
            this->setData(index_n, QVariant(model.data(index).toString()));
        }
    }


}


Qt::ItemFlags SqlQueryModel::flags(const QModelIndex &index)const{
    if(index.column()<8)
      return (QStandardItemModel::flags(index) & ~Qt::ItemIsEditable);
    return QStandardItemModel::flags(index);


}

