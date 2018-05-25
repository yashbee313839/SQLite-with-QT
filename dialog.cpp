#include "dialog.h"
#include "ui_dialog.h"
#include <QtSql>
#include<QDebug>
#include <QFileInfo>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QSqlDatabase  mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/cfast/database.db");
    mydb.open();
    QSqlQueryModel *modal =new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery(mydb);
    QString t5 = "AI567";
    qry->prepare("select * from ADSB");
    qry->exec("create table " +t5+ "(one int,two int)");

    qry->prepare("select * from t5");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    mydb.close();

}

Dialog::~Dialog()
{
    delete ui;
}
