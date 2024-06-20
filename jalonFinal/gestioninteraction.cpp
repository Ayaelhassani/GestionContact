#include "gestioninteraction.h"

gestioninteraction::gestioninteraction()
{

}
void gestioninteraction::ajouterInteraction(const Interaction& i)
{
    this->interactions.push_back(i);
}
/**
 * @brief Modifie une interaction à modifier.
 * @param i L'indice de l'interaction à modifier.
 * @param nvContenu Le nouveau contenu de l'interaction.
 * @param nvDateInteraction La nouvelle date de l'interaction.
*/
void gestioninteraction::modifierInteraction(int i, const std::string& nvContenu,  string nvDateInteraction) {
    auto it = interactions.begin();
    int count = 0;

    while (it != interactions.end() && count < i) {
        ++it;
        ++count;
    }

    if (it != interactions.end()) {
        it->setContenu(nvContenu);
        it->setDI(nvDateInteraction);
    }
}
/**
 * @brief Supprime une interaction du contact.
 * @param i L'interaction à supprimer.
 *
*/
void gestioninteraction :: supprimerInteraction(const Interaction& i){

        // Marquer le contact comme supprimé
        for(auto it=interactions.begin();it!=interactions.end();)
        {
            if(*it==i)
                it=interactions.erase(it);
        else
                it++;
        }

       // std::cout << "Interaction a été supprimée : " << i.getContenu() << " " << i.getDateInteraction() << std::endl;
    }


