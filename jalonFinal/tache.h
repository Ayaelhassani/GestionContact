#ifndef TACHE_H
#define TACHE_H
#include <string>
#include <iostream>
//#include "interaction.h"

#include <chrono>
#include "sdateAuto.h"
#include "date/date.h"
#include "date/chrono_io.h"

using namespace std;
using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
class Tache
{


private:
    int idI;
    string texte;
    string de;
    struct sdateAuto dateEcheance;

public:
    Tache(const std::string& texte, const string& dateEcheance);
    ~Tache();
    Tache();
    std::string getTexte() const;
    struct sdateAuto getDateEcheance() const;
    string getDE() const;

    friend ostream & operator<<(ostream &, const Tache&);
    bool operator==( const Tache &)const;
    void setTexte(const std::string& nouveauTexte);
    void setDateEcheance();
    void setDE(const string& nouvelleDateEcheance);
    string toStringDE();



    //Interaction* getInteractionAssociee() const;
    //void associerAInteraction(Interaction* interaction);

    //Interaction* interactionAssociee;
};

#endif // TACHE_H
