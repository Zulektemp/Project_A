#include "dividesubj.h"
#include "ui_dividesubj.h"
#include <QDebug>

dividesubj::dividesubj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dividesubj)
{
    ui->setupUi(this);

}

void copyData(QAbstractItemModel *model, int column, int rowFrom, int rowTo)
{
    QVariant data = model->data(model->index(rowFrom, column), Qt::EditRole);
    model->setData(model->index(rowTo, column), data);
}

void dividesubj::downloadData(QSqlTableModel *loadedModel, QModelIndex loadedIndex, int lastId)
{
    i=false;
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(loadedModel);

    int fieldIndex_dis_name = loadedModel->fieldIndex("dis_name");
    int fieldIndex_fac = loadedModel->fieldIndex("fac");
    int fieldIndex_kurs = loadedModel->fieldIndex("kurs");
    int fieldIndex_gr = loadedModel->fieldIndex("gr");

    mapper->addMapping(ui->dis_nameLE, fieldIndex_dis_name);
    mapper->addMapping(ui->facLE, fieldIndex_fac);
    mapper->addMapping(ui->kursSB, fieldIndex_kurs);
    mapper->addMapping(ui->chislo_chSB, loadedModel->fieldIndex("chislo_ch"));
    mapper->addMapping(ui->chislo_grSB, loadedModel->fieldIndex("chislo_gr"));
    mapper->addMapping(ui->grLE, fieldIndex_gr);
    mapper->addMapping(ui->lkSB, loadedModel->fieldIndex("lk"));
    mapper->addMapping(ui->ekzSB, loadedModel->fieldIndex("eks"));
    mapper->addMapping(ui->kp_krSB, loadedModel->fieldIndex("kp_kr"));
    mapper->addMapping(ui->ksSB, loadedModel->fieldIndex("ks"));
    mapper->addMapping(ui->lab_na_grSB, loadedModel->fieldIndex("lab_na_gr"));
    mapper->addMapping(ui->lab_vsegoSB, loadedModel->fieldIndex("lab_vsego"));
    mapper->addMapping(ui->pract_na_grSB, loadedModel->fieldIndex("pract_na_gr"));
    mapper->addMapping(ui->vsegoSB, loadedModel->fieldIndex("vsego"));
    mapper->addMapping(ui->zachSB, loadedModel->fieldIndex("zach"));
    mapper->addMapping(ui->srs_vsegoSB, loadedModel->fieldIndex("srs_vsego"));
    mapper->addMapping(ui->srs_na_grSB, loadedModel->fieldIndex("srs_na_gr"));
    mapper->addMapping(ui->rkrzSB, loadedModel->fieldIndex("rkrz"));
    mapper->addMapping(ui->rgrSB, loadedModel->fieldIndex("rgr"));
    mapper->addMapping(ui->pract_vsegoSB, loadedModel->fieldIndex("pract_vsego"));
    mapper->setCurrentModelIndex(loadedIndex);

    mapper_2 = new QDataWidgetMapper(this);
    mapper_2->setModel(loadedModel);
    qDebug()<<"1@"<<ui->pract_na_grSB->value();
    mapper_2->addMapping(ui->dis_nameLE_2, fieldIndex_dis_name);
    mapper_2->addMapping(ui->facLE_2,fieldIndex_fac);
    mapper_2->addMapping(ui->kursSB_2,fieldIndex_kurs);
    mapper_2->addMapping(ui->chislo_chSB_2, loadedModel->fieldIndex("chislo_ch"));
    mapper_2->addMapping(ui->chislo_grSB_2, loadedModel->fieldIndex("chislo_gr"));
    mapper_2->addMapping(ui->grLE_2, fieldIndex_gr);
    mapper_2->addMapping(ui->lkSB_2, loadedModel->fieldIndex("lk"));
    mapper_2->addMapping(ui->ekzSB_2, loadedModel->fieldIndex("eks"));
    mapper_2->addMapping(ui->kp_krSB_2, loadedModel->fieldIndex("kp_kr"));
    mapper_2->addMapping(ui->ksSB_2, loadedModel->fieldIndex("ks"));
    mapper_2->addMapping(ui->lab_na_grSB_2, loadedModel->fieldIndex("lab_na_gr"));
    mapper_2->addMapping(ui->lab_vsegoSB_2, loadedModel->fieldIndex("lab_vsego"));
    mapper_2->addMapping(ui->pract_na_grSB_2, loadedModel->fieldIndex("pract_na_gr"));
    mapper_2->addMapping(ui->vsegoSB_2, loadedModel->fieldIndex("vsego"));
    mapper_2->addMapping(ui->zachSB_2, loadedModel->fieldIndex("zach"));
    mapper_2->addMapping(ui->srs_vsegoSB_2, loadedModel->fieldIndex("srs_vsego"));
    mapper_2->addMapping(ui->srs_na_grSB_2, loadedModel->fieldIndex("srs_na_gr"));
    mapper_2->addMapping(ui->rkrzSB_2, loadedModel->fieldIndex("rkrz"));
    mapper_2->addMapping(ui->rgrSB_2, loadedModel->fieldIndex("rgr"));
    mapper_2->addMapping(ui->pract_vsegoSB_2, loadedModel->fieldIndex("pract_vsego"));

    QModelIndex nextIndex = loadedIndex.sibling(loadedIndex.row()+1, loadedIndex.column());
    mapper_2->setCurrentModelIndex(nextIndex);

    int loadedRow = loadedIndex.row();
    int nextRow = nextIndex.row();
    copyData(loadedModel, fieldIndex_dis_name, loadedRow, nextRow);
    copyData(loadedModel, fieldIndex_fac, loadedRow, nextRow);
    copyData(loadedModel, fieldIndex_kurs, loadedRow, nextRow);
    copyData(loadedModel, fieldIndex_gr, loadedRow, nextRow);

    QString lastIdString = QString::number(lastId);
    ui->lineEdit->setText(lastIdString);
    qDebug()<<"2@"<<ui->pract_na_grSB->value();
}

