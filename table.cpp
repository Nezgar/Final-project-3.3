#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    QSqlmyDB = QSqlDatabase::addDatabase("QSQLITE");
    QSqlmyDB.setDatabaseName("./myDatabase.db");
    if(QSqlmyDB.open())
    {
        qDebug("Connected to database");
    }
    else
    {
        qDebug("Not connected to database");
    }
    QSqlqry = new QSqlQuery(QSqlmyDB);
    QSqlqry->exec("CREATE TABLE TEST (Title TEXT, Deadline TEXT, Progress TEXT);");

    QSqlmodel = new QSqlTableModel(this, QSqlmyDB);
    QSqlmodel->setTable("TEST");
    QSqlmodel->select();
    ui->tableView->setModel(QSqlmodel);
}

Table::~Table()
{
    delete ui;
}
