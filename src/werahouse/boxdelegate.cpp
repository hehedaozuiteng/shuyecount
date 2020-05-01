#include "boxdelegate.h"

#include <QDebug>
#include <QComboBox>

BoxDelegate::BoxDelegate(QVector<QVector<QString>> list,
                         QObject *parent)
    : QStyledItemDelegate(parent)
{

     alist.append(list);
     cangku.push_back("输入仓库");
     for(int i = 0;i < alist.length();i++){
         cangku.push_back(alist.at(i)[0]);
     }




}

QWidget *BoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex & index ) const
{

    QComboBox *editor = new QComboBox(parent);
    editor->setFrame(true);
    if(index.column() == 8){
        for(int i = 0;i < cangku.length();i++){
            editor->addItem(cangku.at(i));
        }
    }
    else if(index.column()==9){
      QString str = index.siblingAtColumn(8).data(Qt::EditRole).toString();
      int value = cangku.indexOf(str)-1;

      if(value > -1){
          for(int i = 1;i < alist[value].length();i++){
              editor->addItem(alist[value][i]);
          }
      }
      else{
          editor->addItem("请输入仓库号");
      }

    }


    return editor;
}


void BoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{


    QString str = index.data(Qt::EditRole).toString();
    QComboBox *box = static_cast<QComboBox*>(editor);
    box->showPopup();//show the popup one clicked;
    int value = box->findText(str);
    box->setCurrentIndex(value);

}



void BoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{

    QComboBox *box = static_cast<QComboBox*>(editor);
    QString value = box->currentText();
    if((value == "请输入仓库号") or (value == "")){
        value = index.data(Qt::EditRole).toString();
    }

    model->setData(index, value, Qt::EditRole);

}



void BoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{

    editor->setGeometry(option.rect);

}


//void changeList(){};

