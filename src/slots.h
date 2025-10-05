#ifndef SLOTS_H
#define SLOTS_H

#include <iostream>
#include <vector>

//class Slots for our game
class Slots {
    //in private we are storing user balance, cash multiplier in game, filename to save user balance, vector for symbols and function to load random symbol from vector
    private:
        float balance;
        float nextMultiplier;

        const char* filename;
        std::vector<std::string> symbols;

        int loadSymbol();
    public:
    //in public we are storing our functions for game:

        Slots();
        ~Slots();

        void loadBalance();
        void saveBalance();

        void deposit();
        void withdraw();

        void checkBalance();
        void play();
};

#endif