#include "interaction.h"
//#include "gestiontache.h"
#include "tache.h"
/**
 * @brief Interaction::Interaction c'est un constructeur de la classe interaction.
 * @param contenu Le contenu de l'interaction.
 * @param dateInteraction La date de l'interaction.
 */
Interaction::Interaction(const string & contenu, const string dateInteraction)
{
    this -> setDateInteraction();
    this -> setContenu(contenu);
    this -> setDI(dateInteraction);

}
/**
 * @brief Interaction::~Interaction Destructeur de la classe Interaction
 */
Interaction::~Interaction(){

}

/**
 * @brief Constructeur par défaut de la classe Interaction.
 * Initialise la date d'interaction, le contenu et l'ID d'interaction.
 */
Interaction::Interaction()
{
    setDateInteraction();
    setContenu("null");
    setDI(toStringDI());
}
string Interaction::getId()
{
    return idI;
}
void Interaction::setId(string h)
{
    idI=h;
}
list<Tache> Interaction::getLtache()
{
return this->taches;
}
/**
 * @brief Getter pour la date d'interaction.
 * @return La date d'interaction sous forme de structure sdateAuto.
 */

struct sdateAuto Interaction::getDateInteraction() const
{
    return this -> dateInteraction;
}


/**
 * @brief Getter pour le contenu de l'interaction.
 * @return Le contenu de l'interaction sous forme de chaîne de caractères.
 */
string Interaction::getContenu()const
{
    return this->contenu;
}

/**
 * @brief Getter pour l'ID d'interaction.
 * @return L'ID d'interaction sous forme de chaîne de caractères.
 */
string Interaction::getDI() const
{
    return this ->di;
}


/**
 * @brief Setter pour la date d'interaction.
 * Utilise la date actuelle pour initialiser la date d'interaction.
 */
void Interaction::setDateInteraction()
{
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateInteraction.jour = ymd.day();
    this -> dateInteraction.mois = ymd.month();
    this -> dateInteraction.annee = ymd.year();
}


/**
 * @brief Setter pour l'ID d'interaction.
 * @param dateI La nouvelle valeur pour l'ID d'interaction.
 */
void Interaction::setDI(const string &dateI)
{
    this ->di=dateI;
}


/**
 * @brief Setter pour le contenu de l'interaction.
 * @param c Le nouveau contenu de l'interaction.
 */
void Interaction::setContenu(const string &c)
{
    this -> contenu = c;
}


/**
 * @brief Convertit la date d'interaction en format de chaîne de caractères.
 * @return Une chaîne représentant la date d'interaction au format "jour/mois/année".
 */
string Interaction::toStringDI()
{
    return to_string(this->dateInteraction.jour.operator unsigned int())+"/"+to_string(this->dateInteraction.mois.operator unsigned int())+"/"+to_string(this->dateInteraction.annee.operator int());
}



/**
 * @brief Surcharge de l'opérateur d'égalité pour les objets Interaction.
 * @param other L'autre objet Interaction à comparer.
 * @return true si les objets sont égaux, sinon false.
 */
bool Interaction::operator==(const Interaction& other) const {
    return (
        contenu == other.contenu &&

        di == other.di
    );
}


/**
 * @brief Surcharge de l'opérateur de sortie pour les objets Interaction.
 * @param o Le flux de sortie.
 * @param i L'objet Interaction à afficher.
 * @return Le flux de sortie après l'affichage.
 */
ostream& operator<<(ostream &o, const Interaction &i)
{
    o << i.getContenu() << " " && o<<i.getDI() << " "; // << i.getDateInteraction().jour << "/" << i.getDateInteraction().mois << "/" << i.getDateInteraction().annee;
    return o;
}
/**
 * @brief Interaction::ajouterTache Ajoute une tache à l'interaction.
 * @param tache La tache à ajouter.
 */
void Interaction::ajouterTache(const Tache& tache) {
    this->taches.push_back(tache);
}
///**
// * @brief Interaction::modifierTache Modifie une tache existante dans l'interaction.
// * @param i L'indice de la tache à modifier.
// * @param nvTexte Le nouveau texte de la tache.
// * @param nvDateEcheance La nouvelle date d'écheance de la tache.
// */
//void Interaction::modifierTache(int i, const std::string& nvTexte, const string nvDateEcheance) {
//    /*if (i >= 0 && i<taches.size()) {
//        auto it = taches.begin();
//        //std::advance(it, i);


//        it->setTexte(nvTexte);
//        it->setDateEcheance(nvDateEcheance);
//    }*/
//    auto it = taches.begin();
//    int count = 0;

//    while (it != taches.end() && count < i) {
//        ++it;
//        ++count;
//    }

//    if (it != taches.end()) {
//        it->setTexte(nvTexte);
//        it->setDE(nvDateEcheance);
//    }
//}
///**
// * @brief Interaction::supprimerTache Supprime une tache de l'interaction
// * @param t La tache à supprimer
// */
///*void Interaction::supprimerTache(Tache& t){
//    for(auto it=taches.begin();it!=taches.end();)
//    {
//        if(*it==t)
//    }
//}*/



