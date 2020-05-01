#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpushbutton.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

bool MainWindow::firstConnect(QSqlDatabase testDb)
{
    Werahouse *a = new Werahouse(db,"temp_werahouse","werahousename",ui->warehouse);
    if(!db_setted){
        if(testDb.open()){
        db_setted = true;
        db = testDb;

        return true;
     }
    else {
        return false;
        }
    }
    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Old size:" << event->oldSize() << ", New size:" << event->size();
    qDebug() << ui->centralwidget->size();

}
*/



void MainWindow::on_pushButtonMainPage_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);//回到首页
}

void MainWindow::on_sqlquary_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);//开启sql查询
}


//=========================================================================================
//======================================================================================
//sql 查询页面组块

void MainWindow::on_generalQueryPushButton_clicked()
{
    qDebug() << "按键输入" <<ui->generalQueryTextEdit->toPlainText();
    QSqlQuery query(db); //数据库选择
    query.exec(ui->generalQueryTextEdit->toPlainText());
    QSqlQueryModel *model = new  QSqlQueryModel(this);
    model ->setQuery(query);
    ui->generalQueryTableView->setModel(model);

}

/*
      query example
      QSqlQuery query;
      "SELECT id, name, age, gender, married FROM employee");
        QSqlQueryModel *model = new  QSqlQueryModel();
        model ->setQuery(query);
       // model->removeColumns(1,3);
       ui->tableView->setModel(model);

*/

void MainWindow::on_generalQueryPushButtonClean_clicked()
{
    ui->generalQueryTextEdit->clear() ;
}

void MainWindow::on_generalQueryPushButtonPaste_clicked()
{
     ui->generalQueryTextEdit->paste();
}

void MainWindow::on_generalQueryPushButtonCopy_clicked()
{
    ui->generalQueryTextEdit->selectAll();
     ui->generalQueryTextEdit->copy();
     QTextCursor cursor = ui->generalQueryTextEdit->textCursor();
     cursor.movePosition( QTextCursor::End );
     ui->generalQueryTextEdit->setTextCursor( cursor );
}

//sql 查询页面组块
//========================================================================================
//=========================================================================================
//小工具模块
//简化流程


//确认表格tablename 中的列 term name中 是否有为 id的值



//=========================================================================================
//========================================================================================
//报告模块

//===========================================================================
//报告模块总设置
void MainWindow::on_pushButtonReports_clicked()// 点击报告单按钮
{

    ui->stackedWidget->setCurrentIndex(2);//开启报告表 页面
    ui->reportTabWidget->setCurrentIndex(0);

}

void MainWindow::on_reportTabWidget_tabBarClicked(int index)
{
    if(index == 1){//初始化检验报告单
        initjianyan();
    }else if(index == 2){
        initbangcairibaobiao();
    }
    else if(index == 3){
        initgaoxianribaobiao();
    }

}
//报告模块总设置
//=========================================================================



//=========================================================================
//实验报表页面组块

void MainWindow::initjianyan(){



    //设置自动时间
    ui->jianyanDateTimeEdit->setDateTime( QDateTime::currentDateTime());


    //重置 组合框项目

    comboxinti(ui->jianyanPaihaoComboBox,"jianyanPaihaoComboBox");
    comboxinti(ui->jianyanBianhaoComboBox,"jianyanBianhaoComboBox");
    comboxinti(ui->jianyanSizeComboBox,"jianyanSizeComboBox",2);
    comboxinti(ui->jianyanJianyanComboBox,"jianyanJianyanComboBox");
    comboxinti(ui->jianyanTianbiaoComboBox,"jianyanTianbiaoComboBox");
    comboxinti(ui->jianyanBiaozhunComboBox,"jianyanBiaozhunComboBox",1);

    //重置 文字框

    ui->jianyanLPHLineEdit->setText("");
    ui->jianyanCLineEdit->setText("");
    ui->jianyanSiLineEdit->setText("");
    ui->jianyanMnLineEdit->setText("");
    ui->jianyanPLineEdit->setText("");
    ui->jianyanSLineEdit->setText("");
    ui->jianyanVLineEdit->setText("");
    ui->jianyanNbLineEdit->setText("");
    ui->jianyanCeqLineEdit->setText("");
    ui->jianyanRelULineEdit->setText("");
    ui->jianyanRelDLineEdit->setText("");
    ui->jianyanRmULineEdit->setText("");
    ui->jianyanRmDLineEdit->setText("");
    ui->jianyanApercenULineEdit->setText("");
    ui->jianyanApercenDLineEdit->setText("");
    ui->jianyanAgtULineEdit->setText("");
    ui->jianyanAgtDLineEdit->setText("");
    ui->jianyanRomroelULineEdit->setText("");
    ui->jianyanRomroelDLineEdit->setText("");
    ui->jianyanRoelrelULineEdit->setText("");
    ui->jianyanRoelrelDLineEdit->setText("");
    ui->jianyanZhongliangLineEdit->setText("");
    ui->jianyanLenwanCheckBox->setChecked(true);
    ui->jianyanFanwanCheckBox->setChecked(true);
    ui->jianyanPandinCheckBox->setChecked(false);





    //判定权限
    if(true){

        ui->jianyanUpdatePushButton->setDisabled(false);
    }

    //上传成功或者失败label
    ui->jianyanSuccessLabel->hide();
    ui->jianyanFailtextBrowser->hide();

}




