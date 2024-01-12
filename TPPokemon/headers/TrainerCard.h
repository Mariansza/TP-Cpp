#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include <string>
#include "Card.h"


using namespace std;

class TrainerCard : public Card {
public:

    
    TrainerCard(string cardName, string trainerEffect); // constructeur
    void displayInfo() const override; // affiche les informations de la carte dresseur

    string trainerEffect;
};
#endif