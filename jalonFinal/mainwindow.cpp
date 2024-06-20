#include "mainwindow.h"
#include "qsqlquery.h"
#include "ui_mainwindow.h"
#include <QDebug>

//Json
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>


/**
     * @brief Constructeur de la classe MainWindow.
     * @param parent Pointeur vers le widget parent.
     */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bd=new basedonne1();
    afficherListe();



    //connect(ac, SIGNAL(enregistrerContact(Contact*)), this, SLOT(enregistrerEtMajListe(Contact*)));
    //connect(af,SIGNAL(afficherButton()),this,SLOT(onAfficherButton()));

}
void MainWindow::sauvegarderEnJSON()
{
    QJsonDocument document;
       document.setArray(bd->exporterEnJSON());
      QFile fichier("/home1/hm036389/HAFSAFINAL/jalonFinal/texte.json");
       fichier.open(QFile::WriteOnly);
       fichier.write(document.toJson());
}
//void MainWindow::json() //json
//{
//    QJsonDocument document;
//    document.setArray(bd->remplirJson());
//    QFile fichier("//home/simo/Documents/era/Projet_CDAA/text.json");
//    fichier.open(QFile::WriteOnly);
//    fichier.write(document.toJson());
//}

/**
    * @brief Destructeur de la classe MainWindow.
    */
MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_actionAjouter_un_contact_triggered()
//{
//    ac = new ajoutcontact();
//    ac -> show();
//    connect(ac, SIGNAL(contactEnregistre(contact*)), bd, SLOT(ajouterContact(contact *)));
//    connect(ac ,SIGNAL(majListe()), this, SLOT(majListeContact()));

//}




/**
 * @brief Affiche les interactions d'un contact dans l'interface utilisateur.
 * @param li Liste des interactions associées au contact.
 * @param c Pointeur vers l'objet contact concerné.
 */
void MainWindow::recLI(list<Interaction *> li, contact *c) //pour afficher les interactions de chaque contact
{
    ui->textEdit->clear();

    ui->textEdit->append(QString::fromStdString("Contact: "+c->getNom()+" "+c->getPrenom()));
    for(auto &i : li)
    {
        ui->textEdit->append(QString::fromStdString(i->getContenu()+" "+i->getDI()));
    }
}

/**
 * @brief Affiche un message dans l'interface utilisateur en cas d'absence d'interactions pour un contact.
 * @param m Message à afficher.
 * @param c Pointeur vers l'objet contact concerné.
 */
void MainWindow::recMessageLI(QString m, contact *c) //message a afficher au cas ou aucune interaction existe pour le contact
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getNom()+" "+c->getPrenom()));
    ui->textEdit->append(m);
}
//void MainWindow::on_tacheB_clicked()
//{
//    a=new aff();
//    a->show();
//}




//void MainWindow::on_listeContact_itemDoubleClicked()
//{
//    f=new formulaire();
//    f->show();
//      connect(bd, SIGNAL(envoyerContact(contact *)), f, SLOT(receiveContact(contact *)));
//      connect(this, SIGNAL(select(string)), bd, SLOT(reception(string)));

//      connect(f, SIGNAL(envoyerE(QString)), bd, SLOT(receiveE(QString)));
//      connect(f, SIGNAL(envoyerEM(QString)), bd, SLOT(receiveEM(QString)));
//      connect(f, SIGNAL(envoyerT(QString)), bd, SLOT(receiveT(QString)));
//      connect(f, SIGNAL(envoyerS()), bd, SLOT(r2supp()));
//      connect(f, SIGNAL(envoyerS()), this, SLOT(majListeContact()));


//    string l=ui->listeContact->currentItem()->text().toStdString();
//    string nv="";
//    bool veri=false;
//    for(int i=0;!veri;i++)
//    {
//        if(l[i]!='-')
//        {
//            nv+=l[i];
//        }
//        else
//        {
//            veri=true;
//        }
//    }
//    emit select(nv);


//}
/**
 * @brief Met à jour la liste des contacts dans l'interface utilisateur.
 * @details Connecte différents signaux et slots pour récupérer le nombre de contacts, mettre à jour la liste,
 *          afficher le nombre de contacts, et émettre un signal pour informer d'autres composants du nombre de contacts.
 *          Appelle également la fonction d'affichage de la liste et de sauvegarde au format JSON.
 */
