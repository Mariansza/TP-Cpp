#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <vector>
#include <tuple>
#include <string>


class PokemonCard : public Card {
public:

    // constructeur
    PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel, int maxHP, int energyCost1, string descriptionAttack1, int damageAttack1, int energyCost2, string descriptionAttack2, int damageAttack2);
    void displayInfo() const override; // affiche les informations de la carte pokemon



    string pokemonType; // type du pokemon
    string familyName; // nom de la famille du pokemon
    int evolutionLevel; // niveau d'évolution du pokemon
    int maxHP; // hp max
    int hp; // hp actuel
    vector<tuple<int, int, string, int>> attacks; // tuple représente une attaque
};

#endif