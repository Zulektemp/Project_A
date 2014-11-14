#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "markdelegate.h"

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include "delegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QSqlDatabase db;
    ~MainWindow();


private slots:

    void bigGroupForPractValueChangedHandler(int value);

    void bigGroupForLabValueChangedHandler(int value);

    void writedRelValueChangedHandler(int value);

    void writedRel2ValueChangedHandler(int value);

    void on_importCSVbtn_clicked();

    void on_divideSubjbtn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *m_csvModel;
    void setupModel();
    void fillTableView();
    QString deleteNumbers(const QString tempstr);
    Delegate *mydelegate;
    MarkDelegate *m_delegate;
    QItemSelectionModel *selectionModel;
};

#endif // MAINWINDOW_H