void dividesubj::initializator()
{
    qDebug()<<"3@"<<ui->pract_na_grSB->value();
        qDebug()<<"4@"<<startValue_pract_na_gr;
    startValue_chislo_ch = ui->chislo_chSB->value();
    startValue_chislo_gr = ui->chislo_grSB->value();
    startValue_lk = ui->lkSB->value();
    startValue_ks = ui->ksSB->value();
    startValue_pract_na_gr = ui->pract_na_grSB->value();
    startValue_pract_vsego =ui->pract_vsegoSB->value();
    startValue_lab_na_gr = ui->lab_na_grSB->value();
    startValue_lab_vsego = ui->lab_vsegoSB->value();
    startValue_srs_na_gr = ui->srs_na_grSB->value();
    startValue_srs_vsego = ui->srs_vsegoSB->value();
    startValue_kp_kr = ui->kp_krSB->value();
    startValue_ekz = ui->ekzSB->value();
    startValue_zach = ui->zachSB->value();
    startValue_rkrz = ui->rkrzSB->value();
    startValue_rgr = ui->rgrSB->value();
    startValue_vsego = ui->vsegoSB->value();
            qDebug()<<"5@"<<startValue_pract_na_gr;
    qDebug()<<"6@"<<ui->pract_na_grSB->value();

    ui->chislo_chSB->setValue(startValue_chislo_ch);
    ui->chislo_chSB_2->setValue(0);
    ui->chislo_chSB->setMaximum(startValue_chislo_ch);
    ui->chislo_chSB_2->setMaximum(startValue_chislo_ch);
    ui->chislo_chSB->setMinimum(0);
    ui->chislo_chSB_2->setMinimum(0);

    ui->chislo_grSB->setValue(startValue_chislo_gr);
    ui->chislo_grSB_2->setValue(0);
    ui->chislo_grSB->setMaximum(startValue_chislo_gr);
    ui->chislo_grSB_2->setMaximum(startValue_chislo_gr);
    ui->chislo_grSB->setMinimum(0);
    ui->chislo_grSB_2->setMinimum(0);

    ui->lkSB->setValue(startValue_lk);
    ui->lkSB_2->setValue(0);
    ui->lkSB->setMaximum(startValue_lk);
    ui->lkSB_2->setMaximum(startValue_lk);
    ui->lkSB->setMinimum(0);
    ui->lkSB_2->setMinimum(0);

    ui->ksSB->setValue(startValue_ks);
    ui->ksSB_2->setValue(0);
    ui->ksSB->setMaximum(startValue_ks);
    ui->ksSB_2->setMaximum(startValue_ks);
    ui->ksSB->setMinimum(0);
    ui->ksSB_2->setMinimum(0);

    ui->pract_na_grSB->setValue(startValue_pract_na_gr);
    ui->pract_na_grSB_2->setValue(0);
    ui->pract_na_grSB->setMaximum(startValue_pract_na_gr);
    ui->pract_na_grSB_2->setMaximum(startValue_pract_na_gr);
    ui->pract_na_grSB->setMinimum(0);
    ui->pract_na_grSB_2->setMinimum(0);
    qDebug()<<"7@"<<ui->pract_na_grSB->value();
    ui->pract_vsegoSB->setValue(startValue_pract_vsego);
    ui->pract_vsegoSB_2->setValue(0);
    ui->pract_vsegoSB->setMaximum(startValue_pract_vsego);
    ui->pract_vsegoSB_2->setMaximum(startValue_pract_vsego);
    ui->pract_vsegoSB->setMinimum(0);
    ui->pract_vsegoSB_2->setMinimum(0);

    ui->lab_na_grSB->setValue(startValue_lab_na_gr);
    ui->lab_na_grSB_2->setValue(0);
    ui->lab_na_grSB->setMaximum(startValue_lab_na_gr);
    ui->lab_na_grSB_2->setMaximum(startValue_lab_na_gr);
    ui->lab_na_grSB->setMinimum(0);
    ui->lab_na_grSB_2->setMinimum(0);

    ui->lab_vsegoSB->setValue(startValue_lab_vsego);
    ui->lab_vsegoSB_2->setValue(0);
    ui->lab_vsegoSB->setMaximum(startValue_lab_vsego);
    ui->lab_vsegoSB_2->setMaximum(startValue_lab_vsego);
    ui->lab_vsegoSB->setMinimum(0);
    ui->lab_vsegoSB_2->setMinimum(0);

    ui->srs_na_grSB->setValue(startValue_srs_na_gr);
    ui->srs_na_grSB_2->setValue(0);
    ui->srs_na_grSB->setMaximum(startValue_srs_na_gr);
    ui->srs_na_grSB_2->setMaximum(startValue_srs_na_gr);
    ui->srs_na_grSB->setMinimum(0);
    ui->srs_na_grSB_2->setMinimum(0);


    ui->srs_vsegoSB->setValue(startValue_srs_vsego);
    ui->srs_vsegoSB_2->setValue(0);
    ui->srs_vsegoSB->setMaximum(startValue_srs_vsego);
    ui->srs_vsegoSB_2->setMaximum(startValue_srs_vsego);
    ui->srs_vsegoSB->setMinimum(0);
    ui->srs_vsegoSB_2->setMinimum(0);

    ui->kp_krSB->setValue(startValue_kp_kr);
    ui->kp_krSB_2->setValue(0);
    ui->kp_krSB->setMaximum(startValue_kp_kr);
    ui->kp_krSB_2->setMaximum(startValue_kp_kr);
    ui->kp_krSB->setMinimum(0);
    ui->kp_krSB_2->setMinimum(0);

    ui->ekzSB->setValue(startValue_ekz);
    ui->ekzSB_2->setValue(0);
    ui->ekzSB->setMaximum(startValue_ekz);
    ui->ekzSB_2->setMaximum(startValue_ekz);
    ui->ekzSB->setMinimum(0);
    ui->ekzSB_2->setMinimum(0);

    ui->zachSB->setValue(startValue_zach);
    ui->zachSB_2->setValue(0);
    ui->zachSB->setMaximum(startValue_zach);
    ui->zachSB_2->setMaximum(startValue_zach);
    ui->zachSB->setMinimum(0);
    ui->zachSB_2->setMinimum(0);

    ui->rkrzSB->setValue(startValue_rkrz);
    ui->rkrzSB_2->setValue(0);
    ui->rkrzSB->setMaximum(startValue_rkrz);
    ui->rkrzSB_2->setMaximum(startValue_rkrz);
    ui->rkrzSB->setMinimum(0);
    ui->rkrzSB_2->setMinimum(0);

    ui->rgrSB->setValue(startValue_rgr);
    ui->rgrSB_2->setValue(0);
    ui->rgrSB->setMaximum(startValue_rgr);
    ui->rgrSB_2->setMaximum(startValue_rgr);
    ui->rgrSB->setMinimum(0);
    ui->rgrSB_2->setMinimum(0);

    ui->vsegoSB->setValue(startValue_vsego);
    ui->vsegoSB_2->setValue(0);
    ui->vsegoSB->setMaximum(startValue_vsego);
    ui->vsegoSB_2->setMaximum(startValue_vsego);
    ui->vsegoSB->setMinimum(0);
    ui->vsegoSB_2->setMinimum(0);


//  СДЕЛАТЬ  connect(lk,ks,pract_vsego,lab_vsego,srs_vsego,kp_kr,ekz,zach,rkrz,rgr
//            vsego)
  i=true;
}

