#include "delegate.h"
#include <QSpinBox>
#include <QLineEdit>

Delegate::Delegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    return editor;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();

    QLineEdit *spinbox = static_cast<QLineEditx*>(editor);
    spinbox->setValue(value);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinbox = static_cast<QSpinBox*>(editor);
    spinbox->interpretText();
    int value = spinbox->value();
    model->setData(index,value, Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
