#include "werahouse.h"
#include "ui_werahouse.h"
#include "QDebug"


Werahouse::Werahouse(QSqlDatabase db,QString tablename,QString werahousename,QWidget *parent):
    QWidget(parent),
    ui(new Ui::Werahouse),db{db},tablename{tablename},werahousename{werahousename}
{
    ui->setupUi(this);
    if(db.open())
           qDebug() << "databese connect";
       else
           qDebug() << "nooooot connect";

    //ui->dateEdit->setDateTime( QDateTime::currentDateTime());

      QSettings settings("config/config.ini",QSettings::IniFormat);
      settings.value("werahouse/werahouse", "仓库名称");
      settings.value("werahouse/duoweihao", "垛位号");

   if(!settings.contains("werahouse/werahouse")){
       settings.setValue("werahouse/werahouse", "仓库名称");
       settings.setValue("werahouse/duoweihao", "垛位号");
   }



   //初始化
   model = new  SqlQueryModel(this);

   intiVector();// 重置仓库名称

   tableView = new QTableView(this);
   tableView->setGeometry(30,70,1570,840);

}

Werahouse::~Werahouse()
{
    delete ui;
}

void Werahouse::intiVector(){
    QSettings settings("config/config.ini",QSettings::IniFormat);
    QString werahouse =  settings.value("werahouse/werahouse", "仓库名称").toString();
    QString duowei = settings.value("werahouse/duoweihao", "垛位号").toString();
    QString queryforsize =  "SELECT COUNT(DISTINCT `"+werahouse+"`) FROM "+werahousename;
    QString queryforname =  "SELECT DISTINCT `"+werahouse+"` FROM "+werahousename;

    QSqlQuery query(db); //数据库选择

    query.exec(queryforsize);
    query.next();
    int size =  query.value(0).toInt();

    werahouseVector.resize(size);


    query.exec(queryforname);
    for(int i = 0;query.next();i++){
        werahouseVector[i].push_front(query.value(0).toString());
    }

// 填入垛位号

    for(int i = 0;i< werahouseVector.size();i++){
       QString queryforduowei =  "SELECT `"+duowei+"` FROM `"+werahousename+"` WHERE `"+werahouse+"` = '"+werahouseVector[i][0]+"'";
       query.exec(queryforduowei);
       while(query.next()){
       werahouseVector[i].push_back(query.value(0).toString());
       }

    }


}

void Werahouse::on_query_clicked()
{
    model->clear();
    QString data = transdate(ui->dateEdit->date());
    QString banci = transNull(ui->banci->currentText());

    QSqlQuery query(db); //数据库选择
    query.exec("DROP TABLE IF EXISTS temp_tb;");
    query.exec("CREATE TEMPORARY TABLE temp_tb SELECT * FROM `"+tablename+"` WHERE `日期` = '"+data+"' AND `班次` = '"+banci +"' ; ");
    query.exec("ALTER TABLE temp_tb DROP `上传日期`,DROP`日期`,DROP`班次`;");
    query.exec("SELECT * FROM temp_tb;");//多句sql要多句exec执行

    model->setQuery(query);


    model->insertColumns(8,2);
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("仓库"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("垛位号"));
    for (int row = 0;  row< model->rowCount(); ++row) {
       QModelIndex indexRow8 = model->index(row,8, QModelIndex());
       QModelIndex indexRow9 = model->index(row,9, QModelIndex());


       model->setData(indexRow8, QVariant("输入仓库"));
       model->setData(indexRow9, QVariant("输入垛位号"));

    }

    BoxDelegate *delegate = new BoxDelegate(werahouseVector);
    tableView->setItemDelegateForColumn(8,delegate);
    tableView->setItemDelegateForColumn(9,delegate);
    tableView->setEditTriggers(QAbstractItemView::CurrentChanged);



    tableView->setModel( model);


}




void Werahouse::on_updateButton_clicked()
{
    QString a =  "输入仓库";
    QString b = "输入垛位号";
    QVector<int> inputId;
    for(int i = 0;i < model->rowCount();i++){
        if  (!(model->item(i,8)->text() == a || model->item(i,9)->text() == b))
            inputId.push_back(i);
    }
    QMessageBox::StandardButton confirm;
    //确认是否有null 信息
    QString information = "总共 ";
    information.append(QString::number(inputId.size()));
    information+=" 个数据需要上传，总数据为 ： ";
    information.append(QString::number(model->rowCount()));


   confirm = QMessageBox::question(this,"是否上传数据",information,QMessageBox::Yes|QMessageBox::No);
   if(confirm == QMessageBox::Yes){//同意上传
       for (int i:inputId) {
            QString insert = "INSERT INTO `werahouse` (`轧制号`, `规格`, `牌号`, `品名`, `长度`, `重量`, `理级重量`, `判定`, `班次`, `仓库`, `垛位号`, `日期`, `上传日期`) VALUES (";
            insert += "'"+model->item(i,0)->text()+"', ";
            insert += "'"+model->item(i,1)->text()+"', ";
            insert += "'"+model->item(i,2)->text()+"', ";
            insert += "'"+model->item(i,3)->text()+"', ";
            insert += "'"+model->item(i,4)->text()+"', ";
            insert += "'"+model->item(i,5)->text()+"', ";
            insert += "'"+model->item(i,6)->text()+"', ";
            insert += "'"+model->item(i,7)->text()+"', ";
            insert += "'"+ui->banci->currentData().toString()+"', ";
            insert += "'"+model->item(i,8)->text()+"', ";
            insert += "'"+model->item(i,9)->text()+"', ";

            insert += "'"+transNull(transdate(ui->dateEdit->date()))+"', ";
            insert += "'"+transdate(QDateTime::currentDateTime().date())+"')";

            qDebug() << insert;
            //QSqlQuery query(db);
            //query.exec(insert);
       }
   }


    //INSERT INTO `werahouse` (`轧制号`, `规格`, `牌号`, `品名`, `长度`, `重量`, `理级重量`, `判定`, `班次`, `仓库`, `垛位号`, `日期`, `上传日期`) VALUES ('1', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '', '', NULL, NULL);

}
