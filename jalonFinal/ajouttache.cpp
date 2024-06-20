#include "ajouttache.h"
#include "tache.h"
#include "ui_ajouttache.h"

ajouttache::ajouttache(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajouttache)
{
    ui->setupUi(this);
}

ajouttache::~ajouttache()
{
    delete ui;
}





