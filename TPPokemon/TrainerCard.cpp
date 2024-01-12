#include "headers/TrainerCard.h"
#include <iostream>

using namespace std;


TrainerCard::TrainerCard(string cardName, string trainerEffect) : Card(cardName){
    this->trainerEffect = trainerEffect;
}

void TrainerCard::displayInfo()  const{
    cout << "Trainer Card - Name : " << this->cardName << ", Effect : " << this->trainerEffect << endl;
}