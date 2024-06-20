#include "basedonne1.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

#include <QtSql/QSqlQuery>
#include "contact.h"
#include <QtSql>
#include <QSqlError>



/**
 * @brief Constructeur de la classe basedonne1.
 * @param parent L'objet parent.
 */
basedonne1::basedonne1(QObject *parent) : QObject(parent)
{
    connexionBDD();
    //ajouterNouvelleAttribut();
    QSqlQuery query("SELECT * FROM contact", db);

          // Affichez les en-têtes des colonnes
          qDebug() << "En-têtes des colonnes :";
          for (int i = 0; i < query.record().count(); ++i) {
              qDebug() << query.record().fieldName(i);
          }

          // Affichez les données
          while (query.next()) {
              qDebug() << "Nouvelle ligne INTERACTION:";
              for (int col = 0; col < query.record().count(); ++col) {
                  qDebug() << query.record().fieldName(col) << ":" << query.value(col).toString();
              }
          }



}

/**
 * @brief basedonne1::remplirJson
 * @return
 */
//QJsonArray basedonne1::remplirJson()
//{

//    QJsonArray tab;
//    QSqlQuery query;
//    query.prepare("SELECT * from Contact");
//    if(!query.exec())
//    {
//        qDebug() << "error";
//    }
//    else
//    {
//        while(query.next())
//        {
//            QVariantMap map;
//            map.insert("Nom: ",query.value(1));
//            map.insert("Prenom: ",query.value(2));
//            map.insert("Entreprise: ",query.value(3));
//            map.insert("Mail: ",query.value(4));
//            map.insert("Telephone: ",query.value(5));
//            map.insert("Date de creation: ",query.value(6));
//            tab.push_back(QJsonObject::fromVariantMap(map));
//        }
//    }
//    return tab;

//}

/**
 * @brief Destructeur de la classe basedonne1.
 */
basedonne1::~basedonne1()
{
}


/**
 * @brief Méthode de connexion à la base de données.
 */
void basedonne1::connexionBDD()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    //attention à avoir placer le fichier dans le répertoire /tmp
    db.setDatabaseName("/home1/hm036389/HAFSAFINAL/jalonFinal/baseded.sqlite");

      if(!db.open())
      {
          qDebug() << "Pas de connexion BDD !";
      }
      else
      {
          qDebug() << "Connexion BDD ok";
          QSqlQuery query("SELECT * from Personne");

          if(!query.exec())
          {
              qDebug() << "Impossible d'exécuter la requête !";
          }
          else
          {
              qDebug() << "Requête exécutée";
              while(query.next())
              {
                  //le value(0) est l'idPersonne
                  qDebug() << "nom : " << query.value(1).toString();
                  qDebug() << "prenom : " << query.value(2).toString();
                  qDebug() << "age : " << query.value(3).toString();
              }
          }
      }
}


/**
 * @brief Méthode pour recevoir l'ID d'un contact.
 * @param i L'ID du contact.
 */
void basedonne1::recID(string i)
{
    idC=i;
}


/**
 * @brief basedonne1::getIdC getteur
 * @return
 */
string basedonne1::getIdC() const{
    return idC;
}

/**
 * @brief Méthode pour ajouter un contact à la base de données.
 * @param c Pointeur vers l'objet Contact à ajouter.
 */
void basedonne1::basedonne1::ajouterContact(contact *c) //pour ajouter un nouveau contact dans la bd
{
    QSqlQuery query;
    query.prepare("INSERT INTO contact (nom, prenom, entreprise, email, telephone, photo, dateC, dateM) VALUES ( :n, :p, :e, :em, :t, :ph, :dc, :dm)");
    query.bindValue(":n", QString::fromStdString(c->getNom()));
    query.bindValue(":p", QString::fromStdString(c->getPrenom()));
    query.bindValue(":e", QString::fromStdString(c->getEntreprise()));
    query.bindValue(":em", QString::fromStdString(c->getEmail()));
    query.bindValue(":t", QString::fromStdString(c->getTelephone()));
    query.bindValue(":ph", QString::fromStdString(c->getPhoto()));

    query.bindValue(":dc", QString::fromStdString(c->toStringDateC()));
    query.bindValue(":dm", QString::fromStdString(c->toStringDateM()));
    query.exec();

}

/**
 * @brief Méthode pour modifier un contact dans la base de données.
 * @param c Pointeur vers l'objet Contact à modifier.
 */
