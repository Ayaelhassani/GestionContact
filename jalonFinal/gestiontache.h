#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H
#include "tache.h"
#include "tache.h"
#include <string>
#include <iostream>
#include <list>

class gestiontache
{
private:
    list<Tache> taches;
public:
    gestiontache();
    ~gestiontache();
    void ajouterTache(const Tache& tache);
    void modifierTache(int i, const std::string& nvTexte, const string nvDateEcheance );
    void supprimerTache(Tache& t);
};

#endif // GESTIONTACHE_H
