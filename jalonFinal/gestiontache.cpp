#include "gestiontache.h"
#include "tache.h"
gestiontache::gestiontache()
{

}
gestiontache::~gestiontache(){

}
void gestiontache::ajouterTache(const Tache& tache) {
    this->taches.push_back(tache);
}
/**
 * @brief Interaction::modifierTache Modifie une tache existante dans l'interaction.
 * @param i L'indice de la tache à modifier.
 * @param nvTexte Le nouveau texte de la tache.
 * @param nvDateEcheance La nouvelle date d'écheance de la tache.
 */
void gestiontache::modifierTache(int i, const std::string& nvTexte, const string nvDateEcheance) {
    /*if (i >= 0 && i<taches.size()) {
        auto it = taches.begin();
        //std::advance(it, i);


        it->setTexte(nvTexte);
        it->setDateEcheance(nvDateEcheance);
    }*/
    auto it = taches.begin();
    int count = 0;

    while (it != taches.end() && count < i) {
        ++it;
        ++count;
    }

    if (it != taches.end()) {
        it->setTexte(nvTexte);
        it->setDE(nvDateEcheance);
    }
}
/**
 * @brief Interaction::supprimerTache Supprime une tache de l'interaction
 * @param t La tache à supprimer
 */
void gestiontache::supprimerTache(Tache& t){
    for(auto it=taches.begin();it!=taches.end();)
    {
        if(*it==t)
            it=taches.erase(it);
        else
            it++;
    }

}