void basedonne1::modifierContact(contact *c){
    QSqlQuery query;
        query.prepare("UPDATE contact SET nom = :n, prenom = :p, entreprise = :e, email = :em, telephone = :t, photo = :ph, dateC = :dc, dateM = :dm WHERE idC = :id");
        //query.bindValue(":id", QString::fromStdString(c->getIdC())); // Ajoutez une méthode getId() à votre classe Contact
        query.bindValue(":n", QString::fromStdString(c->getNom()));
        query.bindValue(":p", QString::fromStdString(c->getPrenom()));
        query.bindValue(":e", QString::fromStdString(c->getEntreprise()));
        query.bindValue(":em", QString::fromStdString(c->getEmail()));
        query.bindValue(":t", QString::fromStdString(c->getTelephone()));
        query.bindValue(":ph", QString::fromStdString(c->getPhoto()));
        query.bindValue(":dc", QString::fromStdString(c->getDateC()));
        query.bindValue(":dm", QString::fromStdString(c->getDateM()));
        query.exec();
}

/**
 * @brief Met à jour le contact avec l'identifiant spécifié.
 *
 * Cette fonction met à jour les informations du contact en utilisant
 * l'identifiant spécifié et émet un signal pour envoyer le contact mis à jour.
 *
 * @param i Identifiant du contact.
 */

void basedonne1::reception(string i)
{
    idC=i;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    query.prepare("SELECT * from contact WHERE idC="+s+";");
    query.exec();
    while(query.next())
    {
        QString nom= QString(query.value(1).toString());
        QString prenom= QString(query.value(2).toString());
        QString entreprise= QString(query.value(3).toString());
        QString email= QString(query.value(4).toString());
        QString telephone= QString(query.value(5).toString());
        QString photo= QString(query.value(6).toString());
        QString dateC= QString(query.value(7).toString());
        QString dateM= QString(query.value(8).toString());
        c= new contact(nom.toStdString(), prenom.toStdString(), entreprise.toStdString(), email.toStdString(), telephone.toStdString(), photo.toStdString(), dateC.toStdString(), dateM.toStdString());

    }
    emit envoyerContact(c);
}


/**
 * @brief Récupère le nombre total de contacts dans la base de données.
 *
 * Cette fonction exécute une requête SQL pour obtenir le nombre total de contacts
 * dans la base de données et émet un signal pour envoyer le nombre de contacts.
 */
void basedonne1::recNbC(){
    int nb=0;
    QSqlQuery query;
    query.prepare("SELECT COUNT (*) from contact");
    query.exec();
    if(query.next())
    {
        nb=query.value(0).toInt();
    }
    emit NB(nb);
}

/**
 * @brief Reçoit une nouvelle valeur pour l'attribut entreprise et met à jour la base de données.
 *
 * Cette fonction reçoit une nouvelle valeur pour l'attribut entreprise, met à jour la base de données,
 * puis récupère à nouveau le contact et émet un signal pour envoyer le contact mis à jour.
 *
 * @param entreprise Nouvelle valeur pour l'attribut entreprise.
 */

void basedonne1::receiveE(QString e)
{
    ct=new contact();
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    query.prepare("UPDATE contact SET entreprise=:e, dateM=:mdf WHERE idC="+s+";");
    query.bindValue(":e", e);
    query.bindValue(":mdf", QString::fromStdString(ct->toStringDateM()));
    query.exec();
    reception(idC);
}

/**
 * @brief Récupère une liste de contacts créés à une date spécifique et émet un signal.
 *
 * Cette fonction exécute une requête SQL pour récupérer une liste de contacts créés à la date spécifiée.
 * Si des contacts sont trouvés, la liste est envoyée via un signal ; sinon, un message d'erreur est émis.
 *
 * @param date Date spécifique pour laquelle récupérer les contacts.
 */
