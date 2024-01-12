#include "headers/Player.h"
#include "headers/PokemonCard.h"
#include "headers/EnergyCard.h"
#include "headers/TrainerCard.h"

#include <iostream>
#include "headers/Player.h"

Player::Player(string playerName) {
    this->playerName = playerName;
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::displayBench() {
    cout << "Bench cards for Player " << playerName << " :" << endl;
    for (auto &benchCard : benchCards) {
        if (dynamic_cast<TrainerCard*>(benchCard)) {
            ((TrainerCard*)benchCard)->displayInfo();
        }
    }
}

void Player::displayAction() {
    cout << "Action cards for Player " << playerName << " :" << endl;
    for (auto &actionCard : actionCards) {
        actionCard->displayInfo();
    }
}


void Player::attachEnergyCard(int pokemonIndex, int energyCardIndex) {
    if (pokemonIndex < actionCards.size() && energyCardIndex < benchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(actionCards[pokemonIndex]);
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyCardIndex]);
        if (pokemonCard && energyCard) {
            std::get<1>(pokemonCard->attacks[0]) += 1;
            std::get<1>(pokemonCard->attacks[1]) += 1;
            cout << this->playerName << " is attaching an Energy Card of type " << energyCard->energyType << " to the Pokemon " << pokemonCard->getName() << endl;
            benchCards.erase(benchCards.begin() + energyCardIndex);
        }
    }
}



void Player::useTrainer(int indexBench) {
    string trainerEffect = ((TrainerCard*) benchCards[indexBench])->trainerEffect;
    cout << this->playerName << " is using the Trainer Card to \"" << trainerEffect << "\"" << endl;
    if (trainerEffect == "heal all your action pokemon") {
        for (auto &actionCard : actionCards) {
            actionCard->hp = actionCard->maxHP;
        }
    }
    else {
        cout << "Unknown effect" << endl;
    }
}

void Player::attack(int pokemonIndex, int attackIndex, Player& opponent, int opponentPokemonIndex) {
    if (pokemonIndex < actionCards.size() && opponentPokemonIndex < opponent.actionCards.size()) {
        PokemonCard* attackingPokemon = dynamic_cast<PokemonCard*>(actionCards[pokemonIndex]);
        PokemonCard* defendingPokemon = dynamic_cast<PokemonCard*>(opponent.actionCards[opponentPokemonIndex]);
        if (attackingPokemon && defendingPokemon) {
            int damage = std::get<3>(attackingPokemon->attacks[attackIndex]);
            string attackName = std::get<2>(attackingPokemon->attacks[attackIndex]);
            defendingPokemon->hp -= damage;
            cout << this->playerName << " attacking " << opponent.playerName << "’s Pokemon " << defendingPokemon->getName() << " with the Pokemon " << attackingPokemon->getName() << " with its attack : " << attackName << endl;
            cout << "Reducing " << damage << " from " << opponent.playerName << "’s Pokemon’s HP" << endl;
            if (defendingPokemon->hp > 0) {
                cout << "Pokemon " << defendingPokemon->getName() << " is still alive" << endl;
            } else {
                cout << "Pokemon " << defendingPokemon->getName() << " has fainted" << endl;
            }
        }
    }
}

void Player::activatePokemonCard(int index) {
    cout << this->playerName << " is activating a Pokemon Card : " << benchCards[index]->getName() << endl;
    actionCards.push_back((PokemonCard*)benchCards[index]);
    benchCards.erase(benchCards.begin() + index);
}