void MainWindow:: majListeContact(){
    connect(this, SIGNAL(envNB()), bd, SLOT(recNbC()));
    connect(bd, SIGNAL(NB(int)), this, SLOT(NbCRec(int)));
    ui->listeContact->clear();
    afficherListe();
    sauvegarderEnJSON();

    emit envNB();
}

/**
 * @brief Affiche la liste des contacts dans l'interface utilisateur.
 * @details Connecte différents signaux et slots pour récupérer le nombre de contacts,
 *          mettre à jour la liste, afficher le nombre de contacts, et émettre un signal pour informer d'autres composants du nombre de contacts.
 *          Utilise également une requête SQL pour récupérer les données de contact depuis la base de données.
 */
void MainWindow::afficherListe(){
    connect(this, SIGNAL(envNB()), bd, SLOT(recNbC()));
    connect(bd, SIGNAL(NB(int)), this, SLOT(NbCRec(int)));
    QSqlQuery query;
    query.prepare("SELECT * from contact");
    query.exec();
    while(query.next())
    {
        //recuperer l'id, nom et prenom de chaque contact du tableau Contact de la base de donnée
        QString l=QString(query.value(0).toString()+"-"+query.value(1).toString()+" "+query.value(2).toString());
        ui -> listeContact ->addItem(l);
    }
    emit envNB();
}

/**
 * @brief Met à jour le nombre de contacts affiché dans l'interface utilisateur.
 * @param nb Le nombre de contacts à afficher.
 */
void MainWindow::NbCRec(int nb){
    ui->nbContacts->clear();
    ui->nbContacts->setText(QString::number(nb));
}

//void MainWindow::on_listeContact_itemClicked(QListWidgetItem *item)
//{
//    QString idContact = item->text().section("-", 0, 0); // Récupérer l'ID du contact
//        emit envoyerIdContact(idContact);
//}


//void MainWindow::on_InterB_clicked()
//{
//    ai=new ajouinteraction();
//    ai->show();
//    //recuperation de l'id du contact qui a été selectionné dans la qlistWidget
//    string l=ui->listeContact->currentItem()->text().toStdString();
//    string nv="";
//    connect(this, SIGNAL(selectC(string)), bd, SLOT(recID(string)));
//    connect(ai, SIGNAL(envoyerInteraction(Interaction *)), bd, SLOT(recInteraction(Interaction *)));
//    connect(ai, SIGNAL(envoyerTache(Tache *)), bd, SLOT(recTache(Tache *)));
//    bool veri=false;
//    for(int i=0;!veri;i++)
//    {
//        if(l[i]!='-')
//        {
//            nv+=l[i];
//        }
//        else
//        {
//            veri=true;
//        }
//    }
//    emit selectC(nv);//envoyer l'id du contact qui a été selectionné via un signal à la classe basedonnee
//}

/**
 * @brief Crée une nouvelle fenêtre pour ajouter une interaction à un contact.
 * @details Cette fonction est déclenchée lorsque le bouton "Ajouter Interaction" est cliqué.
 *          Elle crée une instance de la classe "ajouinteraction", affiche la fenêtre et connecte
 *          différents signaux et slots pour gérer la communication entre la fenêtre d'ajout d'interaction
 *          et la classe "basedonnee".
 */
void MainWindow::on_InterB_3_clicked()
{
    ai=new ajouinteraction();
        ai->show();
        //recuperation de l'id du contact qui a été selectionné dans la qlistWidget
        string l=ui->listeContact->currentItem()->text().toStdString();
        string nv="";
        connect(this, SIGNAL(selectC(string)), bd, SLOT(recID(string)));
        connect(ai, SIGNAL(envoyerInteraction(Interaction *)), bd, SLOT(recInteraction(Interaction *)));
        connect(ai, SIGNAL(envoyerTache(Tache *)), bd, SLOT(recTache(Tache *)));
        bool veri=false;
        for(int i=0;!veri;i++)
        {
            if(l[i]!='-')
            {
                nv+=l[i];
            }
            else
            {
                veri=true;
            }
        }
        emit selectC(nv);//envoyer l'id du contact qui a été selectionné via un signal à la classe basedonnee
    }


