
#include "database.h"
#include "ui_database.h"
#include "table.h"

Database::Database(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Database)
{
    ui->setupUi(this);
    QSqlmyDB = QSqlDatabase::addDatabase("QSQLITE");
    QSqlmyDB.setDatabaseName("./myDatabase.db");
    if(QSqlmyDB.open())
    {
        ui->statusbar->showMessage("Connected to database");
    }
    else
    {
        ui->statusbar->showMessage("Not connected to database");
    }
    QSqlqry = new QSqlQuery(QSqlmyDB);
    QSqlqry->exec("CREATE TABLE TEST (Title TEXT, Deadline TEXT, Progress TEXT);");

    QSqlmodel = new QSqlTableModel(this, QSqlmyDB);
    QSqlmodel->setTable("TEST");
    QSqlmodel->select();
}

Database::~Database()
{
    delete ui;
    QSqlmyDB.close();
}



void Database::on_pushButton_clicked()
{
    QString title, deadline, progress;
    title = ui->Title->text();
    deadline = ui->Deadline->text();
    progress = ui->Progress->text();
    if (!QSqlmyDB.open())
    {
        QMessageBox::warning(this, "warning", "Database is not connected", QMessageBox::Ok);
    }
    QSqlqry->prepare("INSERT INTO TEST (Title, Deadline, Progress) VALUES (:title, :deadline, :progress)");
    QSqlqry->bindValue(":title", title);
    QSqlqry->bindValue(":deadline", deadline);
    QSqlqry->bindValue(":progress", progress);
    if(QSqlqry->exec())
    {
        ui->statusbar->showMessage("Saved to database");
    }
    else
    {
        QMessageBox::warning(this, "warning", "Database is not connected", QMessageBox::Ok);
    }
}


void Database::on_pushButton_2_clicked()
{
    Table table;
    table.setModal(true);
    table.exec();
}

