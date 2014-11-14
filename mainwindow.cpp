#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dividesubj.h"

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QSqlTableModel>
#include <algorithm>
#include <memory>
#include <QItemDelegate>
#include <QRectF>
#include <QPainter>
#include <QAbstractItemDelegate>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->tableView->setModel();
    ui->setupUi(this);

    setupModel();
    fillTableView();

    //mydelegate = new Delegate(this);
    m_delegate = new MarkDelegate(this);
    ui->tableView->setItemDelegate(m_delegate);

    m_delegate->setBigGroupForPract(ui->bigGroupForPractSB->value());
    m_delegate->setBigGroupForLab(ui->bigGroupForLabSB->value());
    int wrRel = ui->writedRelationSB->value();
    int wrRel2 = ui->writedRelation2SB->value();
    m_delegate->setWritedRel(wrRel);
    m_delegate->setWritedRel2(wrRel2);

    connect(ui->bigGroupForPractSB, SIGNAL(valueChanged(int)),
            this, SLOT(bigGroupForPractValueChangedHandler(int)) );
    connect(ui->bigGroupForLabSB, SIGNAL(valueChanged(int)),
            this, SLOT(bigGroupForLabValueChangedHandler(int)) );
    connect(ui->writedRelationSB, SIGNAL(valueChanged(int)),
            this, SLOT(writedRelValueChangedHandler(int)) );
    connect(ui->writedRelation2SB, SIGNAL(valueChanged(int)),
            this, SLOT(writedRel2ValueChangedHandler(int)) );

}


void MainWindow::setupModel()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("VIMI.sqlite3");
    if (!db.open()) {

    }


}

void MainWindow::fillTableView()
{
    ui->tableView->clearSpans();
    m_csvModel = new QSqlTableModel(this);
    m_csvModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_csvModel->setTable("main");
    m_csvModel->select();
    ui->tableView->setModel(m_csvModel);



    QModelIndexList indexes;
    //    foreach(index, indexes) {
    //        QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());
    //        qDebug()<<text;
    //    }
}

QString MainWindow::deleteNumbers(const QString tempstr)
{
    QString tempstr2 = tempstr;
    qDebug()<<tempstr2;
    if (tempstr2.startsWith("."))
    {
        tempstr2 = tempstr.mid(1,-1);
        return tempstr2;
    }
    else
    {
        tempstr2 = tempstr.mid(1,-1);
        return deleteNumbers(tempstr2);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_importCSVbtn_clicked()
{
    if (!db.open()) {}


    //Suppression + creation of the table
      QSqlQuery que;
    que.exec("DROP TABLE main;");
    que.exec ("CREATE TABLE main(dis_name char(255),fac char(255),kurs int,chislo_ch int,chislo_gr int,gr char(255),"
              "lk int,ks int,pract_na_gr int,pract_vsego int,lab_na_gr int,lab_vsego int,srs_na_gr int,srs_vsego int,"
              "kp_kr int,ekz int,zach int,rkrz int,rgr int,vsego int,id integer primary key autoincrement);");

    QFileDialog dg;
    dg.setFileMode(QFileDialog::ExistingFile);
    QStringList Qs;
    if(dg.exec() != QDialog::Accepted) {
        return;
    }
    Qs  = dg.selectedFiles();
    QString myString = Qs.at(0);


    //Open the "excel.csv" file
    QFile f(myString);
    qDebug()<<"rabotaet";
    if (f.open (QIODevice::ReadOnly)){
        qDebug()<<"rabotaet2";
        QTextStream ts(&f);


        //Travel through the csv file "excel.csv"
        while(!ts.atEnd()){

            qDebug()<<"rabotaet3";
            QStringList line = ts.readLine().split('\n');
            QString lineintoword = line.at(0);
            QStringList word = lineintoword.split(";");
            if (word.size()>3){
                qDebug()<<"rabotaet4";

                QString z = "INSERT INTO main(dis_name,fac,kurs,chislo_ch,chislo_gr,gr,lk,ks,pract_na_gr,pract_vsego,lab_na_gr,lab_vsego,srs_na_gr,srs_vsego,kp_kr,ekz,zach,rkrz,rgr,vsego)"
                        "VALUES('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19', '%20');";
                QString x;


                QString wordat0;
                qDebug()<<word.at(0);
                if (word.at(0).size()>1 && !word.at(0).startsWith("       "))
                {
                    wordat0 = deleteNumbers(word.at(0));
                }
                qDebug()<<wordat0;


                x = z.arg(wordat0)
                        .arg(word.at(1))
                        .arg(word.at(2))
                        .arg(word.at(3))
                        .arg(word.at(4))
                        .arg(word.at(5))
                        .arg(word.at(6))
                        .arg(word.at(7))
                        .arg(word.at(8))
                        .arg(word.at(9))
                        .arg(word.at(10))
                        .arg(word.at(11))
                        .arg(word.at(12))
                        .arg(word.at(13))
                        .arg(word.at(14))
                        .arg(word.at(15))
                        .arg(word.at(16))
                        .arg(word.at(17))
                        .arg(word.at(18))
                        .arg(word.at(19));
                if (!que.exec(x)){};
            }
        }
    }
    f.close ();
    fillTableView();
}

void MainWindow::bigGroupForPractValueChangedHandler(int value)
{
    m_delegate->setBigGroupForPract(ui->bigGroupForPractSB->value());

    QStyledItemDelegate d;
    ui->tableView->setItemDelegate(&d);
    ui->tableView->setItemDelegate(m_delegate);
}

void MainWindow::bigGroupForLabValueChangedHandler(int value)
{
    m_delegate->setBigGroupForLab(ui->bigGroupForLabSB->value());

    QStyledItemDelegate d;
    ui->tableView->setItemDelegate(&d);
    ui->tableView->setItemDelegate(m_delegate);
}

void MainWindow::writedRelValueChangedHandler(int value)
{
    int wrRel = ui->writedRelationSB->value();
    m_delegate->setWritedRel(wrRel);
    QStyledItemDelegate d;
    ui->tableView->setItemDelegate(&d);
    ui->tableView->setItemDelegate(m_delegate);
}

void MainWindow::writedRel2ValueChangedHandler(int value)
{
    int wrRel2 = ui->writedRelation2SB->value();
    m_delegate->setWritedRel2(wrRel2);

    QStyledItemDelegate d;
    ui->tableView->setItemDelegate(&d);
    ui->tableView->setItemDelegate(m_delegate);
}

void MainWindow::on_divideSubjbtn_clicked()
{
    QModelIndexList selectedIndexesList = ui->tableView->selectionModel()->selectedIndexes();
    dividesubj DivSubj;
    if (selectedIndexesList.isEmpty())
    {
        qDebug()<<"Не выбрана строка";
    }
    else
    {
        QModelIndex neededIndex = selectedIndexesList.takeFirst();
        m_csvModel->insertRow(neededIndex.row()+1);

        DivSubj.downloadData(m_csvModel,neededIndex,m_csvModel->rowCount());
        DivSubj.initializator();
        DivSubj.exec();

        m_csvModel->submitAll();

        qDebug()<<m_csvModel->fieldIndex("id");
    }

}