/**
 * @brief Crée une nouvelle fenêtre pour ajouter une tâche à un contact.
 * @details Cette fonction est déclenchée lorsque le bouton "Ajouter Tâche" est cliqué.
 *          Elle crée une instance de la classe "ajouttache", affiche la fenêtre et connecte
 *          différents signaux et slots pour gérer la communication entre la fenêtre d'ajout de tâche
 *          et la classe "basedonnee".
 */



//void MainWindow::on_tacheB2_clicked()
//{

//        at=new ajouttache();
//        at->show();
//        connect(at, SIGNAL(envoyerTache(Tache *)), bd, SLOT(recTache(Tache *)));
//        string l=ui->listeContact->currentItem()->text().toStdString();
//        string nv="";

//        bool veri=false;
//        for(int i=0;!veri;i++)
//        {
//            if(l[i]!='-')
//            {
//                nv+=l[i];
//            }
//            else
//            {
//                veri=true;
//            }
//        }
//        emit selectC(nv);//envoyer l'id du contact qui a été selectionné via un signal à la classe basedonnee
//    }

/**
 * @brief Crée une nouvelle fenêtre pour afficher et modifier les détails d'un contact.
 * @details Cette fonction est déclenchée lorsque l'utilisateur double-clique sur un contact dans la liste.
 *          Elle crée une instance de la classe "formulaire", affiche la fenêtre et connecte
 *          différents signaux et slots pour gérer la communication entre la fenêtre de formulaire
 *          et la classe "basedonnee".
 */
void MainWindow::on_listeContact_itemDoubleClicked()
{
    f=new formulaire();
    f->show();
          connect(bd, SIGNAL(envoyerContact(contact *)), f, SLOT(receiveContact(contact *)));
          connect(this, SIGNAL(select(string)), bd, SLOT(reception(string)));

          connect(f, SIGNAL(envoyerE(QString)), bd, SLOT(receiveE(QString)));
          connect(f, SIGNAL(envoyerEM(QString)), bd, SLOT(receiveEM(QString)));
          connect(f, SIGNAL(envoyerT(QString)), bd, SLOT(receiveT(QString)));
          connect(f, SIGNAL(envoyerS()), bd, SLOT(r2supp()));
          connect(f, SIGNAL(envoyerS()), this, SLOT(majListeContact()));


        string l=ui->listeContact->currentItem()->text().toStdString();
        string nv="";
        bool veri=false;
        for(int i=0;!veri;i++)
        {
            if(l[i]!='-')
            {
                nv+=l[i];
            }
            else
            {
                veri=true;
            }
        }
        emit select(nv);


}

/**
 * @brief Crée une nouvelle fenêtre pour ajouter un nouveau contact.
 * @details Cette fonction est déclenchée lorsque l'utilisateur sélectionne l'option "Ajouter un contact" dans le menu.
 *          Elle crée une instance de la classe "ajoutcontact", affiche la fenêtre et connecte
 *          différents signaux et slots pour gérer la communication entre la fenêtre d'ajout de contact
 *          et la classe "basedonnee".
 */
void MainWindow::on_actionAjouter_un_contact_triggered()
{
    ac = new ajoutcontact();
    ac -> show();
        connect(ac, SIGNAL(contactEnregistre(contact*)), bd, SLOT(ajouterContact(contact *)));
        connect(ac ,SIGNAL(majListe()), this, SLOT(majListeContact()));
}

/**
 * @brief Crée une nouvelle fenêtre pour effectuer une recherche avancée.
 * @details Cette fonction est déclenchée lorsque l'utilisateur sélectionne l'option "Rechercher" dans le menu.
 *          Elle crée une instance de la classe "rechercher", affiche la fenêtre et connecte
 *          différents signaux et slots pour gérer la communication entre la fenêtre de recherche
 *          et la classe "basedonnee".
 */
