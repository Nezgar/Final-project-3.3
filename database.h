
#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class Database; }
QT_END_NAMESPACE

class Database : public QMainWindow

{
    Q_OBJECT

public:
    Database(QWidget *parent = nullptr);
    ~Database();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Database *ui;
    QSqlDatabase QSqlmyDB;
    QSqlQuery *QSqlqry;
    QSqlTableModel *QSqlmodel;
};

#endif // DATABASE_H