QString MainWindow::jianyanUpdate(){

    //date 是日期
    //命名规则： 三字以上是简拼，两字以下是全拼。 zzh是轧制号。 命名标准以mysql的列名(column name)为准
    QString date = transNull(transdate(ui->jianyanDateTimeEdit->date()));


    QString lph = transNull(ui->jianyanLPHLineEdit->text());
    QString C = transNull(ui->jianyanCLineEdit->text());
    QString Si = transNull(ui->jianyanSiLineEdit->text());
    QString Mn = transNull(ui->jianyanMnLineEdit->text());
    QString P = transNull(ui->jianyanPLineEdit->text());
    QString S = transNull(ui->jianyanSLineEdit->text());
    QString V = transNull(ui->jianyanVLineEdit->text());
    QString Nb = transNull(ui->jianyanNbLineEdit->text());
    QString Ceq = transNull(ui->jianyanCeqLineEdit->text());


    QString Rel_upp = transNull(ui->jianyanRelULineEdit->text());
    QString Rel_low = transNull(ui->jianyanRelDLineEdit->text());
    QString Rm_upp = transNull(ui->jianyanRmULineEdit->text());
    QString Rm_low = transNull(ui->jianyanRmDLineEdit->text());
    QString A_hi = transNull(ui->jianyanApercenULineEdit->text());
    QString A_lo = transNull(ui->jianyanApercenDLineEdit->text());
    QString Agt_hi = transNull(ui->jianyanAgtULineEdit->text());
    QString Agt_lo = transNull(ui->jianyanAgtDLineEdit->text());

    QString Rom_Roel_h = transNull(ui->jianyanRomroelULineEdit->text());
    QString Rom_Roel_l = transNull(ui->jianyanRomroelDLineEdit->text());
    QString Roel_Rel_h = transNull(ui->jianyanRoelrelULineEdit->text());
    QString Roel_Rel_l = transNull(ui->jianyanRoelrelDLineEdit->text());

    QString zlpc = transNull(ui->jianyanZhongliangLineEdit->text());


    //冷弯，反弯，和判定结果是 “合格” 和 “不合格”
     QString lenwan;
     QString fanwan;
     QString pdjg;
    if(ui->jianyanLenwanCheckBox->isChecked()){
        lenwan = "合格";
    }else{
        lenwan ="不合格";
    }

    if(ui->jianyanFanwanCheckBox->isChecked()){
        fanwan = "合格";
    }
    else{
        fanwan = "合格";
    }

    if(ui->jianyanPandinCheckBox->isChecked()){
        pdjg = "合格";
    }
    else{
        pdjg = "合格";
    }


    QString bianhao = transNull(ui->jianyanBianhaoComboBox->currentText());
    QString paihao = transNull(ui->jianyanPaihaoComboBox->currentText());
    QString guige = transNull(ui->jianyanSizeComboBox->currentText());
    QString biaozhun = transNull(ui->jianyanBiaozhunComboBox->currentText());

    QString jianyan = transNull(ui->jianyanJianyanComboBox->currentText());
    QString tianbiao = transNull(ui->jianyanTianbiaoComboBox->currentText());

    QString update = "INSERT INTO `lab` (`炉批号`, `C`, `Si`, `Mn`, `P`, `S`, `V`, `Nb`, `Ceq`, `Rel_upp`, `Rel_low`, `Rm_upp`, `Rm_low`, `A_hi`, `A_lo`, `Agt_hi`, `Agt_lo`,";
    update += "`Rom_RoeL_h`, `Rom_RoeL_l`, `RoeL_ReL_h`, `RoeL_ReL_l`, `重量偏差`, `冷弯`, `反弯`, `判定结果`, `编号`, `标准`, `牌号`, `规格（Φ/mm）`, `日期`, `检验`, `填表`,`上传日期`)";
    update += "VALUES ('"+lph+"','"+C+"','"+Si+"','"+Mn+"','"+P+"','"+S+"','"+V+"','"+Nb+"','"+Ceq+"','"+Rel_upp+"','"+Rel_low+"','"+Rm_upp+"','"+Rm_low+"','"+A_hi+"','"+A_lo+"','"+Agt_hi+"','"+Agt_lo;
    update += "','"+Rom_Roel_h+"','"+Rom_Roel_l+"','"+Roel_Rel_h+"','"+Roel_Rel_l+"','"+zlpc+"','"+lenwan+"','"+fanwan+"','"+pdjg+"','"+bianhao+"','"+biaozhun+"','"+paihao+"','"+guige+"','"+date+"','"+jianyan+"','"+tianbiao+"','"+transdate(QDateTime::currentDateTime().date())+"');";
    /*
    INSERT INTO `lab` (`轧制号`, `C`, `Si`, `Mn`, `P`, `S`, `V`, `Nb`, `Ceq`, `Rel_upp`, `Rel_low`, `Rm_upp`, `Rm_low`, `A_hi`, `A_lo`, `Agt_hi`, `Agt_lo`,
`Rom_RoeL_h`, `Rom_RoeL_l`, `RoeL_ReL_h`, `RoeL_ReL_l`, `重量偏差`, `冷弯`, `反弯`, `判定结果`, `编号`, `标准`, `牌号`, `规格（Φ/mm）`, `日期`, `检验`, `填表`,`上传日期`)
VALUES (NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '12');


*/
    update.replace("'NULL'","NULL");
    return update;

}

//上传按钮
void MainWindow::on_jianyanUpdatePushButton_clicked()
{

    QString update = jianyanUpdate();
    QMessageBox::StandardButton confirm;
    //确认是否有null 信息
   if(update.contains("NULL")){
        confirm = QMessageBox::warning(this,"数据有缺","是否上传数据",QMessageBox::Yes|QMessageBox::No);
   }else{
         confirm = QMessageBox::question(this,"数据完整","是否上传数据",QMessageBox::Yes|QMessageBox::No);
   }


   if(confirm == QMessageBox::Yes){//同意上传
       qDebug() << update;
       QSqlQuery query(db); //数据库选择
       query.exec(update);

       //更新组合框内容
       renewcombobox(ui->jianyanPaihaoComboBox,"jianyanPaihaoComboBox");
       renewcombobox(ui->jianyanBianhaoComboBox,"jianyanBianhaoComboBox");
       renewcombobox(ui->jianyanSizeComboBox,"jianyanSizeComboBox");
       renewcombobox(ui->jianyanJianyanComboBox,"jianyanJianyanComboBox");
       renewcombobox(ui->jianyanTianbiaoComboBox,"jianyanTianbiaoComboBox");
       renewcombobox(ui->jianyanBiaozhunComboBox,"jianyanBiaozhunComboBox");


       ui->jianyanSuccessLabel->setText("炉批号 : "+ui->jianyanLPHLineEdit->text()+"  上传成功 (´・ω・`) ");
       queryVerify(ui->jianyanSuccessLabel,ui->jianyanFailtextBrowser,&query);





   }




}


