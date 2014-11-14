#include "markdelegate.h"

#include <QPainter>

#include  <QDebug>

MarkDelegate::MarkDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void MarkDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (markBGFP(index)) {
        painter->save();
        painter->fillRect(option.rect, QBrush(Qt::red));
        painter->restore();
        QStyledItemDelegate::paint(painter,option, index);
    }
    else
    {
        if (markBGFL(index)) {
            painter->save();
            painter->fillRect(option.rect, QBrush(Qt::red));
            painter->restore();
            QStyledItemDelegate::paint(painter,option, index);
        }
        else
        {

            if (markWR(index))
            {
                painter->save();
                painter->fillRect(option.rect, QBrush(Qt::yellow));
                painter->restore();
                QStyledItemDelegate::paint(painter,option, index);
            }
            else
            {
                if (markWR2(index))
                {
                    painter->save();
                    painter->fillRect(option.rect, QBrush(Qt::yellow));
                    painter->restore();
                    QStyledItemDelegate::paint(painter,option, index);
                }
                else
                {
                    QStyledItemDelegate::paint(painter, option, index);
                }
            }
        }
    }
}

bool MarkDelegate::markBGFP(const QModelIndex &index) const
{


    int i  = index.row();
    const QAbstractItemModel *model =  index.model();
    QModelIndex idx1 = model->index(i, m_practicePerGroupColumn);
    int q1 = idx1.data().toInt();
    QModelIndex idx2 = model->index(i, m_totalPracticeColumn);
    int q2 = idx2.data().toInt();
    QModelIndex idx3 = model->index(i, m_peoplesCountColumn);
    int q3 = idx3.data().toInt();

    if (q1!=0 && q2!=0)
    {

        if ((idx1 == index || idx2 == index) && q2 == q1 && q3>m_bigGroupForPract)
        {
           return true;
        }



    return false;
}
}

bool MarkDelegate::markBGFL(const QModelIndex &index) const
{
    int i  = index.row();
    const QAbstractItemModel *model =  index.model();

    QModelIndex idx3 = model->index(i, m_peoplesCountColumn);
    int q3 = idx3.data().toInt();
    QModelIndex idx4 = model->index(i, m_labPerGroupColumn);
    int q4 = idx4.data().toInt();
    QModelIndex idx5 = model->index(i, m_labTotalColumn);
    int q5 = idx5.data().toInt();

    if (q4!=0 && q5!=0)
    {

        if ((idx4 == index || idx5 == index) && q4 == q5 && q3>m_bigGroupForLab)
        {
            return true;
        }
    }



    return false;

}

bool MarkDelegate::markWR(const QModelIndex &index) const
{
    int i  = index.row();
    const QAbstractItemModel *model =  index.model();
    QModelIndex idx1 = model->index(i, m_practicePerGroupColumn);
    int q1 = idx1.data().toInt();
    QModelIndex idx2 = model->index(i, m_totalPracticeColumn);
    int q2 = idx2.data().toInt();
    QModelIndex idx3 = model->index(i, m_peoplesCountColumn);
    int q3 = idx3.data().toInt();

    if (q1!=0 && q2!=0)
    {

        double relq1=q1,relq2=q2;
        double practRel = relq1/relq2;
        if ((idx1 == index || idx2 == index) && practRel>m_writedRel && q2!=q1 && q3>m_bigGroupForPract)
        {
            return true;
        }
    }

    return false;

}

bool MarkDelegate::markWR2(const QModelIndex &index) const
{
    int i  = index.row();
    const QAbstractItemModel *model =  index.model();
    QModelIndex idx3 = model->index(i, m_peoplesCountColumn);
    int q3 = idx3.data().toInt();
    QModelIndex idx4 = model->index(i, m_labPerGroupColumn);
    int q4 = idx4.data().toInt();
    QModelIndex idx5 = model->index(i, m_labTotalColumn);
    int q5 = idx5.data().toInt();



    if (q4!=0 && q5!=0 )
    {
        double relq4=q4,relq5=q5;
        double labRel = relq4/relq5;

        if ((idx4 == index || idx5 == index) && labRel>m_writedRel2 && q4!=q5 && q3>m_bigGroupForLab)
        {
           return true;
        }

    }
    return false;
}


double MarkDelegate::writedRel2() const
{
    return m_writedRel2;
}

void MarkDelegate::setWritedRel2(int writedRel2)
{
    m_writedRel2 = writedRel2;
    m_writedRel2 = m_writedRel2/100;
}

double MarkDelegate::writedRel() const
{
    return m_writedRel;
}

void MarkDelegate::setWritedRel(int writedRel)
{
    m_writedRel = writedRel;
    m_writedRel = m_writedRel/100;
}

int MarkDelegate::bigGroupForLab() const
{
    return m_bigGroupForLab;
}

void MarkDelegate::setBigGroupForLab(int bigGroupForLab)
{
    m_bigGroupForLab = bigGroupForLab;
}

int MarkDelegate::bigGroupForPract() const
{
    return m_bigGroupForPract;
}

void MarkDelegate::setBigGroupForPract(int bigGroupForPract)
{
    m_bigGroupForPract = bigGroupForPract;
}

