#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H
#include "interaction.h"
#include "contact.h"

class gestioninteraction
{
private:
    std::list<Interaction> interactions;
public:
    gestioninteraction();
    ~gestioninteraction();
    friend ostream & operator<<(ostream &, const contact&);

    void ajouterInteraction(const Interaction&);
    void modifierInteraction(int i, const std::string& nvContenu, string nvDateInteraction);
    void supprimerInteraction(const Interaction& i);


};

#endif // GESTIONINTERACTION_H
