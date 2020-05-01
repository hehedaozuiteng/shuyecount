#include "supporttool.h"



QString transdate(QDate a){

    QString year = QString::number(a.year());
    QString month =  QString::number(a.month());
    QString  day =   QString::number(a.day());
    return year+'.'+month+'.'+day;
}

QString transNull(QString a){
    if ((a == "")or(a== "..."))
        return "NULL";
    return a;

}
void comboxinti(QComboBox *a, QString comboboxname,int initlItemnum){
    //重设combox
    QSettings settings("config/config.ini",QSettings::IniFormat);

    while(a->count()>initlItemnum)
        a->removeItem(a->count()-1);

    int size = settings.beginReadArray(comboboxname);



    for(int i =0; i < size ;i++){
        settings.setArrayIndex(i);
        QString item = settings.value("term").toString();
        a->addItem(item);
    }

    settings.endArray();

    a->addItem("...");
}

 void renewcombobox(QComboBox *a,QString comboboxname){
     if (a->itemText(a->count()-1) != "..."){

     QSettings settings("config/config.ini",QSettings::IniFormat);
     QList<QString> lst ;
     int size = settings.beginReadArray(comboboxname);
     for(int i =0; i < size ;i++){
         settings.setArrayIndex(i);
          lst.append(settings.value("term").toString());
     }
     settings.endArray();

     lst.push_front(a->itemText(a->count()-1));
     if(size > 9){
         lst.pop_back();
     size = 9;
     }

     settings.beginWriteArray(comboboxname);
     for (int var = 0; var < size+1; ++var) {

         settings.setArrayIndex(var);
         settings.setValue("term", lst[var]);


     }
    settings.endArray();
    a->addItem("...");
    }

}

bool queryVerify(QLabel *succefulLabel, QTextBrowser *failBrower, QSqlQuery *sqlQuery){

    if(sqlQuery->isActive()){
        succefulLabel->show();
       failBrower->hide();
       return true;
    }else{

        int errorCode = sqlQuery->lastError().nativeErrorCode().toInt();
        if(1062 == errorCode ){

       failBrower->setText("上传失败 : 该炉批号或者轧制号已经存在\n如需修改数据请使用修改键 \n详细 : databaseText() "+sqlQuery->lastError().databaseText()+ "\n driverText()  " + sqlQuery->lastError().driverText()+ "\n nativeErrorCode()   "+ sqlQuery->lastError().nativeErrorCode());
        }
        else if(errorCode == 1048){
       failBrower->setText("上传失败 : 炉批号或轧制号为空\n如需修改数据请使用修改键 \n详细 : databaseText() "+sqlQuery->lastError().databaseText()+ "\n driverText()  " + sqlQuery->lastError().driverText()+ "\n nativeErrorCode()   "+ sqlQuery->lastError().nativeErrorCode());

        }
         else{
        failBrower->setText("上传失败 : 原因不明 \n 详细: databaseText() \n"+sqlQuery->lastError().databaseText()+ "\n driverText()  " + sqlQuery->lastError().driverText()+ "\n nativeErrorCode()   "+ sqlQuery->lastError().nativeErrorCode());
         }
       failBrower->show();
        succefulLabel->hide();
    }

    return false;

 }


bool IsItemExist(QString term, QString id,QString tablename, QSqlDatabase db){
    QSqlQuery query(db); //数据库选择
    QString input = "SELECT * FROM `"+tablename+"` WHERE `"+term+"`= " + id+";";

    //SELECT * FROM `chejian` WHERE `轧制号` = 1
    query.exec(input);
            while(query.next()){
                    return true;
            }
            return false;
}
