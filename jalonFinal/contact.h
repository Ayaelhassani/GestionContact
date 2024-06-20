#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <list>
#include <iostream>
#include <list>
#include "interaction.h"

using namespace std;


#include "sdateAuto.h"
#include "date/date.h"
#include "date/chrono_io.h"
//#include "Interaction.h"


using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
using namespace std;

//struct Date {
//    unsigned int day;
//    unsigned int month;
//    unsigned int year;
//        };

class contact
{

private:
    std::string prenom;
    std::string nom;
    std::string entreprise;
    std::string email;
    std::string telephone;
    std::string photo;
    string dateC;
    string dateM;
    struct sdateAuto dateCreation;
    struct sdateAuto dateModification;
    std::list<Interaction> interactions;

public:
    contact(const std::string& prenom, const std::string& nom, const std::string& entreprise, const std::string& email, const std::string& telephone, const std::string& photo, const string dateC, const string dateM);
    ~contact();
    contact();
    contact(const string &, const string &);


    std::string getPrenom() const;
    std::string getNom() const;
    std::string getEntreprise() const;
    std::string getEmail() const;
    std::string getTelephone() const;
    std::string getPhoto() const;
    string getDateC() const;
    string getDateM()const;
    struct sdateAuto getDateCreation()const;
    struct sdateAuto getDateModification()const;


    void setPrenom(const std::string& prenom);
    void setNom(const std::string& nom);
    void setEntreprise(const std::string& entreprise);
    void setEmail(const std::string& email);
    void setTelephone(const std::string& telephone);
    void setPhoto(const std::string& photo);
    void setDateC(const string dc);
    void setDateM(const string dm);
    void setDateCreation();
    void setDateModification();
    string toStringDateC();
    string toStringDateM();




   friend ostream & operator<<(ostream &, const contact&);
    bool operator==( const contact &)const;
//    void ajouterInteraction(const Interaction&);
//    void modifierInteraction(int i, const std::string& nvContenu, string nvDateInteraction);
//    void supprimerInteraction(const Interaction& i);

};

#endif // CONTACT_H
