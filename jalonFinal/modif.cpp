#include "modif.h"
#include "ui_modif.h"
/**
     * @brief Constructeur de la classe modif.
     * @param parent Le widget parent (le cas échéant).
     */
modif::modif(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modif)
{
    ui->setupUi(this);
}
/**
     * @brief Destructeur de la classe modif.
     */
modif::~modif()
{
    delete ui;
}

/**
   * @brief Remplit les champs de l'interface utilisateur avec les informations d'un objet contact.
   * @param c L'objet contact.
   */
void modif::getContact(contact *c){
    ui->lineNom->setText(QString::fromStdString(c->getNom()));
    ui->linePrenom->setText(QString::fromStdString(c->getPrenom()));
    ui->lineEntreprise->setText(QString::fromStdString(c->getEntreprise()));
    ui->lineEmail->setText(QString::fromStdString(c->getEmail()));
    ui->lineTelephone->setText(QString::fromStdString(c->getTelephone()));
    ui->lineDC->setText(QString::fromStdString(c->getDateC()));
    ui->lineDM->setText(QString::fromStdString(c->getDateM()));



}
/**
     * @brief Slot appelé lorsqu'on clique sur le bouton Enregistrer.
     */
void modif::on_EnregistrerButton_2_clicked()
{
    bool entreprise = ui->lineEntreprise->text().isEmpty();
    bool email = ui->lineEmail->text().isEmpty();
    bool telephone = ui->lineTelephone->text().isEmpty();

    if(!entreprise)
    {
        emit sendEntreprise(ui->lineEntreprise->text());
    }
    if(!email)
    {
        emit sendEmail(ui->lineEmail->text());
    }
    if(!telephone)
    {
        emit sendTelephone(ui->lineTelephone->text());
    }
    this->close();
}

/**
    * @brief Slot appelé lorsqu'on clique sur le bouton Supprimer.
    */
void modif::on_SupprimerButton_clicked()
{
    emit supp();
    this->close();
}

/**
     * @brief Slot appelé lorsqu'on clique sur le bouton Annuler.
     */
void modif::on_AnnulerButton_2_clicked()
{
    this->close();
}