void basedonne1::recD(QString date){
    bool verif=false;
    list<contact *> lc;
    QSqlQuery query;
    query.prepare("SELECT * from contact WHERE dateC='"+date+"';");
    query.exec();
    while(query.next())
    {
        QString p= QString(query.value(1).toString());
        QString n= QString(query.value(2).toString());
        QString e= QString(query.value(3).toString());
        QString em= QString(query.value(4).toString());
        QString t= QString(query.value(5).toString());
        QString ph= QString(query.value(6).toString());
        QString dc= QString(query.value(7).toString());
        QString de= QString(query.value(8).toString());
        c= new contact(n.toStdString(), p.toStdString(), e.toStdString(), em.toStdString(), t.toStdString(), ph.toStdString(), dc.toStdString(), de.toStdString());
        lc.push_back(c);
        verif=true;
    }
    if(verif)
    {
        emit sendLC(lc);
    }
    else
    {
        emit message("Aucun contact n'a été crée dans cette date !");
    }
}
/**
 * @brief Récupère un contact en fonction du nom de l'entreprise et émet un signal.
 *
 * Cette fonction exécute une requête SQL pour récupérer un contact en fonction du nom de l'entreprise.
 * Si un contact est trouvé, il est envoyé via un signal ; sinon, un message d'erreur est émis.
 *
 * @param entreprise Nom de l'entreprise pour laquelle récupérer le contact.
 */
void basedonne1::recE(QString entreprise){
    bool verif=false;
    QSqlQuery query;
    query.prepare("SELECT * from contact WHERE entreprise='"+entreprise+"';");
    query.exec();
    while(query.next())
    {
        QString n= QString(query.value(1).toString());
        QString p= QString(query.value(2).toString());
        QString e= QString(query.value(3).toString());
        QString em= QString(query.value(4).toString());
        QString t= QString(query.value(5).toString());
        QString ph= QString(query.value(6).toString());
        QString dc= QString(query.value(7).toString());
        QString de= QString(query.value(8).toString());

        c= new contact(n.toStdString(), p.toStdString(), e.toStdString(), em.toStdString(), t.toStdString(), ph.toStdString(), dc.toStdString(), de.toStdString());
        verif=true;
    }
    if(verif)
    {
        emit envoyerContact(c);
    }
    else
    {
        emit message("Impossible de trouver le Contact");
    }
}

/**
 * @brief Récupère un contact en fonction du nom et émet un signal.
 *
 * Cette fonction exécute une requête SQL pour récupérer un contact en fonction du nom.
 * Si un contact est trouvé, il est envoyé via un signal ; sinon, un message d'erreur est émis.
 *
 * @param nom Nom du contact pour lequel récupérer les informations.
 */
void basedonne1::recN(QString nom){
    bool verif=false;
    QSqlQuery query;
    query.prepare("SELECT * from contact WHERE nom='"+nom+"';");
    query.exec();
    while(query.next())
    {
        QString n= QString(query.value(1).toString());
        QString p= QString(query.value(2).toString());
        QString e= QString(query.value(3).toString());
        QString em= QString(query.value(4).toString());
        QString t= QString(query.value(5).toString());
        QString ph= QString(query.value(6).toString());
        QString dc= QString(query.value(7).toString());
        QString de= QString(query.value(8).toString());

        c= new contact(n.toStdString(), p.toStdString(), e.toStdString(), em.toStdString(), t.toStdString(), ph.toStdString(), dc.toStdString(), de.toStdString());
        verif=true;
    }
    if(verif)
    {
        emit envoyerContact(c);
    }
    else
    {
        emit message("Impossible de trouver le Contact");
    }
}

/**
 * @brief Reçoit une nouvelle valeur pour l'attribut email, met à jour la base de données et réceptionne le contact.
 *
 * Cette fonction reçoit une nouvelle valeur pour l'attribut email, met à jour la base de données,
 * puis récupère à nouveau le contact et émet un signal pour envoyer le contact mis à jour.
 *
 * @param m Nouvelle valeur pour l'attribut email.
 */
void basedonne1::receiveEM(QString m)
{
    c=new contact();
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    query.prepare("UPDATE contact SET email=:m, dateM=:mdf WHERE idC="+s+";");
    query.bindValue(":m", m);
    query.bindValue(":mdf", QString::fromStdString(c->toStringDateM()));
    query.exec();
    reception(idC);
}

/**
 * @brief Reçoit une nouvelle valeur pour l'attribut téléphone, met à jour la base de données et réceptionne le contact.
 *
 * Cette fonction reçoit une nouvelle valeur pour l'attribut téléphone, met à jour la base de données,
 * puis récupère à nouveau le contact et émet un signal pour envoyer le contact mis à jour.
 *
 * @param p Nouvelle valeur pour l'attribut téléphone.
 */
