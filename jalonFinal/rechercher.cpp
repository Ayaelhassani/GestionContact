#include "rechercher.h"
#include "ui_rechercher.h"
/**
     * @brief Constructeur de la classe rechercher.
     * @param parent Le widget parent (le cas échéant).
     */
rechercher::rechercher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rechercher)
{
    ui->setupUi(this);
}
/**
     * @brief Destructeur de la classe rechercher.
     */
rechercher::~rechercher()
{
    delete ui;
}


/**
    * @brief Slot appelé lorsqu'on clique sur la case à cocher "Nom exact" (checkBoxNE).
*/

void rechercher::on_checkBoxNE_clicked()
{
    ui->RB1->setEnabled(false);
    ui->checkBoxD->setChecked(false);
    ui->RB->setEnabled(true);
    ui->checkBoxNE->setChecked(true);
}

/**
 * @brief Slot pour recevoir une liste de contacts après une recherche.
 * @param lc Liste de contacts résultante de la recherche.
 */
void rechercher::recLC(list<contact *> lc)
{
    for(auto &c : lc)
    {
        ui->resultatEdit->append(QString::fromStdString("Nom: "+c->getNom()));
        ui->resultatEdit->append(QString::fromStdString("Prenom: "+c->getPrenom()));
        ui->resultatEdit->append(QString::fromStdString("Entreprise: "+c->getEntreprise()));
        ui->resultatEdit->append(QString::fromStdString("Mail: "+c->getEmail()));
        ui->resultatEdit->append(QString::fromStdString("Telephone: "+c->getTelephone()));
        ui->resultatEdit->append(QString::fromStdString("Date de creation: "+c->getDateC()));
        ui->resultatEdit->append(" ");
    }
}
/**
 * @brief Slot pour afficher les informations d'un contact après une recherche spécifique.
 * @param c Le contact trouvé.
 */
void rechercher::receptionC(contact *c)
{
    ui->resultatEdit->setText(QString::fromStdString("Nom: "+c->getNom()));
    ui->resultatEdit->append(QString::fromStdString("Prenom: "+c->getPrenom()));
    ui->resultatEdit->append(QString::fromStdString("Entreprise: "+c->getEntreprise()));
    ui->resultatEdit->append(QString::fromStdString("Mail: "+c->getEmail()));
    ui->resultatEdit->append(QString::fromStdString("Telephone: "+c->getTelephone()));
    ui->resultatEdit->append(QString::fromStdString("Date de creation: "+c->getDateC()));
}

/**
 * @brief Slot pour afficher un message résultant de la recherche.
 * @param m Le message à afficher.
 */
void rechercher::recMessage(QString m)
{
    ui->resultatEdit->setText(m);
}

/**
    * @brief Slot appelé lorsqu'on clique sur le bouton "Recherche par Nom ou Entreprise" (RB).
    */
void rechercher::on_RB_clicked()
{
    QString info=ui->rechercheLine->text();
    std::string crit=ui->TypeR->currentText().toStdString();
    ui->resultatEdit->setText(" ");
    //qDebug() << info;
    //qDebug() << crit;
    if(crit=="Nom")
    {
        emit envN(info);
    }
    if(crit=="Entreprise")
    {
        emit envE(info);
    }
}

/**
     * @brief Slot appelé lorsqu'on clique sur la case à cocher "Date" (checkBoxD).
     */
void rechercher::on_checkBoxD_clicked()
{
    ui->RB1->setEnabled(true);
    ui->checkBoxNE->setChecked(false);
    ui->RB->setEnabled(false);
    ui->checkBoxD->setChecked(true);
}

/**
     * @brief Slot appelé lorsqu'on clique sur le bouton "Recherche par Date" (RB1).
     */
void rechercher::on_RB1_clicked()
{
    ui->resultatEdit->setText(" ");
    QString date=ui->dateCEdit->text();
    string l=date.toStdString();
    string nl="";
    if(l[0]=='0')
    {
        for(__SIZE_TYPE__ i=1;i<l.size();i++)
        {
            nl+=l[i];
        }
        date=QString::fromStdString(nl);
    }
    emit envD(date);
}

