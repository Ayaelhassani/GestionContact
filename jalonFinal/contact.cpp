#include "contact.h"
#include "interaction.h"
/**
 * @brief contact::contact Constructeur de la classe contact
 * @param prenom Le prenom du contact.
 * @param nom Le nom du contact.
 * @param entreprise Le nom de l'entreprise du contact.
 * @param email L'adresse email du contact.
 * @param telephone Le numéro de téléphone du contact.
 * @param photo Le chemin de la photo du contact.
 */
contact::contact(const std::string& prenom, const std::string& nom, const std::string& entreprise, const std::string& email, const std::string& telephone, const std::string& photo, const string dateC, const string dateM)
{   this->prenom = prenom;
    this->nom = nom;
    this->entreprise = entreprise;
    this->email = email;
    this->telephone = telephone;
    this->photo = photo;
    //this->supprime = false;
    //this->dateCreation = dateCreation;
    //this->dateModification = dateModification;
    this -> setDateC(dateC);
    this->setDateM(dateM);
    //this->dateCreation = floor<days>(system_clock::now());

    // Utilisez le type day_point pour stocker la date de modification
    //this->dateModification = floor<days>(system_clock::now());


}


/**
 * @brief Constructeur de la classe contact avec nom et prénom.
 *
 * Ce constructeur initialise un objet contact avec les valeurs spécifiées pour le nom et le prénom.
 * Les autres attributs sont initialisés avec des valeurs par défaut.
 *
 * @param n Nom du contact.
 * @param p Prénom du contact.
 */
contact::contact(const string &n, const string &p)
{
    this -> setNom(n);
    this -> setPrenom(p);
}



/**
 * @brief Constructeur par défaut de la classe contact.
 *
 * Ce constructeur initialise un objet contact avec des valeurs par défaut.
 * Le nom et le prénom sont initialisés à "null", les autres attributs sont également initialisés avec des valeurs par défaut.
 * Les dates de création et de modification sont définies automatiquement.
 */
contact::contact()
{
    this -> setNom("null");
    this -> setPrenom("null");
    this -> setEntreprise("null");
    this -> setEmail("null");
    this -> setTelephone("null");
    this -> setPhoto("null");
    this -> setDateCreation();
    this -> setDateModification();
    this -> setDateC(toStringDateC());
    this->setDateM(toStringDateM());
}
/**
 * @brief contact::~contact Destructeur de la classe contact.
 */
contact::~contact(){

}
/**
 * @brief Obtient le prénom du contact.
 *
 * @return Le nom du contact.
*/
std::string contact::getPrenom() const {
    return prenom;
}
/**
 * @brief Obtient le nom du contact.
 *
 * @return Le nom du contact.
*/
std::string contact::getNom() const {
    return nom;
}
/**
 * @brief Obtient le nom de l'entreprise du contact.
 * @return Le nom de l'entreprise du contact.
*/
std::string contact::getEntreprise() const {
    return entreprise;
}
/**
 * @brief Obtient l'adresse email du contact.
 * @return L'adresse email du contact.
*/
std::string contact::getEmail() const {
    return email;
}
/**
 * @brief Obtient le numéro du téléphone du contact.
 * @return Le numéro de téléphone du contact.
*/

std::string contact::getTelephone() const {
    return telephone;
}
/**
 * @brief Obtient le chemin de la photo du contact.
 * @return Le chemin de la photo du contact.
*/
std::string contact::getPhoto() const {
    return photo;
}
/**
 * @brief Modifie le prénom du contact.
 * @return prenom Le nouveau prénom du contact.
*/

void contact::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}
/**
 * @brief Modifie le nom du contact.
 * @param nom Le nouveau nom du contact.
*/
void contact::setNom(const std::string& nom) {
    this->nom = nom;
}
/**
 * @brief Modifie le nom de l'entreprise du contact.
 * @param entreprise Le nouveau nom de l'entreprise du contact.
*/
void contact::setEntreprise(const std::string& entreprise) {
    this->entreprise = entreprise;
}
/**
 * @brief Modifie l'adresse email du contact.
 * @param email La nouvelle adresse
*/
void contact::setEmail(const std::string& email) {
    this->email = email;
}
/**
 * @brief Modifie le numéro de téléphone du contact.
 * @param telephone Le nouveau numéro du contact.
*/
void contact::setTelephone(const std::string& telephone) {
    this->telephone = telephone;
}
/**
 * @brief Modifie le chemin de la photo du contact.
 * @param photo Le nouveau chemin de la photo du contact.
*/
void contact::setPhoto(const std::string& photo) {
    this->photo = photo;
}
/**
 * @brief Obtient la date de création du contact.
 * @return La date de création du contact.
*/
struct sdateAuto contact::getDateCreation() const {
    return dateCreation;
}
void contact::setDateCreation(){
//    auto tp = floor<days>(system_clock::now());
//    auto ymd = year_month_day{tp};
//    this -> dateCreation.jour = day{ymd.day()};
//    this -> dateCreation.mois = ymd.month();
//    this -> dateCreation.annee = ymd.year();
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateCreation.jour = ymd.day();
    this -> dateCreation.mois = ymd.month();
    this -> dateCreation.annee = ymd.year();
}
string contact::getDateC()const{
    return dateC;
}
void contact ::setDateC(const string dc){
    this->dateC=dc;
}
struct sdateAuto contact::getDateModification() const {
    return dateModification;
}
void contact::setDateModification(){
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateModification.jour = ymd.day();
    this -> dateModification.mois = ymd.month();
    this -> dateModification.annee = ymd.year();
}
string contact::getDateM()const{
    return dateM;
}
void contact ::setDateM(const string dm){
    this->dateM=dm;
}