void basedonne1::receiveT(QString p)
{
    c=new contact();
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    query.prepare("UPDATE contact SET telephone=:p, dateM=:mdf WHERE idC="+s+";");
    query.bindValue(":p", p);
    query.bindValue(":mdf", QString::fromStdString(c->toStringDateM()));
    query.exec();
    reception(idC);
}

/**
 * @brief Supprime le contact de la base de données et toutes les interactions associées.
 *
 * Cette fonction supprime le contact de la base de données ainsi que toutes les interactions associées
 * en exécutant des requêtes SQL appropriées.
 */
void basedonne1::r2supp(){
    list<QString> idI;
    list<QString> idT;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;

    query.prepare(("DELETE FROM contact WHERE idC="+s+";"));
    query.exec();
    query.prepare(("DELETE FROM interaction WHERE idC="+s+";"));
    query.exec();
}



/**
 * @brief Met à jour les données existantes en assignant une valeur spécifique à la colonne 'idI' dans la table 'tache'.
 *
 * Cette fonction exécute une requête SQL pour mettre à jour les données existantes en assignant la valeur '0'
 * à la colonne 'idI' dans la table 'tache' pour les entrées où 'idI' est NULL.
 * Si la requête échoue, un message d'erreur est affiché via qDebug().
 */
void basedonne1::mettreAJourNouvelAttribut() {
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE tache SET idI = '0' WHERE idI IS NULL");
    if (!updateQuery.exec()) {
        qDebug() << "Erreur lors de la mise à jour des données existantes:" << updateQuery.lastError().text();
    }
}

/**
 * @brief Ajoute une nouvelle colonne 'idI' de type INTEGER à la table 'tache'.
 *
 * Cette fonction exécute une requête SQL pour ajouter une nouvelle colonne 'idI' de type INTEGER à la table 'tache'.
 * Elle affiche un message de réussite ou d'erreur via qDebug().
 */
void basedonne1:: ajouterNouvelleAttribut(){
     QSqlQuery query;
     query.prepare("ALTER TABLE tache ADD COLUMN idI INTEGER");
             if(query.exec()) {
                 qDebug()<<"La colonne a été ajoutée avec succès.";

     }else{
                 QSqlError error = query.lastError();
                 qDebug()<<"Erreur lors de l'ajout de la colonne :"<<error.text();
             }
}


/**
 * @brief Ajoute une nouvelle interaction à la base de données.
 *
 * Cette fonction prend un objet Interaction en paramètre, extrait les informations nécessaires, puis
 * exécute une requête SQL pour insérer ces informations dans la table 'interaction'.
 * Elle affiche un message de réussite via qDebug().
 *
 * @param I Pointeur vers l'objet Interaction à ajouter à la base de données.
 */
void basedonne1::recInteraction(Interaction *I) //ajouter une interaction a la base de donnée
{

    QSqlQuery query;

    query.prepare("INSERT INTO interaction (idC, contenu, di) VALUES ( :c, :t, :d)");
    query.bindValue(":c", QString::fromStdString(idC));
    query.bindValue(":t", QString::fromStdString(I->getContenu()));
    query.bindValue(":d", QString::fromStdString(I->getDI()));
   // query.exec();
    if(query.exec()){
        qDebug()<<"Insertion réussie";

    }
    QString inter=QString::fromStdString(I->getContenu());
    query.prepare("SELECT * from interaction WHERE contenu='"+inter+"';");
    query.exec();
    while(query.next())
    {
        QString id=QString(query.value(0).toString());
        idI=id.toStdString();
    }


}
/**
 * @brief Récupère les interactions et les tâches associées pour un contact entre deux dates spécifiques.
 *
 * Cette fonction exécute des requêtes SQL pour récupérer les interactions et les tâches associées à un contact
 * entre deux dates spécifiées. Elle émet un signal avec les résultats ou un message d'erreur.
 *
 * @param du Date de début.
 * @param au Date de fin.
 * @param i Identifiant du contact.
 */
