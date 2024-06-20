#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include "ajouttache.h"
#include "formulaire.h"
#include "rechercher.h"
#include "ui_mainwindow.h"
#include "ajoutcontact.h"
#include "ajouinteraction.h"
//#include "basededonne.h"
#include "aff.h"
#include "basedonne1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    //basededonne * bd;
    ajoutcontact * ac;
    ajouinteraction * ai;
    //ajouttache * at;
    aff *a;
    rechercher * r;
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMenuBar * barreMenu;
    void afficherListe();//pour remplir la qlistWidget
    //json
    void sauvegarderEnJSON();

private slots:
    //void recupMessageLITI(QString m, contact* c);
    void recLI(list<Interaction *> li, contact *c);
    void recMessageLI(QString m, contact *c);
    void on_InterB_3_clicked();



    //void on_tacheB2_clicked();

    void on_listeContact_itemDoubleClicked( );

    void on_actionAjouter_un_contact_triggered();

    void on_actionRechercher_triggered();

    void on_InterB1_clicked();

    void on_tacheB_clicked();

    void on_pushButton_clicked();

signals:



    //void onBoutonCreationContactClicked();


    //void on_formB_clicked();
    //void on_actionRechercher_triggered();
    //void on_actionAjouter_un_contact_triggered();



    //void on_InterB_clicked();

    //void on_tacheB_clicked();


    //void on_listeContact_itemDoubleClicked();

    void on_listeContact_itemClicked(QListWidgetItem *item);





public slots:
    void majListeContact();
    void NbCRec(int);

    void recupMessageLITI(string, contact*);
    void affichIt(list<Interaction *>, contact *);
    void recupListeIDA(map<Interaction *, list<Tache *>> it, contact *c);
    void recupMessageListeIDA(QString m, contact *c);


signals:
  void select(string);
  void selectC(string);//pour envoyer l'id du contact qui a été selectionné dans qlistWidget à la classe basedonnee
  void envoyerIdContact(QString idContact);
  void sendLIDA(map<Interaction *, list<Tache *>>);
  void envoyer(QString, QString, string);//envoyer la premiere date et la deuxieme date et l'id du contact selectionné à la classe basedonne
  void messageLIDA(QString, contact*);

  void envNB();


private:
Ui::MainWindow *ui;
formulaire * f;
basedonne1 *bd;
};


#endif // MAINWINDOW_H