//mysql 查询信息

QString MainWindow::jianyanReupdate(){

    //date 是日期
    //命名规则： 三字以上是简拼，两字以下是全拼。 zzh是轧制号。 命名标准以mysql的列名(column name)为准


    QString date = transNull(transdate(ui->jianyanDateTimeEdit->date()));


    QString lph = transNull(ui->jianyanLPHLineEdit->text());
    QString C = transNull(ui->jianyanCLineEdit->text());
    QString Si = transNull(ui->jianyanSiLineEdit->text());
    QString Mn = transNull(ui->jianyanMnLineEdit->text());
    QString P = transNull(ui->jianyanPLineEdit->text());
    QString S = transNull(ui->jianyanSLineEdit->text());
    QString V = transNull(ui->jianyanVLineEdit->text());
    QString Nb = transNull(ui->jianyanNbLineEdit->text());
    QString Ceq = transNull(ui->jianyanCeqLineEdit->text());


    QString Rel_upp = transNull(ui->jianyanRelULineEdit->text());
    QString Rel_low = transNull(ui->jianyanRelDLineEdit->text());
    QString Rm_upp = transNull(ui->jianyanRmULineEdit->text());
    QString Rm_low = transNull(ui->jianyanRmDLineEdit->text());
    QString A_hi = transNull(ui->jianyanApercenULineEdit->text());
    QString A_lo = transNull(ui->jianyanApercenDLineEdit->text());
    QString Agt_hi = transNull(ui->jianyanAgtULineEdit->text());
    QString Agt_lo = transNull(ui->jianyanAgtDLineEdit->text());

    QString Rom_Roel_h = transNull(ui->jianyanRomroelULineEdit->text());
    QString Rom_Roel_l = transNull(ui->jianyanRomroelDLineEdit->text());
    QString Roel_Rel_h = transNull(ui->jianyanRoelrelULineEdit->text());
    QString Roel_Rel_l = transNull(ui->jianyanRoelrelDLineEdit->text());

    QString zlpc = transNull(ui->jianyanZhongliangLineEdit->text());


    //冷弯，反弯，和判定结果是 “合格” 和 “不合格”
     QString lenwan;
     QString fanwan;
     QString pdjg;
    if(ui->jianyanLenwanCheckBox->isChecked()){
        lenwan = "合格";
    }else{
        lenwan ="不合格";
    }

    if(ui->jianyanFanwanCheckBox->isChecked()){
        fanwan = "合格";
    }
    else{
        fanwan = "合格";
    }

    if(ui->jianyanPandinCheckBox->isChecked()){
        pdjg = "合格";
    }
    else{
        pdjg = "合格";
    }


    QString bianhao = transNull(ui->jianyanBianhaoComboBox->currentText());
    QString paihao = transNull(ui->jianyanPaihaoComboBox->currentText());
    QString guige = transNull(ui->jianyanSizeComboBox->currentText());
    QString biaozhun = transNull(ui->jianyanBiaozhunComboBox->currentText());

    QString jianyan = transNull(ui->jianyanJianyanComboBox->currentText());
    QString tianbiao = transNull(ui->jianyanTianbiaoComboBox->currentText());


    QString update = " UPDATE `lab` SET";
    if(C!="NULL"){
        update += "`C`= '"+C+"',";
    }
    if(Si!="NULL"){
        update += "`Si`= '"+Si+"',";
    }
    if(Mn!="NULL"){
        update += "`Mn`= '"+Mn+"',";
    }
    if(P!="NULL"){
        update += "`P`= '"+P+"',";
    }
    if(S!="NULL"){
        update += "`S`= '"+S+"',";
    }
    if(Ceq!="NULL"){
        update += "`Ceq`=  '"+Ceq+"',";
    }
    if(V!="NULL"){
        update += "`V`= '"+V+"',";
    }
    if(Nb!="NULL"){
        update += "`Nb`= '"+Nb+"',";
    }
    if(Rel_upp!="NULL"){
        update += "`Rel_upp`=  '"+Rel_upp+"',";
    }
    if(Rel_low!="NULL"){
        update += "`Rel_low`= '"+Rel_low+"',";
    }
    if(Rm_upp!="NULL"){
        update += "`Rm_upp`= '"+Rm_upp+"',";
    }
    if(Rm_low!="NULL"){
        update += "`Rm_low`= '"+Rm_low+"',";
    }
    if(A_hi!="NULL"){
        update += "`A_hi`= '"+A_hi+"',";
    }
    if(A_lo!="NULL"){
        update += "`A_lo`= '"+A_lo+"',";
    }
    if(Agt_hi!="NULL"){
        update += "`Agt_hi`= '"+Agt_hi+"',";
    }
    if(Agt_lo!="NULL"){
        update += "`Agt_lo`= '"+Agt_lo+"',";
    }
    if(Rom_Roel_h!="NULL"){
        update += "`Rom_RoeL_h`= '"+Rom_Roel_h+"',";
    }
    if(Rom_Roel_l!="NULL"){
        update += "`Rom_RoeL_l`= '"+Rom_Roel_l+"',";
    }
    if(Roel_Rel_h!="NULL"){
        update += "`RoeL_ReL_h`= '"+Roel_Rel_h+"',";
    }
    if(Rom_Roel_l!="NULL"){
        update += "`RoeL_ReL_l`= '"+Rom_Roel_l+"',";
    }
    if(zlpc!="NULL"){
        update += "`重量偏差`= '"+zlpc+"',";
    }

        update += "`冷弯`= '"+lenwan+"',";
        update += "`反弯`= '"+fanwan+"',";
        update += "`判定结果`= '"+pdjg+"',";

    if(bianhao!="NULL"){
        update += "`编号`= '"+bianhao+"',";
    }
    if(biaozhun!="NULL"){
        update += "`标准`= '"+biaozhun+"',";
    }
    if(paihao!="NULL"){
        update += "`牌号`= '"+paihao+"',";
    }
    if(guige!= "NULL"){
        update += "`规格（Φ/mm）`= '"+guige+"',";
    }
    if(date!= "NULL"){
         update += "`日期`= '"+date+"',";
    }
    if(jianyan!= "NULL"){
         update += "`检验`= '"+jianyan+"',";
    }
    if(tianbiao!= "NULL"){
         update += "`填表`= '"+tianbiao+"',";
    }
    update += "`上传日期`= '"+transdate(QDateTime::currentDateTime().date())+"' ";
    update += " WHERE `炉批号` =  '"+lph+"';";




 /*
 UPDATE `lab` SET `炉批号`=[value-1],`C`=[value-2],`Si`=[value-3],`Mn`=[value-4],`P`=[value-5],`S`=[value-6],`V`=[value-7],`Nb`=[value-8],
`Ceq`=[value-9],`Rel_upp`=[value-10],`Rel_low`=[value-11],`Rm_upp`=[value-12],`Rm_low`=[value-13],`A_hi`=[value-14],`A_lo`=[value-15],
`Agt_hi`=[value-16],`Agt_lo`=[value-17],`Rom_RoeL_h`=[value-18],`Rom_RoeL_l`=[value-19],`RoeL_ReL_h`=[value-20],`RoeL_ReL_l`=[value-21],
`重量偏差`=[value-22],`冷弯`=[value-23],`反弯`=[value-24],`判定结果`=[value-25],`编号`=[value-26],`标准`=[value-27],`牌号`=[value-28],
`规格（Φ/mm）`=[value-29],`日期`=[value-30],`检验`=[value-31],`填表`=[value-32],`上传日期`=[value-33] WHERE 1
*/

    return update;


}


