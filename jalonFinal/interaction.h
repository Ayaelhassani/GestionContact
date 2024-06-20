#ifndef INTERACTION_H
#define INTERACTION_H
#include "tache.h"
#include <string>
#include <iostream>
#include <list>
#include <chrono>
#include "sdateAuto.h"
#include "date/date.h"
#include "date/chrono_io.h"
using namespace std;
using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;

class Interaction
{


private:
    //int idC;
    string contenu;
    struct sdateAuto dateInteraction;
    list<Tache> taches;
    string di;
    string idI="";



public:
    Interaction(const string & contenu, const string dateInteraction);
    ~Interaction();
    Interaction();

    friend ostream & operator<<(ostream&, const Interaction&);
    bool operator==( const Interaction &)const;
    void setContenu(const string &c);
    void setDI(const string &dateInteraction);

    std::string getContenu()const;
    void setDateInteraction();
    struct sdateAuto getDateInteraction() const;
    string getDI()const;
    string getId();
    list<Tache>getLtache();
    void setId(string);

   // void listerTaches() const;
    void ajouterTache(const Tache& tache);
//    void modifierTache(int i, const std::string& nvTexte, const string nvDateEcheance );
//    void supprimerTache(Tache& t);

    string toStringDI();


};


#endif // INTERACTION_H
