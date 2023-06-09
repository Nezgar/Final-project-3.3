#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Table;
}

class Table : public QDialog
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

private:
    Ui::Table *ui;
    QSqlDatabase QSqlmyDB;
    QSqlQuery *QSqlqry;
    QSqlTableModel *QSqlmodel;
};

#endif // TABLE_H