//修改按钮

void MainWindow::on_jianyanReupdatepushButton_clicked()
{

   if(ui->jianyanLPHLineEdit->text().compare("")==0){
        ui->jianyanFailtextBrowser->setText("无法修改，炉批号为空");
        ui->jianyanSuccessLabel->hide();
        ui->jianyanFailtextBrowser->show();
        return;


    }else if(!IsItemExist("炉批号",ui->jianyanLPHLineEdit->text(),"lab",db)){

        ui->jianyanFailtextBrowser->setText("无法修改，该炉批号不存在");
        ui->jianyanSuccessLabel->hide();
        ui->jianyanFailtextBrowser->show();
        return;
   }



   QMessageBox::StandardButton confirm;

   confirm = QMessageBox::question(this,"数据修改","是否修改信息",QMessageBox::Yes|QMessageBox::No);

  if(confirm == QMessageBox::Yes){//同意上传

   QString update = jianyanReupdate();

   QSqlQuery query(db); //数据库选择

   query.exec(update);

   qDebug() << update;


   renewcombobox(ui->jianyanPaihaoComboBox,"jianyanPaihaoComboBox");
   renewcombobox(ui->jianyanBianhaoComboBox,"jianyanBianhaoComboBox");
   renewcombobox(ui->jianyanSizeComboBox,"jianyanSizeComboBox");
   renewcombobox(ui->jianyanJianyanComboBox,"jianyanJianyanComboBox");
   renewcombobox(ui->jianyanTianbiaoComboBox,"jianyanTianbiaoComboBox");
   renewcombobox(ui->jianyanBiaozhunComboBox,"jianyanBiaozhunComboBox");


   ui->jianyanSuccessLabel->setText("炉批号 : "+ui->jianyanLPHLineEdit->text()+" 修改成功 (´・ω・`) ");
   queryVerify(ui->jianyanSuccessLabel,ui->jianyanFailtextBrowser,&query);
   }

}


void MainWindow::on_jianyanResetPushButton_clicked()
{
    initjianyan();
}


//使组合框可以记录自己的内容
void MainWindow::on_jianyanSizeComboBox_editTextChanged(const QString &arg1)
{
     ui->jianyanSizeComboBox->setItemText(ui->jianyanSizeComboBox->currentIndex(),arg1);
}

void MainWindow::on_jianyanPaihaoComboBox_editTextChanged(const QString &arg1)
{
    ui->jianyanPaihaoComboBox->setItemText(ui->jianyanPaihaoComboBox->currentIndex(),arg1);
}

void MainWindow::on_jianyanBianhaoComboBox_editTextChanged(const QString &arg1)
{
     ui->jianyanBianhaoComboBox->setItemText(ui->jianyanBianhaoComboBox->currentIndex(),arg1);
}

void MainWindow::on_jianyanJianyanComboBox_editTextChanged(const QString &arg1)
{
    ui->jianyanJianyanComboBox->setItemText(ui->jianyanJianyanComboBox->currentIndex(),arg1);
}

void MainWindow::on_jianyanBiaozhunComboBox_editTextChanged(const QString &arg1)
{
     ui->jianyanBiaozhunComboBox->setItemText(ui->jianyanBiaozhunComboBox->currentIndex(),arg1);
}

void MainWindow::on_jianyanTianbiaoComboBox_editTextChanged(const QString &arg1)
{
    ui->jianyanTianbiaoComboBox->setItemText(ui->jianyanTianbiaoComboBox->currentIndex(),arg1);
}


//========================================================================================

