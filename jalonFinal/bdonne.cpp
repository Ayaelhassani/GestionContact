#include "bdonne.h"

bdonne::bdonne(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home1/hm036389/jalonFinal/baseded.sqlite");
    db.open();


}
bdonne::~bdonne(){
    db.close();
}