void MainWindow::on_actionRechercher_triggered()
{
    r=new rechercher();
    r->show();
    connect(r, SIGNAL(envN(QString)), bd, SLOT(recN(QString)));
    connect(r, SIGNAL(envE(QString)), bd, SLOT(recE(QString)));
    connect(r, SIGNAL(envD(QString)), bd, SLOT(recD(QString)));
    connect(bd, SIGNAL(envoyerContact(contact *)), r, SLOT(receptionC(contact *)));
    connect(bd, SIGNAL(message(QString)), r, SLOT(recMessage(QString)));
    connect(bd, SIGNAL(sendLC(list<contact *>)), r, SLOT(recLC(list<contact *>)));

}



/**
 * @brief Effectue une recherche d'interactions pour le contact sélectionné.
 * @details Cette fonction est déclenchée lorsque l'utilisateur clique sur le bouton "Interactions".
 *          Elle récupère l'id du contact sélectionné dans la QListWidget, émet un signal vers la classe "basedonnee"
 *          pour récupérer les interactions associées à ce contact, et connecte différents signaux et slots pour afficher
 *          les résultats dans la fenêtre principale.
 */
void MainWindow::on_InterB1_clicked()
{   //ui->textEdit->clear();
    connect(this, SIGNAL(selectC(string)), bd, SLOT(recIDCI(string)));


    connect(bd, SIGNAL(sendLI(list<Interaction *>, contact *)), this, SLOT(recLI(list<Interaction *>, contact *)));
    connect(bd, SIGNAL(messageLI(QString, contact *)), this, SLOT(recMessageLI(QString, contact *)));
    //recuperation de l'id du contact qui a été selectionné dans la qlistWidget
    string l=ui->listeContact->currentItem()->text().toStdString();
    string nv="";
    bool veri=false;
    for(int i=0;!veri;i++)
    {
        if(l[i]!='-')
        {
            nv+=l[i];
        }
        else
        {
            veri=true;
        }
    }
    emit selectC(nv);//envoyer l'id du contact qui a été selectionné dans la qlistWidget à la classe basedonnee
}

/**
 * @brief Effectue une recherche de tâches pour le contact sélectionné.
 * @details Cette fonction est déclenchée lorsque l'utilisateur clique sur le bouton "Tâches".
 *          Elle récupère l'id du contact sélectionné dans la QListWidget, émet un signal vers la classe "basedonnee"
 *          pour récupérer les tâches associées à ce contact, et connecte différents signaux et slots pour afficher
 *          les résultats dans la fenêtre principale.
 */
void MainWindow::on_tacheB_clicked()
{   connect(this, SIGNAL(selectC(string)), bd, SLOT(recIDCIT(string)));

    connect(bd, SIGNAL(sendLCIT(list<Interaction *>, contact *)), this, SLOT(affichIt(list<Interaction *>, contact *)));
    connect(bd, SIGNAL(messageLITI(string, contact *)), this, SLOT(recupMessageLITI(string, contact *)));
    //recuperation de l'id du contact selectionné
    string l=ui->listeContact->currentItem()->text().toStdString();
    string nv="";
    bool veri=false;
    for(int i=0;!veri;i++)
    {
        if(l[i]!='-')
        {
            nv+=l[i];
        }
        else
        {
            veri=true;
        }

}
 emit selectC(nv);
}
/**
 * @brief Affiche les interactions et les tâches associées à un contact dans la fenêtre principale.
 * @details Cette fonction est utilisée pour afficher les résultats d'une recherche d'interactions et de tâches pour un contact.
 * @param it Map contenant les interactions et les listes de tâches associées à un contact.
 * @param c Pointeur vers le contact sélectionné.
 */
//pour afficher les taches de chaque interaction et les interactions de chaque contact


void MainWindow::affichIt(list<Interaction *>li, contact *ca)
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact :"+ca->getNom()+" "+ca->getPrenom()+""));
    for(Interaction *i:li)
    {
        ui->textEdit->append(QString::fromStdString("Interaction: "));
        ui->textEdit->append(QString::fromStdString("\t"+i->getContenu()+ " date :"+i->getDI()));
        ui->textEdit->append(QString::fromStdString("Les taches:"));
        for(Tache t:i->getLtache())
        {

            ui->textEdit->append(QString::fromStdString("\t"+t.getTexte()+" "+t.getDE()));
        }
        ui->textEdit->append(QString::fromStdString("\n"));
    }




}