//======================================================================================
//棒材日报表模块
void MainWindow::initbangcairibaobiao(){

     //设置自动时间
     ui->bangcairibaoDateEdit->setDateTime( QDateTime::currentDateTime() );

    //重置 组合框项目
     comboxinti(ui->bangcairibaobiaoBancicomboBox,"bangcairibaobiaoBancicomboBox",3);
     comboxinti(ui->bangcairibaobiaoPaihaoComboBox,"bangcairibaobiaoPaihaoComboBox");
     comboxinti(ui->bangcairibaobiaoSizeComboBox,"bangcairibaobiaoSizeComboBox",2);
     comboxinti(ui->bangcairibaobiaoChangduComboBox,"bangcairibaobiaoChangduComboBox",1);
     comboxinti(ui->bangcairibaobiaoPandingComboBox,"bangcairibaobiaoPandingComboBox",2);
    //comboxinti(ui->bangcairibaobiaoPinmingComboBox,"bangcairibaobiaoPinmingComboBox",1);

    //重置输出栏
     ui->bangcairibaobiaoZZHLineEdit->setText("");
     ui->bangcairibaobiaoHLZLLineEdit->setText("");
     ui->bangcairibaobiaozhongliangLineEdit->setText("");


     //判定权限
     if(true){

         ui->bangcairibaobiaoPushButton->setDisabled(false);
     }


     //隐藏提示
     //上传成功或者失败label
     ui->bangcairibaobiaoSuccessLabel->hide();
     ui->bangcairibaobiaoFailTextBrowser->hide();
}


QString MainWindow::bangcairibaobiaoUpdate(){

    QString date = transNull(transdate(ui->bangcairibaoDateEdit->date()));

    QString guige = transNull(ui->bangcairibaobiaoSizeComboBox->currentText());

    QString paihao = transNull(ui->bangcairibaobiaoPaihaoComboBox->currentText());
    QString changdu = transNull(ui->bangcairibaobiaoChangduComboBox->currentText());
    QString zzh = transNull(ui->bangcairibaobiaoZZHLineEdit->text());
    QString zhongliang = transNull(ui->bangcairibaobiaozhongliangLineEdit->text());


    QString pangdin = transNull(ui->bangcairibaobiaoPandingComboBox->currentText());

    QString banci = transNull(ui->bangcairibaobiaoBancicomboBox->currentText());
    QString pinming = transNull(ui->bangcairibaobiaoPinmingComboBox->currentText());

     QString HLZL = transNull(ui->bangcairibaobiaoHLZLLineEdit->text());// should changed this one for 理级重量

    QString update = "INSERT INTO `chejian` (`轧制号`, `规格`, `牌号`, `品名`, `长度`, `重量`, `理级重量`, `判定`, `班次`, `日期`, `上传日期`) ";
    update += "VALUES ('"+zzh+"','"+guige+"','"+paihao+"','"+pinming+"','"+changdu+"','"+zhongliang+"','"+HLZL+"','"+pangdin;
    update +="','"+banci+"','"+date+"','"+transdate(QDateTime::currentDateTime().date())+"');";
  /*

INSERT INTO `chejian` (`炉批号`, `规格`, `牌号`, `品名`, `长度`, `重量`, `理级重量`, `判定`, `班次`, `日期`, `上传日期`) VALUES ('1', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);


*/

    update.replace("'NULL'","NULL");
    return update;

}



void MainWindow::on_bangcairibaobiaoPushButton_clicked() //上传按钮
{
    QString update = bangcairibaobiaoUpdate();
    QMessageBox::StandardButton confirm;
    //确认是否有null 信息
   if(update.contains("NULL")){
        confirm = QMessageBox::warning(this,"数据有缺","是否上传数据",QMessageBox::Yes|QMessageBox::No);
   }else{
         confirm = QMessageBox::question(this,"数据完整","是否上传数据",QMessageBox::Yes|QMessageBox::No);
   }


   if(confirm == QMessageBox::Yes){//同意上传
       qDebug() << update;

       QSqlQuery query(db);//数据库选择
       query.exec(update);

       //更新组合框内容

       renewcombobox(ui->bangcairibaobiaoBancicomboBox,"bangcairibaobiaoBancicomboBox");

       renewcombobox(ui->bangcairibaobiaoPaihaoComboBox,"bangcairibaobiaoPaihaoComboBox");
       renewcombobox(ui->bangcairibaobiaoSizeComboBox,"bangcairibaobiaoSizeComboBox");
       renewcombobox(ui->bangcairibaobiaoChangduComboBox,"bangcairibaobiaoChangduComboBox");
       renewcombobox(ui->bangcairibaobiaoPandingComboBox,"bangcairibaobiaoPandingComboBox");
      // renewcombobox(ui->bangcairibaobiaoPinmingComboBox,"bangcairibaobiaoPinmingComboBox");


        ui->bangcairibaobiaoSuccessLabel->setText("轧制号 : "+ui->bangcairibaobiaoZZHLineEdit->text()+" 上传成功 (´・ω・`) ");
        queryVerify(ui->bangcairibaobiaoSuccessLabel,ui->bangcairibaobiaoFailTextBrowser,&query);


   }
}



