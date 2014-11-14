#ifndef MARKDELEGATE_H
#define MARKDELEGATE_H

#include <QStyledItemDelegate>

class MarkDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MarkDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    int bigGroupForPract() const;

    int bigGroupForLab() const;

    double writedRel() const;

    double writedRel2() const;


public slots:
    void setBigGroupForPract(int bigGroupForPract);
    void setBigGroupForLab(int bigGroupForLab);
    void setWritedRel(int writedRel);
    void setWritedRel2(int writedRel2);

private:
    bool markBGFP(const QModelIndex &index) const;
    bool markBGFL(const QModelIndex &index) const;
    bool markWR(const QModelIndex &index) const;
    bool markWR2(const QModelIndex &index) const;

    int m_bigGroupForPract;
    int m_bigGroupForLab;
    double m_writedRel;
    double m_writedRel2;
    const int m_peoplesCountColumn = 3;
    const int m_practicePerGroupColumn = 8;
    const int m_totalPracticeColumn = 9;
    const int m_labPerGroupColumn = 10;
    const int m_labTotalColumn = 11;

};

#endif // MARKDELEGATE_H
