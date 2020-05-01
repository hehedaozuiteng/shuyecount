#ifndef BOXDELEGATE_H
#define BOXDELEGATE_H
#include <QStyledItemDelegate>
#include <QModelIndex>


class BoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    BoxDelegate(QVector<QVector<QString>> list,
                QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    //void changeList();
private:
    QVector<QVector<QString>> alist;
    QVector<QString> cangku;


};

#endif // BOXDELEGATE_H
