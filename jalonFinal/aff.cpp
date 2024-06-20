#include "aff.h"
#include "ui_aff.h"
#include "basedonne1.h"

aff::aff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aff)
{
    ui->setupUi(this);
    //connect(mw, SIGNAL(envoyerIdContact(QString)), this, SLOT(recevoirIdContact(QString)));
}

aff::~aff()
{
    delete ui;
}




void aff::on_nouvTacheB_clicked()
{
    at=new ajouttache();
    at->show();

}


void aff::on_BQuitter_clicked()
{
    this->close();
}


//void aff::on_pushButton_clicked()
//{
// emit afficherButton();
//}

//void aff::recevoirIdContact(QString idContact)
//{
//    connect(this, SIGNAL(envoyer(QString, QString, QString)), bd, SLOT(recdda(QString, QString, QString)));
//    connect(bd, SIGNAL(sendLIDA(map<Interaction *, list<Tache *>>, Contact *)), this, SLOT(recLIDA(map<Interaction *, list<Tache *>>, Contact *)));
//    connect(bd, SIGNAL(messageLIDA(QString, Contact*)), this, SLOT(recMessageLIDA(QString, Contact *)));

//    // Récupérer l'id du contact sélectionné dans la MainWindow
//    QString id = idContact;

//    // Récupérer les dates du widget aff.ui
//    QString dateDu = ui->dateDu->text();
//    QString dateAu = ui->dateAu->text();

//    // Émettre le signal pour récupérer les données de la base de données
//    emit envoyer(dateDu, dateAu, id);}

void aff::on_pushButton_clicked()
{/*
    connect(bd, SIGNAL(sendLIDA(map<Interaction *, list<Tache *>>, contact *)), this, SLOT(recLIDA(map<Interaction *, list<Tache *>>, Contact *)));
    connect(bd, SIGNAL(messageLIDA(QString, contact*)), this, SLOT(recMessageLIDA(QString, contact *)));*/
}
void aff::recMessageLIDA(QString m, contact *c){
    ui->textEI->clear();
    ui->textEI->append(QString::fromStdString("Contact: "+c->getNom()+" "+c->getPrenom()));
    ui->textEI->append(m);
}
void aff::recLIDA(map<Interaction *, list<Tache *>> it, contact *c) //afficher les taches de chaque interaction et les interaction de chaque contact entre deux dates données
{
    ui->textEI->clear();
    ui->textEI->append(QString::fromStdString("Contact: "+c->getNom()+" "+c->getPrenom()));
    for(auto &i : it)//recuperation du key du hash map
    {
        ui->textEI->append(QString::fromStdString("Interaction: "+i.first->getContenu()+" date: "+i.first->getDI()));
        ui->textEI->append(QString::fromStdString("les taches:"));
        for(auto &l : i.second)//recuperation des valeurs du hashmap
        {
            ui->textEI->append(QString::fromStdString(l->getTexte()+" "+l->getDE
                                                      ()));
        }
        ui->textEI->append("");
    }
}
void aff::affLI(list<Interaction *> li, contact *c) //pour afficher les interactions de chaque contact
{
    ui->textEI->clear();
    ui->textEI->append(QString::fromStdString("Contact: "+c->getPrenom()+" "+c->getNom()));
    for(auto &i : li)
    {
        ui->textEI->append(QString::fromStdString(i->getContenu()+" "+i->getDI()));
    }
}

void aff::recMessageLI(QString m, contact *c) //message a afficher au cas ou aucune interaction existe pour le contact
{
    ui->textEI->clear();
    ui->textEI->append(QString::fromStdString("Contact: "+c->getNom()+" "+c->getPrenom()));
    ui->textEI->append(m);
}