QString MainWindow::bangcairibaobiaoReupdate(){


     QString date = transNull(transdate(ui->bangcairibaoDateEdit->date()));

     QString guige = transNull(ui->bangcairibaobiaoSizeComboBox->currentText());

     QString paihao = transNull(ui->bangcairibaobiaoPaihaoComboBox->currentText());
     QString changdu = transNull(ui->bangcairibaobiaoChangduComboBox->currentText());
     QString zzh = transNull(ui->bangcairibaobiaoZZHLineEdit->text());
     QString zhongliang = transNull(ui->bangcairibaobiaozhongliangLineEdit->text());


     QString pangdin = transNull(ui->bangcairibaobiaoPandingComboBox->currentText());

     QString banci = transNull(ui->bangcairibaobiaoBancicomboBox->currentText());
     QString pinming = transNull(ui->bangcairibaobiaoPinmingComboBox->currentText());

      QString HLZL = transNull(ui->bangcairibaobiaoHLZLLineEdit->text());// should changed this one for 理级重量
      QString update = " UPDATE `chejian` SET";
      if(guige!="NULL"){
          update += "`规格`= '"+guige+"',";
      }
      if(paihao!="NULL"){
          update += "`牌号`= '"+paihao+"',";
      }
      if(pinming!="NULL"){
          update += "`品名`= '"+pinming+"',";
      }
      if(changdu!="NULL"){
          update += "`长度`= '"+changdu+"',";
      }
      if(zhongliang!="NULL"){
          update += "`重量`= '"+zhongliang+"',";
      }
      if(HLZL!="NULL"){
          update += "`理级重量`= '"+HLZL+"',";
      }
      if(pangdin!="NULL"){
          update += "`判定`= '"+pangdin+"',";
      }
      if(banci!="NULL"){
          update += "`班次`= '"+banci+"',";
      }
      if(date!="NULL"){
          update += "`日期`= '"+date+"',";
      }


      /*

      UPDATE `chejian` SET `轧制号`=[value-1],`规格`=[value-2],`牌号`=[value-3],`品名`=[value-4],`长度`=[value-5],`重量`=[value-6],`理级重量`=[value-7],`判定`=[value-8],`班次`=[value-9],`日期`=[value-10],`上传日期`=[value-11] WHERE 1

      */

     update += "`上传日期`= '"+transdate(QDateTime::currentDateTime().date())+"' ";
     update += " WHERE `轧制号` =  '"+zzh+"';";


      return update;

}



void MainWindow::on_bangcairibaobiaoReupdatePushButton_clicked()//修改按钮
{
    if(ui->bangcairibaobiaoZZHLineEdit->text().compare("")==0){
         ui->bangcairibaobiaoFailTextBrowser->setText("无法修改，轧制号为空");
         ui->bangcairibaobiaoSuccessLabel->hide();
         ui->bangcairibaobiaoFailTextBrowser->show();
         return;


     }else if(!IsItemExist("轧制号",ui->bangcairibaobiaoZZHLineEdit->text(),"chejian",db)){

         ui->bangcairibaobiaoFailTextBrowser->setText("无法修改，该轧制号不存在");
         ui->bangcairibaobiaoSuccessLabel->hide();
         ui->bangcairibaobiaoFailTextBrowser->show();
         return;
    }



    QMessageBox::StandardButton confirm;

    confirm = QMessageBox::question(this,"数据修改","是否修改信息",QMessageBox::Yes|QMessageBox::No);

   if(confirm == QMessageBox::Yes){//同意上传
    QString update = bangcairibaobiaoReupdate();
    QSqlQuery query(db); //数据库选择
    query.exec(update);
    qDebug() << update;


    renewcombobox(ui->bangcairibaobiaoBancicomboBox,"bangcairibaobiaoBancicomboBox");
    renewcombobox(ui->bangcairibaobiaoPaihaoComboBox,"bangcairibaobiaoPaihaoComboBox");
    renewcombobox(ui->bangcairibaobiaoSizeComboBox,"bangcairibaobiaoSizeComboBox");
    renewcombobox(ui->bangcairibaobiaoChangduComboBox,"bangcairibaobiaoChangduComboBox");
    renewcombobox(ui->bangcairibaobiaoPandingComboBox,"bangcairibaobiaoPandingComboBox");
   // renewcombobox(ui->bangcairibaobiaoPinmingComboBox,"bangcairibaobiaoPinmingComboBox");

    ui->bangcairibaobiaoSuccessLabel->setText("轧制号 : "+ui->bangcairibaobiaoZZHLineEdit->text()+" 修改成功 (´・ω・`) ");
    queryVerify(ui->bangcairibaobiaoSuccessLabel,ui->bangcairibaobiaoFailTextBrowser,&query);
   }



}


//重置按钮
void MainWindow::on_bangcairibaobiaoResetPushButton_clicked()
{
    initbangcairibaobiao();
}


//使组合框可以记录自己的内容
void MainWindow::on_bangcairibaobiaoBancicomboBox_editTextChanged(const QString &arg1)
{
    ui->bangcairibaobiaoBancicomboBox->setItemText(ui->bangcairibaobiaoBancicomboBox->currentIndex(),arg1);
}


void MainWindow::on_bangcairibaobiaoPaihaoComboBox_editTextChanged(const QString &arg1)
{
    ui->bangcairibaobiaoPaihaoComboBox->setItemText(ui->bangcairibaobiaoPaihaoComboBox->currentIndex(),arg1);
}

void MainWindow::on_bangcairibaobiaoSizeComboBox_editTextChanged(const QString &arg1)
{
    ui->bangcairibaobiaoSizeComboBox->setItemText(ui->bangcairibaobiaoSizeComboBox->currentIndex(),arg1);
}

void MainWindow::on_bangcairibaobiaoChangduComboBox_editTextChanged(const QString &arg1)
{
    ui->bangcairibaobiaoChangduComboBox->setItemText(ui->bangcairibaobiaoChangduComboBox->currentIndex(),arg1);
}

void MainWindow::on_bangcairibaobiaoPandingComboBox_editTextChanged(const QString &arg1)
{
    ui->bangcairibaobiaoPandingComboBox->setItemText(ui->bangcairibaobiaoPandingComboBox->currentIndex(),arg1);
}

//========================================================================================

//======================================================================================
//高线日报表模块

