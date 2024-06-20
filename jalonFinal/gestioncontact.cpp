#include "gestioncontact.h"
//#include <gestion.h>
#include <contact.h>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>


gestionContact::gestionContact()
{
    // Initialiser la base de données SQLite
       /* QSqlDatabase db;
        db= QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("/tmp/base.sqlite");

        if (!db.open()) {
            qDebug() << "Pas de connexion à la BD" ;
            return;
        }

        // Créer la table des contacts
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS contacts ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "prenom TEXT,"
                   "nom TEXT,"
                   "entreprise TEXT,"
                   "email TEXT,"
                   "telephone TEXT,"
                   "photo TEXT,"
                   "dateCreation TEXT)");*/
}
/**
 * @brief gestionContact::~gestionContact Destructeur de la classe gestionContact
 */
gestionContact::~gestionContact(){

}
/**
 * @brief Ajoute un contact à la liste de contacts gérée par cette classe.
 *
 * @param c Le contact à ajouter.
 */
void gestionContact::ajoutContact(const contact &c) {
    listedeContacts.push_back(c);
    std::cout << "Contact a bien été ajouté : " << c.getPrenom()<< " " << c.getNom() << std::endl;

}
/**
 * @brief Modifie les informations d'un contact.
 *
 * @param c Le contact à modifier.
 * @param nouveauNom Le nouveau nom du contact.
 * @param nouveauPrenom Le nouveau prénom du contact.
 * @param nouvelleEntreprise La nouvelle entreprise du contact.
 * @param nouvelEmail Le nouvel email du contact.
 * @param nouveauTelephone Le nouveau numéro de téléphone du contact.
 * @param nouvellePhoto Le nouveau chemin de la photo du contact.
 */
void gestionContact::modifierContact(contact& c, const std::string& nouveauNom, const std::string& nouveauPrenom, const std::string& nouvelleEntreprise, const std::string& nouvelEmail, const std::string& nouveauTelephone, const std::string& nouvellePhoto, const string nouvelleDateCreation,const string& nouvelleDateModification) {

    c.getNom() = nouveauNom;
    c.getPrenom() = nouveauPrenom;
    c.getEntreprise() = nouvelleEntreprise;
    c.getEmail() = nouvelEmail;
    c.getTelephone() = nouveauTelephone;
    c.getPhoto() = nouvellePhoto;
    c.getDateC()= nouvelleDateCreation;
    c.getDateM()=nouvelleDateModification;

    std::cout << "Contact a été modifié : " << c.getPrenom()<< " " << c.getNom() << std::endl;
}
/**
 * @brief Supprime un contact de la liste de contacts gérée par cette classe.
 *
 * @param c Le contact à supprimer.
 */

void gestionContact::supprimerContact(contact& c) {
    // Marquer le contact comme supprimé
    for(auto it=listedeContacts.begin();it!=listedeContacts.end();)
    {
        if(*it==c)
            it=listedeContacts.erase(it);
    else
            it++;
    }

    std::cout << "Contact a été supprimé : " << c.getPrenom() << " " << c.getNom() << std::endl;
}
