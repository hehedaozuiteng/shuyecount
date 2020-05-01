/********************************************************************************
** Form generated from reading UI file 'werahouse.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WERAHOUSE_H
#define UI_WERAHOUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Werahouse
{
public:
    QPushButton *query;
    QComboBox *banci;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QLabel *label;
    QPushButton *updateButton;

    void setupUi(QWidget *Werahouse)
    {
        if (Werahouse->objectName().isEmpty())
            Werahouse->setObjectName(QString::fromUtf8("Werahouse"));
        Werahouse->resize(1694, 932);
        query = new QPushButton(Werahouse);
        query->setObjectName(QString::fromUtf8("query"));
        query->setGeometry(QRect(530, 20, 141, 41));
        QFont font;
        font.setPointSize(16);
        query->setFont(font);
        banci = new QComboBox(Werahouse);
        banci->addItem(QString());
        banci->addItem(QString());
        banci->addItem(QString());
        banci->setObjectName(QString::fromUtf8("banci"));
        banci->setGeometry(QRect(110, 20, 111, 31));
        banci->setFont(font);
        banci->setEditable(true);
        dateEdit = new QDateEdit(Werahouse);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(320, 20, 181, 31));
        dateEdit->setFont(font);
        dateEdit->setDateTime(QDateTime(QDate(2019, 12, 16), QTime(0, 0, 0)));
        label_2 = new QLabel(Werahouse);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 20, 81, 31));
        label_2->setFont(font);
        label = new QLabel(Werahouse);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 71, 31));
        label->setFont(font);
        updateButton = new QPushButton(Werahouse);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(700, 20, 151, 41));
        updateButton->setFont(font);

        retranslateUi(Werahouse);

        banci->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Werahouse);
    } // setupUi

    void retranslateUi(QWidget *Werahouse)
    {
        Werahouse->setWindowTitle(QApplication::translate("Werahouse", "Form", nullptr));
        query->setText(QApplication::translate("Werahouse", "\346\237\245\350\257\242", nullptr));
        banci->setItemText(0, QApplication::translate("Werahouse", "\346\227\251\347\217\255", nullptr));
        banci->setItemText(1, QApplication::translate("Werahouse", "\344\270\255\347\217\255", nullptr));
        banci->setItemText(2, QApplication::translate("Werahouse", "\346\231\232\347\217\255", nullptr));

        label_2->setText(QApplication::translate("Werahouse", "\346\227\245\346\234\237:", nullptr));
        label->setText(QApplication::translate("Werahouse", "\347\217\255\346\254\241:", nullptr));
        updateButton->setText(QApplication::translate("Werahouse", "\344\270\212\344\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Werahouse: public Ui_Werahouse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WERAHOUSE_H
