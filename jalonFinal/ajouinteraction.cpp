#include "ajouinteraction.h"
#include "ui_ajouinteraction.h"
#include "gestioninteraction.h"
#include "interaction.h"
/**
 * @brief Constructeur de la classe ajouinteraction.
 * @param parent Le widget parent.
 */
ajouinteraction::ajouinteraction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajouinteraction)
{
    ui->setupUi(this);
}


/**
 * @brief ajouinteraction::~ajouinteraction
 */
ajouinteraction::~ajouinteraction()
{
    delete ui;
}


/**
 * @brief ajouinteraction::on_BQuitter_clicked
 */

void ajouinteraction::on_BQuitter_clicked()
{
    this->close();
}


/**
 * @brief ajouinteraction::on_ajouterIB_clicked
 */
void ajouinteraction::on_ajouterIB_clicked()
{
    I= new Interaction();
    I->setContenu(ui->titreEdit->toPlainText().toStdString());
    emit envoyerInteraction(I);
    //ui->ajouterIB->setEnabled(false);
}

/**
 * @brief Slot appelé lors du clic sur le bouton "Ajouter Tâche".
 */
void ajouinteraction::on_ajouttacheB_clicked()
{
    QString tache=ui->tache->toPlainText();
    string sx=tache.toStdString();
    string todo;
    string date;
    bool verifd=false;
    __SIZE_TYPE__ i=0; int nb=0;
    while(nb<3 && i<sx.size())
    {
        if(sx[i]=='@')
        {
            nb++;
            i=i+5;
        }
        else
        {
            if(nb==1)
            {
                todo+=sx[i];
            }
            if(nb==2)
            {
                date+=sx[i];
                verifd=true;
            }
        }
        i++;
    }
    if(verifd)
    {
        T=new Tache(todo,date);
    }
    else
    {
        T=new Tache(todo,I->getDI());
    }
    //std::cout<<"tache :"<<todo;
    emit envoyerTache(T);
   ui->tache->clear();
   ui->titreEdit->clear();

   // ui->m2Label->setText("Tache ajouter avec succes");
}


