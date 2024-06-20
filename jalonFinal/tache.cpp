#include "tache.h"
/**
 * @brief Constructeur de la classe Tache.
 *
 * @param texte Le texte de la tâche.
 * @param dateEcheance La date d'échéance de la tâche.
 */
Tache::Tache(const string &a, const string &dateT)
{
    this->setDateEcheance();
    this -> setTexte(a);
    this -> setDE(dateT);
}
Tache::~Tache(){

}
Tache::Tache()
{
    setDateEcheance();
    setTexte("NULL");
    setDE(toStringDE());
}

/**
 * @brief Récupère le texte de la tâche.
 *
 * @return Le texte de la tâche.
 */
std::string Tache::getTexte() const {
    return texte;
}

/**
 * @brief Récupère la date d'échéance de la tâche.
 *
 * @return La date d'échéance de la tâche.
 */
struct sdateAuto Tache::getDateEcheance() const {
    return dateEcheance;
}
string Tache::getDE() const
{
    return this->de;
}

/**
 * @brief Modifie le texte de la tâche.
 *
 * @param texte Le nouveau texte de la tâche.
 */
void Tache:: setTexte(const std::string& texte) {
        this->texte=texte;
    }


/**
 * @brief Modifie la date d'échéance de la tâche.
 *
 * @param dateEcheance La nouvelle date d'échéance de la tâche.
 */
void Tache::setDE(const string& dateEcheance) {
        this->de = dateEcheance;
    }
void Tache::setDateEcheance(){
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateEcheance.jour = ymd.day();
    this -> dateEcheance.mois = ymd.month();
    this -> dateEcheance.annee = ymd.year();
}

/**
 * @brief Surcharge de l'opérateur de sortie pour afficher la tâche au format @TODO.
 *
 * @param os Le flux de sortie.
 * @param c La tâche à afficher.
 * @return Le flux de sortie modifié.
 */
std::ostream& operator<<(std::ostream& os, const Tache& t)
{
    //petit check pour varier l'affichage, avec ou sans format de date, suivant la nature de la tache, si elle contient une date ou non
    //if(t.getCheck() == false)
    {
        struct sdateAuto d = t.getDateEcheance();
        os << "@todo" << " " << t.getTexte() << " " << "@date" << " " << d.jour << "/" << d.mois << "/" << d.annee;
    }
    /*else
    {
        o << "@todo" << " " << t.getAction();
    }*/
    return os;
}
bool Tache::operator==(const Tache& t)const{
    if(getTexte() ==t.getTexte())
        if(getDE()==t.getDE())

                           return true;
    return false;

}

string Tache::toStringDE()
{
    return to_string(this->dateEcheance.jour.operator unsigned int())+"/"+to_string(this->dateEcheance.mois.operator unsigned int())+"/"+to_string(this->dateEcheance.annee.operator int());
}

