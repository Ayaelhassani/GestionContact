#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H
#include "contact.h"

class gestionContact
{
private:
    std::list<contact>listedeContacts;
public:
    gestionContact();
    ~gestionContact();
    void ajoutContact(const contact &c);
    void modifierContact(contact& c, const std::string& nouveauNom, const std::string& nouveauPrenom, const std::string& nouvelleEntreprise, const std::string& nouvelEmail, const std::string& nouveauTelephone, const std::string& nouvellePhoto, const string nouvelleDateCreation,const string& nouvelleDateModification);
    void supprimerContact(contact& c);




};

#endif // GESTIONCONTACT_H