void dividesubj::on_chislo_chSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->chislo_chSB_2->blockSignals(true);
        ui->chislo_chSB_2->setValue(startValue_chislo_ch-ui->chislo_chSB->value());
        ui->chislo_chSB_2->blockSignals(false);
    }
}

void dividesubj::on_chislo_chSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->chislo_chSB->blockSignals(true);
        ui->chislo_chSB->setValue(startValue_chislo_ch-ui->chislo_chSB_2->value());
        ui->chislo_chSB->blockSignals(false);
    }
}

void dividesubj::on_chislo_grSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->chislo_grSB_2->blockSignals(true);
        ui->chislo_grSB_2->setValue(startValue_chislo_gr-ui->chislo_grSB->value());
        ui->chislo_grSB_2->blockSignals(false);
    }
}

void dividesubj::on_chislo_grSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->chislo_grSB->blockSignals(true);
        ui->chislo_grSB->setValue(startValue_chislo_gr-ui->chislo_grSB_2->value());
        ui->chislo_grSB->blockSignals(false);
    }
}

void dividesubj::on_lkSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->lkSB_2->blockSignals(true);
        ui->lkSB_2->setValue(startValue_lk-ui->lkSB->value());
        ui->lkSB_2->blockSignals(false);
    }
}

void dividesubj::on_lkSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->lkSB->blockSignals(true);
        ui->lkSB->setValue(startValue_lk-ui->lkSB_2->value());
        ui->lkSB->blockSignals(false);
    }
}