/**
 * @brief Affiche un message pour le contact lorsqu'aucune interaction n'est disponible.
 * @details Cette fonction est utilisée pour afficher un message spécifique au contact lorsqu'aucune interaction n'est trouvée.
 * @param m Message à afficher.
 * @param c Pointeur vers le contact sélectionné.
 */

void MainWindow::recupMessageLITI(string m, contact* c){
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getNom()+" "+c->getPrenom()));
    ui->textEdit->append(QString::fromStdString(m));
}

/**
 * @brief Effectue une recherche d'interactions et de tâches pour le contact sélectionné entre deux dates données.
 * @details Cette fonction est déclenchée lorsque l'utilisateur clique sur le bouton "Rechercher" pour les interactions
 *          et les tâches entre deux dates. Elle récupère l'id du contact sélectionné dans la QListWidget, les dates
 *          spécifiées dans les champs d'édition, émet un signal vers la classe "basedonnee" pour récupérer les
 *          interactions et les tâches associées à ce contact dans la plage de dates spécifiée, et connecte différents
 *          signaux et slots pour afficher les résultats dans la fenêtre principale.
 */
void MainWindow::on_pushButton_clicked()
{
    connect(this, SIGNAL(envoyer(QString, QString, string)), bd, SLOT(recdda(QString, QString, string)));
    connect(bd, SIGNAL(sendLIDA(map<Interaction *, list<Tache *>>, contact *)), this, SLOT(recupListeIDA(map<Interaction *, list<Tache *>>, contact *)));
    connect(bd, SIGNAL(messageLIDA(QString, contact*)), this, SLOT(recupMessageListeIDA(QString, contact *)));
    //recuperation de l'id du contact qui a été selectionne dans qlistWidget
    string l=ui->listeContact->currentItem()->text().toStdString();
    string nv="";
    bool veri=false;
    for(int i=0;!veri;i++)
    {
        if(l[i]!='-')
        {
            nv+=l[i];
        }
        else
        {
            veri=true;
        }
    }
    QString dateDu=ui->dateEditDu->text();
    QString dateAu=ui->dateEditAu->text();
    emit envoyer(dateDu,dateAu,nv);
}


/**
 * @brief Affiche les interactions et les tâches associées à un contact dans la fenêtre principale
 *        pour une plage de dates donnée.
 * @details Cette fonction est utilisée pour afficher les résultats d'une recherche d'interactions et de tâches
 *          pour un contact dans une plage de dates spécifiée.
 * @param it Map contenant les interactions et les listes de tâches associées à un contact.
 * @param c Pointeur vers le contact sélectionné.
 */
void MainWindow::recupListeIDA(map<Interaction *, list<Tache *>> it, contact *c) //afficher les taches de chaque interaction et les interaction de chaque contact entre deux dates données
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getNom()+" "+c->getPrenom()));
    for(auto &i : it)//recuperation du key du hash map
    {
        ui->textEdit->append(QString::fromStdString("Interaction: "+i.first->getContenu()+" date: "+i.first->getDI()));
        ui->textEdit->append(QString::fromStdString("les taches:"));
        for(auto &l : i.second)//recuperation des valeurs du hashmap
        {
            ui->textEdit->append(QString::fromStdString(l->getTexte()+" "+l->getDE()));
        }
        ui->textEdit->append("");
    }
}

/**
 * @brief Affiche un message pour le contact lorsqu'aucune interaction n'est disponible
 *        pour une plage de dates donnée.
 * @details Cette fonction est utilisée pour afficher un message spécifique au contact lorsqu'aucune interaction
 *          n'est trouvée pour une plage de dates spécifiée.
 * @param m Message à afficher.
 * @param c Pointeur vers le contact sélectionné.
 */
void MainWindow::recupMessageListeIDA(QString m, contact *c) //message a afficher au cas ou aucune interaction existe pour le contact
{
    ui->textEdit->clear();
    ui->textEdit->append(QString::fromStdString("Contact: "+c->getNom()+" "+c->getPrenom()));
    ui->textEdit->append(m);
}
