#include "headers/PokemonCard.h"
#include <iostream>


using namespace std;


PokemonCard::PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel, int maxHP, int energyCost1, string descriptionAttack1, int damageAttack1,
                         int energyCost2, string descriptionAttack2,
                         int damageAttack2) : Card(cardName) {
    this->pokemonType = pokemonType;
    this->familyName = familyName;
    this->evolutionLevel = evolutionLevel;
    this->maxHP = maxHP;
    this->hp = maxHP;
    this->attacks = vector<tuple<int, int, string, int>>();
    this->attacks.emplace_back(energyCost1, 0, descriptionAttack1, damageAttack1);
    this->attacks.emplace_back(energyCost2, 0, descriptionAttack2, damageAttack2);
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name : " << this->cardName
         << ", Type : " << this->pokemonType
         << ", Evolution Level : " << this->evolutionLevel
         << " of the family \"" << this->familyName
         << ", HP : " << this->hp << "\"" << endl;
    cout << "Attacks: " << endl;
    for (int i = 0; i < attacks.size(); i++) {
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attacks[i]) << endl;
        cout << "Attack current energy storage: " << get<1>(attacks[i]) << endl;
        cout << "Attack description: " << get<2>(attacks[i]) << endl;
        cout << "Attack damage: " << get<3>(attacks[i]) << endl;
    }
}