#include "ajoutcontact.h"
#include "ui_ajoutcontact.h"
#include <QFileDialog>

/**
 * @brief Constructeur de la classe ajoutcontact.
 * @param parent Le widget parent.
 */
ajoutcontact::ajoutcontact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajoutcontact)
{
    ui->setupUi(this);
}

/**
 * @brief Destructeur de la classe ajoutcontact.
 */
ajoutcontact::~ajoutcontact()
{
    delete ui;
}

/**
 * @brief Slot appelé lors du clic sur le bouton "Annuler".
 */
void ajoutcontact::on_annulerB_clicked()
{
    this->close();
}

/**
 * @brief Slot appelé lors du clic sur le bouton "Enregistrer".
 */
void ajoutcontact::on_enregistrerB_clicked()
{
    // Crée un nouveau contact
    contact *c = new contact();
    c->setNom((ui->nomEdit->text()).toStdString());
    c->setPrenom((ui->prenomEdit->text()).toStdString());
    c->setEntreprise((ui->entrepriseEdit->text()).toStdString());
    c->setEmail((ui->emailEdit->text()).toStdString());
    c->setTelephone((ui->telephoneEdit->text()).toStdString());
    c->setPhoto(this->path.toStdString());
    c->setDateCreation();
    c->setDateModification();

    // Émet un signal pour indiquer qu'un contact a été enregistré
    emit contactEnregistre(c);

    // Émet un signal pour demander la mise à jour de la liste de contacts
    emit majListe();

    // Ferme la fenêtre d'ajout de contact
    this->close();
}

/**
 * @brief Slot appelé lors du clic sur le bouton "Photo".
 */
void ajoutcontact::on_photoB_clicked()
{
    // Ouvre une boîte de dialogue pour choisir une photo
    this->path = QFileDialog::getOpenFileName(this, "Choisir une photo", "", "Images (*.png *.jpg *.bmp *.jpeg)");
}