void MainWindow::initgaoxianribaobiao(){

     //设置自动时间
     ui->gaoxianribaoDateEdit->setDateTime( QDateTime::currentDateTime() );

    //重置 组合框项目
     comboxinti(ui->gaoxianribaobiaoBancicomboBox,"gaoxianribaobiaoBancicomboBox",3);
     comboxinti(ui->gaoxianribaobiaoPaihaoComboBox,"gaoxianribaobiaoPaihaoComboBox");
     comboxinti(ui->gaoxianribaobiaoSizeComboBox,"gaoxianribaobiaoSizeComboBox",2);
     comboxinti(ui->gaoxianribaobiaoChangduComboBox,"gaoxianribaobiaoChangduComboBox",1);
     comboxinti(ui->gaoxianribaobiaoPandingComboBox,"gaoxianribaobiaoPandingComboBox",2);
     comboxinti(ui->gaoxianribaobiaoPinmingComboBox,"gaoxianribaobiaoPinmingComboBox",1);

    //重置输出栏
     ui->gaoxianribaobiaoZZHLineEdit->setText("");
     ui->gaoxianribaobiaoHLZLLineEdit->setText("");
     ui->gaoxianribaobiaozhongliangLineEdit->setText("");


     //判定权限
     if(true){

         ui->gaoxianribaobiaoPushButton->setDisabled(false);
     }


     //隐藏提示
     //上传成功或者失败label
     ui->gaoxianribaobiaoSuccessLabel->hide();
     ui->gaoxianribaobiaoFailTextBrowser->hide();
}


QString MainWindow::gaoxianribaobiaoUpdate(){

    QString date = transNull(transdate(ui->gaoxianribaoDateEdit->date()));

    QString guige = transNull(ui->gaoxianribaobiaoSizeComboBox->currentText());

    QString paihao = transNull(ui->gaoxianribaobiaoPaihaoComboBox->currentText());
    QString changdu = transNull(ui->gaoxianribaobiaoChangduComboBox->currentText());
    QString zzh = transNull(ui->gaoxianribaobiaoZZHLineEdit->text());
    QString zhongliang = transNull(ui->gaoxianribaobiaozhongliangLineEdit->text());


    QString pangdin = transNull(ui->gaoxianribaobiaoPandingComboBox->currentText());

    QString banci = transNull(ui->gaoxianribaobiaoBancicomboBox->currentText());
    QString pinming = transNull(ui->gaoxianribaobiaoPinmingComboBox->currentText());

     QString HLZL = transNull(ui->gaoxianribaobiaoHLZLLineEdit->text());// should changed this one for 理级重量

    QString update = "INSERT INTO `chejian` (`轧制号`, `规格`, `牌号`, `品名`, `重量`, `理级重量`, `判定`, `班次`, `日期`, `上传日期`) ";
    update += "VALUES ('"+zzh+"','"+guige+"','"+paihao+"','"+pinming+"','"+zhongliang+"','"+HLZL+"','"+pangdin;
    update +="','"+banci+"','"+date+"','"+transdate(QDateTime::currentDateTime().date())+"');";

    //删除了长度的输入，因为高线生成不需要长度

    /*

INSERT INTO `chejian` (`炉批号`, `规格`, `牌号`, `品名`, `长度`, `重量`, `理级重量`, `判定`, `班次`, `日期`, `上传日期`) VALUES ('1', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);


*/

    update.replace("'NULL'","NULL");
    return update;

}


void MainWindow::on_gaoxianribaobiaoPushButton_clicked() //上传按钮
{
    QString update = gaoxianribaobiaoUpdate();
    QMessageBox::StandardButton confirm;
    //确认是否有null 信息
   if(update.contains("NULL")){
        confirm = QMessageBox::warning(this,"数据有缺","是否上传数据",QMessageBox::Yes|QMessageBox::No);
   }else{
         confirm = QMessageBox::question(this,"数据完整","是否上传数据",QMessageBox::Yes|QMessageBox::No);
   }


   if(confirm == QMessageBox::Yes){//同意上传
       qDebug() << update;

       QSqlQuery query(db);//数据库选择
       query.exec(update);

       //更新组合框内容

       renewcombobox(ui->gaoxianribaobiaoBancicomboBox,"gaoxianribaobiaoBancicomboBox");

       renewcombobox(ui->gaoxianribaobiaoPaihaoComboBox,"gaoxianribaobiaoPaihaoComboBox");
       renewcombobox(ui->gaoxianribaobiaoSizeComboBox,"gaoxianribaobiaoSizeComboBox");
       renewcombobox(ui->gaoxianribaobiaoChangduComboBox,"gaoxianribaobiaoChangduComboBox");
       renewcombobox(ui->gaoxianribaobiaoPandingComboBox,"gaoxianribaobiaoPandingComboBox");
       renewcombobox(ui->gaoxianribaobiaoPinmingComboBox,"gaoxianribaobiaoPinmingComboBox");


        ui->gaoxianribaobiaoSuccessLabel->setText("轧制号 : "+ui->gaoxianribaobiaoZZHLineEdit->text()+" 上传成功 (´・ω・`) ");
        queryVerify(ui->gaoxianribaobiaoSuccessLabel,ui->gaoxianribaobiaoFailTextBrowser,&query);


   }
}





