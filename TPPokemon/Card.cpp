#include "headers/Card.h"


//getters 
string Card::getName() const {
    return cardName;
}
Card :: Card(string name) {
    this->cardName = name;
}