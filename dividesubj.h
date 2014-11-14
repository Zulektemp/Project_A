#ifndef DIVIDESUBJ_H
#define DIVIDESUBJ_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>

namespace Ui {
class dividesubj;
}

class dividesubj : public QDialog
{
    Q_OBJECT

public:
    explicit dividesubj(QWidget *parent = 0);
    ~dividesubj();
    void downloadData(QSqlTableModel *loadedModel, QModelIndex loadedIndex, int lastId);
    void initializator();
    bool i=false;
    QDataWidgetMapper *mapper,*mapper_2;
    int startValue_chislo_ch;
    int startValue_chislo_gr ;
    int startValue_gr ;
    int startValue_lk ;
    int startValue_ks ;
    int startValue_pract_na_gr ;
    int startValue_pract_vsego ;
    int startValue_lab_na_gr ;
    int startValue_lab_vsego ;
    int startValue_srs_na_gr ;
    int startValue_srs_vsego ;
    int startValue_kp_kr ;
    int startValue_ekz ;
    int startValue_zach ;
    int startValue_rkrz ;
    int startValue_rgr ;
    int startValue_vsego;

public slots:
        void on_acceptDivisionBtn_clicked();


private slots:


    void on_chislo_chSB_valueChanged(int arg1);

    void on_chislo_chSB_2_valueChanged(int arg1);

    void on_chislo_grSB_valueChanged(int arg1);

    void on_chislo_grSB_2_valueChanged(int arg1);

    void on_lkSB_valueChanged(int arg1);

    void on_ksSB_2_valueChanged(int arg1);

    void on_ksSB_valueChanged(int arg1);

    void on_pract_na_grSB_valueChanged(int arg1);

    void on_pract_na_grSB_2_valueChanged(int arg1);

    void on_pract_vsegoSB_valueChanged(int arg1);

    void on_pract_vsegoSB_2_valueChanged(int arg1);

    void on_lab_na_grSB_valueChanged(int arg1);

    void on_lab_na_grSB_2_valueChanged(int arg1);

    void on_lab_vsegoSB_valueChanged(int arg1);

    void on_lab_vsegoSB_2_valueChanged(int arg1);

    void on_srs_na_grSB_valueChanged(int arg1);

    void on_srs_na_grSB_2_valueChanged(int arg1);

    void on_srs_vsegoSB_valueChanged(int arg1);

    void on_srs_vsegoSB_2_valueChanged(int arg1);

    void on_kp_krSB_valueChanged(int arg1);

    void on_kp_krSB_2_valueChanged(int arg1);

    void on_ekzSB_valueChanged(int arg1);

    void on_ekzSB_2_valueChanged(int arg1);

    void on_zachSB_valueChanged(int arg1);

    void on_zachSB_2_valueChanged(int arg1);

    void on_rkrzSB_valueChanged(int arg1);

    void on_rkrzSB_2_valueChanged(int arg1);

    void on_vsegoSB_2_valueChanged(int arg1);

    void on_rgrSB_valueChanged(int arg1);

    void on_rgrSB_2_valueChanged(int arg1);

    void on_vsegoSB_valueChanged(int arg1);

    void on_lkSB_2_valueChanged(int arg1);



private:
    Ui::dividesubj *ui;
};

#endif // DIVIDESUBJ_H
