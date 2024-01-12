#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include <string>
#include "Card.h"

class EnergyCard : public Card {
public:
    EnergyCard(string energyType);
    void displayInfo() const override; // affiche les informations de la carte énergie

    string energyType;
};

#endif