QString MainWindow::gaoxianribaobiaoReupdate(){


     QString date = transNull(transdate(ui->gaoxianribaoDateEdit->date()));

     QString guige = transNull(ui->gaoxianribaobiaoSizeComboBox->currentText());

     QString paihao = transNull(ui->gaoxianribaobiaoPaihaoComboBox->currentText());
     QString changdu = transNull(ui->gaoxianribaobiaoChangduComboBox->currentText());
     QString zzh = transNull(ui->gaoxianribaobiaoZZHLineEdit->text());
     QString zhongliang = transNull(ui->gaoxianribaobiaozhongliangLineEdit->text());


     QString pangdin = transNull(ui->gaoxianribaobiaoPandingComboBox->currentText());

     QString banci = transNull(ui->gaoxianribaobiaoBancicomboBox->currentText());
     QString pinming = transNull(ui->gaoxianribaobiaoPinmingComboBox->currentText());

      QString HLZL = transNull(ui->gaoxianribaobiaoHLZLLineEdit->text());// should changed this one for 理级重量
      QString update = " UPDATE `chejian` SET";
      if(guige!="NULL"){
          update += "`规格`= '"+guige+"',";
      }
      if(paihao!="NULL"){
          update += "`牌号`= '"+paihao+"',";
      }
      if(pinming!="NULL"){
          update += "`品名`= '"+pinming+"',";
      }
   /*   if(changdu!="NULL"){
          update += "`长度`= '"+changdu+"',";
      }*/
      if(zhongliang!="NULL"){
          update += "`重量`= '"+zhongliang+"',";
      }
      if(HLZL!="NULL"){
          update += "`理级重量`= '"+HLZL+"',";
      }
      if(pangdin!="NULL"){
          update += "`判定`= '"+pangdin+"',";
      }
      if(banci!="NULL"){
          update += "`班次`= '"+banci+"',";
      }
      if(date!="NULL"){
          update += "`日期`= '"+date+"',";
      }


      /*

      UPDATE `chejian` SET `轧制号`=[value-1],`规格`=[value-2],`牌号`=[value-3],`品名`=[value-4],`长度`=[value-5],`重量`=[value-6],`理级重量`=[value-7],`判定`=[value-8],`班次`=[value-9],`日期`=[value-10],`上传日期`=[value-11] WHERE 1

      */

     update += "`上传日期`= '"+transdate(QDateTime::currentDateTime().date())+"' ";
     update += " WHERE `轧制号` =  '"+zzh+"';";


      return update;

}

void MainWindow::on_gaoxianribaobiaoReupdatePushButton_clicked()//修改按钮
{
    if(ui->gaoxianribaobiaoZZHLineEdit->text().compare("")==0){
         ui->gaoxianribaobiaoFailTextBrowser->setText("无法修改，轧制号为空");
         ui->gaoxianribaobiaoSuccessLabel->hide();
         ui->gaoxianribaobiaoFailTextBrowser->show();
         return;


     }else if(!IsItemExist("轧制号",ui->gaoxianribaobiaoZZHLineEdit->text(),"chejian",db)){

         ui->gaoxianribaobiaoFailTextBrowser->setText("无法修改，该轧制号不存在");
         ui->gaoxianribaobiaoSuccessLabel->hide();
         ui->gaoxianribaobiaoFailTextBrowser->show();
         return;
    }



    QMessageBox::StandardButton confirm;

    confirm = QMessageBox::question(this,"数据修改","是否修改信息",QMessageBox::Yes|QMessageBox::No);

   if(confirm == QMessageBox::Yes){//同意上传
    QString update = gaoxianribaobiaoReupdate();
    QSqlQuery query(db); //数据库选择
    query.exec(update);
    qDebug() << update;


    renewcombobox(ui->gaoxianribaobiaoBancicomboBox,"gaoxianribaobiaoBancicomboBox");
    renewcombobox(ui->gaoxianribaobiaoPaihaoComboBox,"gaoxianribaobiaoPaihaoComboBox");
    renewcombobox(ui->gaoxianribaobiaoSizeComboBox,"gaoxianribaobiaoSizeComboBox");
    renewcombobox(ui->gaoxianribaobiaoChangduComboBox,"gaoxianribaobiaoChangduComboBox");
    renewcombobox(ui->gaoxianribaobiaoPandingComboBox,"gaoxianribaobiaoPandingComboBox");
    renewcombobox(ui->gaoxianribaobiaoPinmingComboBox,"gaoxianribaobiaoPinmingComboBox");

    ui->gaoxianribaobiaoSuccessLabel->setText("轧制号 : "+ui->gaoxianribaobiaoZZHLineEdit->text()+" 修改成功 (´・ω・`) ");
    queryVerify(ui->gaoxianribaobiaoSuccessLabel,ui->gaoxianribaobiaoFailTextBrowser,&query);
   }



}


//重置按钮
void MainWindow::on_gaoxianribaobiaoResetPushButton_clicked()
{
    initgaoxianribaobiao();
}





//使组合框可以记录自己的内容
void MainWindow::on_gaoxianribaobiaoBancicomboBox_editTextChanged(const QString &arg1)
{
    ui->gaoxianribaobiaoBancicomboBox->setItemText(ui->gaoxianribaobiaoBancicomboBox->currentIndex(),arg1);
}


void MainWindow::on_gaoxianribaobiaoPaihaoComboBox_editTextChanged(const QString &arg1)
{
    ui->gaoxianribaobiaoPaihaoComboBox->setItemText(ui->gaoxianribaobiaoPaihaoComboBox->currentIndex(),arg1);
}

void MainWindow::on_gaoxianribaobiaoSizeComboBox_editTextChanged(const QString &arg1)
{
    ui->gaoxianribaobiaoSizeComboBox->setItemText(ui->gaoxianribaobiaoSizeComboBox->currentIndex(),arg1);
}

void MainWindow::on_gaoxianribaobiaoChangduComboBox_editTextChanged(const QString &arg1)
{
    ui->gaoxianribaobiaoChangduComboBox->setItemText(ui->gaoxianribaobiaoChangduComboBox->currentIndex(),arg1);
}

void MainWindow::on_gaoxianribaobiaoPandingComboBox_editTextChanged(const QString &arg1)
{
    ui->gaoxianribaobiaoPandingComboBox->setItemText(ui->gaoxianribaobiaoPandingComboBox->currentIndex(),arg1);
}


void MainWindow::on_gaoxianribaobiaoPinmingComboBox_editTextChanged(const QString &arg1)
{
    ui->gaoxianribaobiaoPinmingComboBox->setItemText(ui->gaoxianribaobiaoPinmingComboBox->currentIndex(),arg1);
}


//报告模块
//=====================================================================================================
//============================================================================================



//========================================================================================
//========================================================================================
//入库模块


void MainWindow::on_pushButtonWarehouse_clicked()//点击入库按钮
{

    ui->stackedWidget->setCurrentIndex(3);//开启报告表 页面


}




//入库模块
//========================================================================================
//========================================================================================
