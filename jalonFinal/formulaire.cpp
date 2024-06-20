#include "formulaire.h"
#include "ui_formulaire.h"
#include "contact.h"


/**
 * @brief Constructeur de la classe formulaire.
 * @param parent Pointeur vers le widget parent.
 */
formulaire::formulaire(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formulaire)
{
    ui->setupUi(this);
}


/**
 * @brief Destructeur de la classe formulaire.
 */
formulaire::~formulaire()
{
    delete ui;
}

/**
 * @brief Réception d'un contact et affichage des informations dans le formulaire.
 * @param c Pointeur vers l'objet contact à afficher.
 */
void formulaire::receiveContact(contact *c){
    ui->lineNom->setText(QString::fromStdString(c->getNom()));
    ui->linePrenom->setText(QString::fromStdString(c->getPrenom()));
    ui->lineEntreprise->setText(QString::fromStdString(c->getEntreprise()));
    ui->lineEmail->setText(QString::fromStdString(c->getEmail()));
    ui->lineTelephone->setText(QString::fromStdString(c->getTelephone()));
    ui->lineDC->setText(QString::fromStdString(c->getDateC()));
    ui->lineDM->setText(QString::fromStdString(c->getDateM()));
    //pour afficher l'image d'un contact
//    string img=c->getPhoto();
//    QPixmap pixmap(img.c_str());
//    QIcon ButtonIcon(pixmap);
//    ui->photoB->setIcon(ButtonIcon);
//    ui->photoB->setIconSize(pixmap.rect().size());
    string img = c->getPhoto();

    // Charger l'image dans QPixmap
    QPixmap originalPixmap(img.c_str());

    // Définir la taille souhaitée
    QSize desiredSize(100, 100);  // Remplacez 100 par la largeur et la hauteur souhaitées

    // Redimensionner l'image
    QPixmap scaledPixmap = originalPixmap.scaled(desiredSize, Qt::KeepAspectRatio);

    // Créer une icône à partir de l'image redimensionnée
    QIcon ButtonIcon(scaledPixmap);

    // Affecter l'icône au bouton
    ui->photoB->setIcon(ButtonIcon);

    // Ajuster la taille de l'icône
    ui->photoB->setIconSize(desiredSize);

    nc=c;
}


/**
 * @brief Slot pour la suppression d'un contact.
 * Émet un signal pour informer la suppression et ferme la fenêtre formulaire.
 */
void formulaire::rsup(){
    emit envoyerS();
    this->close();
}


/**
 * @brief Slot pour le clic sur le bouton de modification.
 * Affiche la fenêtre de modification et connecte les signaux et les slots nécessaires.
 */
void formulaire::on_modifierB_clicked()
{
    m=new modif();
    m->show();
    connect(this, SIGNAL(envoyerModifC(contact *)), m, SLOT(getContact(contact *)));
    connect(m, SIGNAL(sendEntreprise(QString)), this, SLOT(receiveE(QString)));
    connect(m, SIGNAL(sendEmail(QString)), this, SLOT(receiveEM(QString)));
    connect(m, SIGNAL(sendTelephone(QString)), this, SLOT(receiveT(QString)));
    connect(m, SIGNAL(supp()), this, SLOT(rsup()));
    emit envoyerModifC(nc);

}



/**
 * @brief Slot pour le clic sur le bouton de quitter.
 * Ferme la fenêtre formulaire.
 */
void formulaire::on_quitterB_clicked()
{
    this->close();
}


/**
 * @brief Slot pour la réception d'une nouvelle entreprise depuis la fenêtre de modification.
 * Émet un signal pour informer la fenêtre principale du changement.
 * @param ct Nouvelle entreprise.
 */
void formulaire::receiveE(QString ct)
{
    emit envoyerE(ct);
}


/**
 * @brief Slot pour la réception d'un nouvel email depuis la fenêtre de modification.
 * Émet un signal pour informer la fenêtre principale du changement.
 * @param ct Nouvel email.
 */
void formulaire::receiveEM(QString ct)
{
    emit envoyerEM(ct);
}

/**
 * @brief Slot pour la réception d'un nouveau numéro de téléphone depuis la fenêtre de modification.
 * Émet un signal pour informer la fenêtre principale du changement.
 * @param ct Nouveau numéro de téléphone.
 */
void formulaire::receiveT(QString ct)
{
    emit envoyerT(ct);
}

