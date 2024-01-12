#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"

class Player {
public:

    Player(string playerName);
    
    void displayBench(); // affiche les cartes de la main
    void displayAction(); // affiche les cartes en jeu

    void activatePokemonCard(int index); // active une carte pokemon
    
    void addCardToBench(Card* card); // ajoute une carte à la main
    void attachEnergyCard(int benchIndex, int energyIndex); // attache une carte énergie à une carte pokemon

    void attack(int benchIndex, int attackIndex, Player& enemy, int enemyBenchIndex); // attaque une carte pokemon adverse
    void useTrainer(int benchIndex); // utilise une carte dresseur

    string playerName; // nom du joueur
    vector<Card*> benchCards; // cartes dans la main
    vector<PokemonCard*> actionCards; // cartes en jeu
};

#endif