void basedonne1::recdda(QString du, QString au, string i)
{
    map<Interaction *, list<Tache *>> it;
    list<Tache *> lt;
    idC=i;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    bool verif=false;
    query.prepare("SELECT * from interaction WHERE idC="+s+" and di between '"+du+"' and '"+au+"';");
    query.exec();
    while(query.next())
    {
        QString idi=QString(query.value(0).toString());
        QString in=QString(query.value(1).toString());
        QString din=QString(query.value(2).toString());
        QSqlQuery quer;
        quer.prepare("SELECT * from tache WHERE idI="+idi+";");
        quer.exec();
        while(quer.next())
        {
            QString idt=QString(quer.value(0).toString());
            QSqlQuery qr;
            qr.prepare("SELECT * from tache WHERE idT="+idt+";");
            qr.exec();
            while(qr.next())
            {
                QString ct=QString(qr.value(1).toString());
                QString dt=QString(qr.value(2).toString());
                T=new Tache(ct.toStdString(), dt.toStdString());
                lt.push_back(T);
            }

        }
        I=new Interaction(in.toStdString(), din.toStdString());
        it[I]=lt;
        lt.clear();
        verif=true;
    }

    //selectionner Contact
    query.prepare("SELECT * from contact WHERE idC="+s+";");
    query.exec();
    while(query.next())
    {
        QString ln=QString(query.value(1).toString());
        QString fn=QString(query.value(2).toString());
        c=new contact(ln.toStdString(), fn.toStdString());
    }


    if(verif)
    {
        emit sendLIDA(it,c);
    }
    else
    {
        emit messageLIDA("//Ce contact n'a aucune interaction entre ces deux dates", c);
    }

}

/**
 * @brief Récupère les interactions associées à un contact et émet un signal avec les résultats.
 *
 * Cette fonction exécute une requête SQL pour récupérer les interactions associées à un contact
 * en fonction de son identifiant. Elle émet un signal avec les résultats ou un message d'erreur.
 *
 * @param i Identifiant du contact.
 */
void basedonne1::recIDCI(string i)
{
    idC=i;
    bool verif=false;
    list<Interaction *> li;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    //selection interaction
    query.prepare("SELECT * from interaction WHERE idC="+s+";");
    query.exec();
    while(query.next())
    {
        QString in=QString(query.value(1).toString());
        QString din=QString(query.value(2).toString());
        I=new Interaction(in.toStdString(),din.toStdString());
        li.push_back(I);
        verif=true;
    }


    //selectionner Contact
    query.prepare("SELECT * from contact WHERE idC="+s+";");
    query.exec();
    while(query.next())
    {
        QString n=QString(query.value(1).toString());
        QString p=QString(query.value(2).toString());
        c=new contact(n.toStdString(), p.toStdString());
    }

    if(verif)
    {
        emit sendLI(li,c);
    }
    else
    {
        emit messageLI("//Ce contact n'a aucune interaction.", c);
    }

}
//void basedonne1::recN(QString nom)
//{
//    bool verif=false;
//    QSqlQuery query;
//    query.prepare("SELECT * from contact WHERE nom='"+nom+"';");
//    query.exec();
//    while(query.next())
//    {
//        QString ln= QString(query.value(1).toString());
//        QString fn= QString(query.value(2).toString());
//        QString e= QString(query.value(3).toString());
//        QString m= QString(query.value(4).toString());
//        QString t= QString(query.value(5).toString());
//        QString ph= QString(query.value(6).toString());
//        QString dc= QString(query.value(7).toString());
//        QString de= QString(query.value(8).toString());

//        c= new contact(ln.toStdString(), fn.toStdString(), e.toStdString(), m.toStdString(), t.toStdString(), ph.toStdString(), dc.toStdString(), de.toStdString());
//        verif=true;
//    }
//    if(verif)
//    {
//        emit envoyerContact(c);
//    }
//    else
//    {
//        emit message("Impossible de trouver le Contact");
//    }
//}
/**
 * @brief Récupère les interactions et les tâches associées à un contact, puis émet un signal avec les résultats.
 *
 * Cette fonction exécute des requêtes SQL pour récupérer les interactions et les tâches associées à un contact
 * en fonction de son identifiant. Elle construit une structure de données pour stocker les résultats, puis émet
 * un signal avec cette structure. Si le contact n'a aucune interaction, un message d'erreur est émis.
 *
 * @param i Identifiant du contact.
 */
