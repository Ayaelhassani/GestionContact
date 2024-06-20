#ifndef AJOUINTERACTION_H
#define AJOUINTERACTION_H
#include "ajouttache.h"
#include "gestioninteraction.h"
#include "interaction.h"
#include <QWidget>

namespace Ui {
class ajouinteraction;
}

class ajouinteraction : public QWidget
{
    ajouttache *at;

       Q_OBJECT
   private:
       Interaction *I;
       gestioninteraction *GI;
       Tache *T;
   public:
       explicit ajouinteraction(QWidget *parent = nullptr);
       ~ajouinteraction();

   private slots:


       void on_BQuitter_clicked();



       void on_ajouterIB_clicked();


       void on_ajouttacheB_clicked();

private:
       Ui::ajouinteraction *ui;
   signals:
       void envoyerInteraction(Interaction *);
       void envoyerTache(Tache *);


   };


#endif // AJOUINTERACTION_H