void dividesubj::on_ksSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->ksSB_2->blockSignals(true);
        ui->ksSB_2->setValue(startValue_ks-ui->ksSB->value());
        ui->ksSB_2->blockSignals(false);
    }
}

void dividesubj::on_ksSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->ksSB->blockSignals(true);
        ui->ksSB->setValue(startValue_ks-ui->ksSB_2->value());
        ui->ksSB->blockSignals(false);
    }
}

void dividesubj::on_pract_na_grSB_valueChanged(int arg1)
{
    if (i)
    {
        qDebug()<<"111@"<<ui->pract_na_grSB->value();
        ui->pract_na_grSB_2->blockSignals(true);
        ui->pract_na_grSB_2->setValue(startValue_pract_na_gr-ui->pract_na_grSB->value());
        ui->pract_na_grSB_2->blockSignals(false);
    }
}

void dividesubj::on_pract_na_grSB_2_valueChanged(int arg1)
{
    if (i)
    {
        qDebug()<<"222@"<<ui->pract_na_grSB->value();
        ui->pract_na_grSB->blockSignals(true);
        ui->pract_na_grSB->setValue(startValue_pract_na_gr-ui->pract_na_grSB_2->value());
        ui->pract_na_grSB->blockSignals(false);
    }
}

void dividesubj::on_pract_vsegoSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->pract_vsegoSB_2->blockSignals(true);
        ui->pract_vsegoSB_2->setValue(startValue_pract_vsego-ui->pract_vsegoSB->value());
        ui->pract_vsegoSB_2->blockSignals(false);
    }
}

void dividesubj::on_pract_vsegoSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->pract_vsegoSB->blockSignals(true);
        ui->pract_vsegoSB->setValue(startValue_pract_vsego-ui->pract_vsegoSB_2->value());
        ui->pract_vsegoSB->blockSignals(false);
    }
}

void dividesubj::on_lab_na_grSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->lab_na_grSB_2->blockSignals(true);
        ui->lab_na_grSB_2->setValue(startValue_lab_na_gr-ui->lab_na_grSB->value());
        ui->lab_na_grSB_2->blockSignals(false);
    }
}

void dividesubj::on_lab_na_grSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->lab_na_grSB->blockSignals(true);
        ui->lab_na_grSB->setValue(startValue_lab_na_gr-ui->lab_na_grSB_2->value());
        ui->lab_na_grSB->blockSignals(false);
    }
}

void dividesubj::on_lab_vsegoSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->lab_vsegoSB_2->blockSignals(true);
        ui->lab_vsegoSB_2->setValue(startValue_lab_vsego-ui->lab_vsegoSB->value());
        ui->lab_vsegoSB_2->blockSignals(false);
    }
}

