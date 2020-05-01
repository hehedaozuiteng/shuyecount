#ifndef SUPPORTTOOL_H
#define SUPPORTTOOL_H

#include <QtCore/qglobal.h>
#include <QComboBox>
#include <QSettings>
#include <QDate>
#include <QLabel>
#include <QTextBrowser>
#include <QSqlQuery>
#include <QSqlError>

#if defined(SUPPORTTOOL_LIBRARY)
#  define SUPPORTTOOL_EXPORT Q_DECL_EXPORT
#else
#  define SUPPORTTOOL_EXPORT Q_DECL_IMPORT
#endif


void comboxinti(QComboBox *a, QString comboboxname,int initlItemnum = 0);
void renewcombobox(QComboBox *a, QString comboboxname);
bool queryVerify(QLabel *succefulLabel, QTextBrowser *failBrower, QSqlQuery *sqlQuery);


QString transdate(QDate a);
QString transNull(QString a);

bool IsItemExist(QString term, QString id,QString tablename, QSqlDatabase db);

#endif // SUPPORTTOOL_H
