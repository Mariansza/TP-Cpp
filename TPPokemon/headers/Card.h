#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
public:
    Card(string name);
    virtual void displayInfo() const = 0; // affiche les informations de la carte
    
    // getters
    string getName() const;

protected:
    string cardName;
};

#endif 