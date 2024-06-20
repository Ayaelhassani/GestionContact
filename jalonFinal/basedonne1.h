#ifndef BASEDONNE1_H
#define BASEDONNE1_H
#include <QObject>
#include <map>


#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include "contact.h"
#include "gestiontache.h"
class basedonne1 : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;
    Interaction *I;
    Tache *T;
    gestiontache *gt;

    string idC;
    string idI;
    string idT;

    contact *c;
    contact *ct;
    Tache *tache;

public:
    basedonne1(QObject *parent = nullptr);
    ~basedonne1();
    void connexionBDD();
    string getIdC() const;
    QJsonArray exporterEnJSON();
    //void sauvegarderEnJSON(const QString &cheminFichier);


signals:
    void envoyerContact(contact *c);
    void NB(int);
    void envoyerE(QString);
    void envoyerEM(QString);
    void envoyerT(QString);
    void sendLIDA(map<Interaction *, list<Tache *>>, contact *);
    void sendLI(list<Interaction *>, contact *);
    void messageLIDA(QString, contact *);
    void messageLI(QString, contact *);
    void message(QString);
    void sendLC(list<contact *>);
    void messageLITI(string,contact*);
    void sendLCIT(list<Interaction *>, contact *);






public slots:
   void ajouterContact(contact *c);
   void recTache(Tache *t);
   void recN(QString nom);
   void recE(QString entreprise);
   void recD(QString date);

   void reception(string i);
   void recNbC();
   void modifierContact(contact *);
   void recID(string);
   void receiveE(QString e);
   void receiveEM(QString m);
   void receiveT(QString p);
   void recInteraction(Interaction *I);

   void r2supp();
   void recdda(QString du, QString au, string i);
   void recIDCI(string i);

   void recIDCIT(string i);






   void ajouterNouvelleAttribut();
   void mettreAJourNouvelAttribut();



};
#endif // FENETRE_H