void basedonne1::recIDCIT(string i)
{
    idC=i;
    bool ok=false;
    tache=new Tache();
    list<Interaction *> li;
    QString s=QString::fromStdString(idC);
    QSqlQuery query;
    //selection interaction
    query.prepare("SELECT * from interaction WHERE idC="+s+";");
    query.exec();
    while(query.next())
    {
        QString in=QString(query.value(1).toString());
        QString din=QString(query.value(2).toString());
        QString id=QString(query.value(0).toString());
        I=new Interaction(in.toStdString(),din.toStdString());
        I->setId(id.toStdString());

        li.push_back(I);

    }
    //selectionner Contact
    query.prepare("SELECT * from contact WHERE idC="+s+";");
    query.exec();
    while(query.next())
    {
        QString n=QString(query.value(1).toString());
        QString p=QString(query.value(2).toString());
        c=new contact();
    c->setNom(n.toStdString());
    c->setPrenom(p.toStdString());
    }

    //selectionner les taches
    for( Interaction *inter:li)
    {
        QString k=QString::fromStdString(inter->getId());
        query.prepare("SELECT * from tache WHERE idI="+k+";");
        query.exec();
        while(query.next())
        {
            QString contenu=QString(query.value(1).toString());
            QString date=QString(query.value(2).toString());
            tache->setDE(date.toStdString());
            tache->setTexte(contenu.toStdString());
            inter->ajouterTache(*tache);
           // qDebug() << "tache : " << tache->getTexte().c_str() << ", Date : " << tache->getDE().c_str();
              ok=true;
        }
    }
    if(ok)
        emit sendLCIT(li,c);
    else
        emit messageLITI("//Ce contact n'a aucune tache à faire.",c);
}

QJsonArray basedonne1::exporterEnJSON()
{
    QJsonArray tableauExport;

    // Exporter les contacts
    QSqlQuery queryContacts("SELECT * FROM contact");
    while (queryContacts.next())
    {
        QJsonObject contactJson;
        contactJson["nom"] = queryContacts.value(1).toString();
        contactJson["prenom"] = queryContacts.value(2).toString();
        contactJson["entreprise"] = queryContacts.value(3).toString();
        contactJson["email"] = queryContacts.value(4).toString();
        contactJson["telephone"] = queryContacts.value(5).toString();
        contactJson["photo"] = queryContacts.value(6).toString();
        contactJson["dateC"] = queryContacts.value(7).toString();
        contactJson["dateM"] = queryContacts.value(8).toString();

        tableauExport.append(contactJson);
    }

    // Exporter les interactions
    QSqlQuery queryInteractions("SELECT * FROM interaction");
    while (queryInteractions.next())
    {
        QJsonObject interactionJson;
        interactionJson["idC"] = queryInteractions.value(0).toString();
        interactionJson["contenu"] = queryInteractions.value(1).toString();
        interactionJson["di"] = queryInteractions.value(2).toString();

        tableauExport.append(interactionJson);
    }

    // Exporter les tâches
    QSqlQuery queryTaches("SELECT * FROM tache");
    while (queryTaches.next())
    {
        QJsonObject tacheJson;
        tacheJson["idI"] = queryTaches.value(0).toString();
        tacheJson["texte"] = queryTaches.value(1).toString();
        tacheJson["de"] = queryTaches.value(2).toString();

        tableauExport.append(tacheJson);
    }

    return tableauExport;
}

/**
 * @brief Ajoute une nouvelle tâche à la base de données.
 *
 * Cette fonction prend un objet Tache en paramètre, extrait les informations nécessaires, puis exécute une
 * requête SQL pour insérer ces informations dans la table 'tache'. Elle affiche un message de réussite via qDebug().
 *
 * @param T Pointeur vers l'objet Tache à ajouter à la base de données.
 */
void basedonne1::recTache(Tache *T) //ajouter une tache a la base de donnée
{

    QSqlQuery query;
    //for (const Tache* T : l) {
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO tache (texte,de,idI ) VALUES (:t, :d,:idI)");
        insertQuery.bindValue(":idI",std::stoi(this->idI));
        insertQuery.bindValue(":t", QString::fromStdString(T->getTexte()));
        insertQuery.bindValue(":d", QString::fromStdString(T->getDE()));

        if (insertQuery.exec()) {
            qDebug() << "Insertion avec succès à la table Todo.";
        } else {
            qDebug() << "Erreur lors de l'ajout de l'enregistrement à la table Todo:" << insertQuery.lastError().text();
        }
    //}
//    //InterTodo
//    QString inter=QString::fromStdString(T->getTexte());
//    query.prepare("SELECT * from tache WHERE texte='"+inter+"';");
//    query.exec();
//    while(query.next())
//    {
//        QString id=QString(query.value(0).toString());
//        idT=id.toStdString();
//    }
}