void dividesubj::on_lab_vsegoSB_2_valueChanged(int arg1)
{    if (i)
    {
        ui->lab_vsegoSB->blockSignals(true);
        ui->lab_vsegoSB->setValue(startValue_lab_vsego-ui->lab_vsegoSB_2->value());
        ui->lab_vsegoSB->blockSignals(false);
    }
}

void dividesubj::on_srs_na_grSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->srs_na_grSB_2->blockSignals(true);
        ui->srs_na_grSB_2->setValue(startValue_srs_na_gr-ui->srs_na_grSB->value());
        ui->srs_na_grSB_2->blockSignals(false);
    }
}

void dividesubj::on_srs_na_grSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->srs_na_grSB->blockSignals(true);
        ui->srs_na_grSB->setValue(startValue_srs_na_gr-ui->srs_na_grSB_2->value());
        ui->srs_na_grSB->blockSignals(false);
    }
}

void dividesubj::on_srs_vsegoSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->srs_vsegoSB_2->blockSignals(true);
        ui->srs_vsegoSB_2->setValue(startValue_srs_vsego-ui->srs_vsegoSB->value());
        ui->srs_vsegoSB_2->blockSignals(false);
    }
}

void dividesubj::on_srs_vsegoSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->srs_vsegoSB->blockSignals(true);
        ui->srs_vsegoSB->setValue(startValue_srs_vsego-ui->srs_vsegoSB_2->value());
        ui->srs_vsegoSB->blockSignals(false);
    }
}

void dividesubj::on_kp_krSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->kp_krSB_2->blockSignals(true);
        ui->kp_krSB_2->setValue(startValue_kp_kr-ui->kp_krSB->value());
        ui->kp_krSB_2->blockSignals(false);
    }
}

void dividesubj::on_kp_krSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->kp_krSB->blockSignals(true);
        ui->kp_krSB->setValue(startValue_kp_kr-ui->kp_krSB_2->value());
        ui->kp_krSB->blockSignals(false);
    }
}

void dividesubj::on_ekzSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->ekzSB_2->blockSignals(true);
        ui->ekzSB_2->setValue(startValue_ekz-ui->ekzSB->value());
        ui->ekzSB_2->blockSignals(false);
    }
}

void dividesubj::on_ekzSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->ekzSB->blockSignals(true);
        ui->ekzSB->setValue(startValue_ekz-ui->ekzSB_2->value());
        ui->ekzSB->blockSignals(false);
    }
}

void dividesubj::on_zachSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->zachSB_2->blockSignals(true);
        ui->zachSB_2->setValue(startValue_zach-ui->zachSB->value());
        ui->zachSB_2->blockSignals(false);
    }
}

void dividesubj::on_zachSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->zachSB->blockSignals(true);
        ui->zachSB->setValue(startValue_zach-ui->zachSB_2->value());
        ui->zachSB->blockSignals(false);
    }
}

void dividesubj::on_rkrzSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->rkrzSB_2->blockSignals(true);
        ui->rkrzSB_2->setValue(startValue_rkrz-ui->rkrzSB->value());
        ui->rkrzSB_2->blockSignals(false);
    }
}

void dividesubj::on_rkrzSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->rkrzSB->blockSignals(true);
        ui->rkrzSB->setValue(startValue_rkrz-ui->rkrzSB_2->value());
        ui->rkrzSB->blockSignals(false);
    }
}

void dividesubj::on_rgrSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->rgrSB_2->blockSignals(true);
        ui->rgrSB_2->setValue(startValue_rgr-ui->rgrSB->value());
        ui->rgrSB_2->blockSignals(false);
    }
}

void dividesubj::on_rgrSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->rgrSB->blockSignals(true);
        ui->rgrSB->setValue(startValue_rgr-ui->rgrSB_2->value());
        ui->rgrSB->blockSignals(false);
    }
}

void dividesubj::on_vsegoSB_valueChanged(int arg1)
{
    if (i)
    {
        ui->vsegoSB_2->blockSignals(true);
        ui->vsegoSB_2->setValue(startValue_vsego-ui->vsegoSB->value());
        ui->vsegoSB_2->blockSignals(false);
    }
}

void dividesubj::on_vsegoSB_2_valueChanged(int arg1)
{
    if (i)
    {
        ui->vsegoSB->blockSignals(true);
        ui->vsegoSB->setValue(startValue_vsego-ui->vsegoSB_2->value());
        ui->vsegoSB->blockSignals(false);
    }
}

void dividesubj::on_acceptDivisionBtn_clicked()
{
mapper->submit();
mapper_2->submit();
}

dividesubj::~dividesubj()
{
    delete ui;
}


