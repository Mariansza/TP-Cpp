#include "headers/EnergyCard.h"
#include <iostream>
using namespace std;

EnergyCard::EnergyCard(string energyType) : Card("Energy"){
    this->energyType = energyType;
}

void EnergyCard::displayInfo() const {
    cout << "Card Name: " << cardName << endl;
    cout << "Energy Type: " << energyType << endl;
}