/**
 * @brief Surcharge de l'opérateur de sortie pour afficher les informations du contact.
 * @param os Le flux de sortie.
 * @param c Le contact à afficher.
 * @return Le flux de sortie mis à jour.
*/

std::ostream& operator<<(std::ostream& os, const contact& c) {


    os << "Prénom: " << c.prenom << "\n";
    os << "Nom: " << c.nom << "\n";
    os << "Société: " << c.entreprise << "\n";
    os << "Email: " << c.email << "\n";
    os << "Téléphone: " << c.telephone << "\n";
    os << "Image: " << c.photo << "\n";
    os<<"Date de création: "<<c.getDateC()<<"\n";
    for(auto it=c.interactions.begin();it!=c.interactions.end();)
    {
        os<<*it;
        ++it;
    }

    return os;
}
/**
 * @brief Surcharge de l'opérateur de comparaison pour vérifier l'égalité de deux contacts.
 *
 * @param c Le contact à comparer.
 * @return Vrai si les contacts sont égaux, sinon faux.
*/
bool contact::operator==(const contact& c)const{
    if(getNom() ==c.getNom())
        if(getPrenom()==c.getPrenom())
            if(getEmail()==c.getEmail())
                if(getEntreprise()==c.getEntreprise())
                    if(getTelephone()==c.getTelephone())
                        if(getPhoto()==c.getPhoto())
                            return true;
    return false;

}

/**
 * @brief Convertit la date de modification en format de chaîne de caractères.
 * @return Une chaîne représentant la date de modification au format "jour/mois/année".
 */
string contact::toStringDateM()
{
    return to_string(this->dateModification.jour.operator unsigned int())+"/"+to_string(this->dateModification.mois.operator unsigned int())+"/"+to_string(this->dateModification.annee.operator int());
}
/**
 * @brief Convertit la date de création en format de chaîne de caractères.
 * @return Une chaîne représentant la date de création au format "jour/mois/année".
 */
string contact::toStringDateC()
{
    return to_string(this->dateCreation.jour.operator unsigned int())+"/"+to_string(this->dateCreation.mois.operator unsigned int())+"/"+to_string(this->dateCreation.annee.operator int());

}
/**
 * @brief Ajoute une interaction au contatc.
 *
 * @param i L'interaction à ajouter.
*/



//void contact::ajouterInteraction(const Interaction& i)
//{
//    this->interactions.push_back(i);
//}
///**
// * @brief Modifie une interaction à modifier.
// * @param i L'indice de l'interaction à modifier.
// * @param nvContenu Le nouveau contenu de l'interaction.
// * @param nvDateInteraction La nouvelle date de l'interaction.
//*/
//void contact::modifierInteraction(int i, const std::string& nvContenu,  string nvDateInteraction) {
//    auto it = interactions.begin();
//    int count = 0;

//    while (it != interactions.end() && count < i) {
//        ++it;
//        ++count;
//    }

//    if (it != interactions.end()) {
//        it->setContenu(nvContenu);
//        it->setDI(nvDateInteraction);
//    }
//}
///**
// * @brief Supprime une interaction du contact.
// * @param i L'interaction à supprimer.
// *
//*/
//void contact :: supprimerInteraction(const Interaction& i){

//        // Marquer le contact comme supprimé
//        for(auto it=interactions.begin();it!=interactions.end();)
//        {
//            if(*it==i)
//                it=interactions.erase(it);
//        else
//                it++;
//        }

//       // std::cout << "Interaction a été supprimée : " << i.getContenu() << " " << i.getDateInteraction() << std::endl;
//    }



