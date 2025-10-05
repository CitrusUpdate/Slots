#include "slots.h"
#include <cstdio>
#include <iomanip>

//class contructor
Slots::Slots() {
    //when object is created, we set the balance, multiplier, file name and fill vector in with symbols, we are loading balance from file
    balance = 100.00;
    nextMultiplier = 1.0;
    
    filename = "account.txt";
    symbols = {"🍒", "🍋", "🍉", "⭐", "💎", "🔥"};

    loadBalance();
}

//class destructor
Slots::~Slots() {
    //at the end of a program we are saving balance to file
    saveBalance();
}

int Slots::loadSymbol() {
    return rand() % symbols.size();
}

void Slots::loadBalance() {
    //open file and check if file is opened
    FILE * fp = fopen(filename, "r");

    if(!fp) {
        std::cerr << "Failed to open file\n";
    } else {
        //scanning file for a float number and set the value we find to balance variable
        fscanf(fp, "%f", &balance);
        fclose(fp);
    }
}

void Slots::saveBalance() {
    FILE * fp = fopen(filename, "w");

    if(!fp) {
        std::cerr << "Failed to open file\n";
    } else {
        //write to file balance at the end of the program with two decimal places
        fprintf(fp, "%.2f", balance);
        fclose(fp);
    }
}

void Slots::deposit() {
    //deposit cash into the account when amount is greater than 0
    float amount;
    
    std::cout << "How much you want to deposit? ";
    std::cin >> amount;

    if(amount > 0) {
        balance += amount;
        std::cout << std::fixed << std::setprecision(2) << amount << " PLN deposited\n";
    } else {
        std::cout << "Amount must be greater than 0!\n";
    }
}

void Slots::withdraw() {
    //withdraw cash from account when amount is greater than 0 or lower/equal than actual balance
    float amount;

    std::cout << "How much you want to wihdraw? ";
    std::cin >> amount;

    if(amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << std::fixed << std::setprecision(2) << amount << " has been withdrawn from your account\n";
    } else {
        std::cout << "Amount must bre greater than 0 and lower than your balance";
    }
}

void Slots::checkBalance() {
    //show user balance with 2 decimal places
    std::cout << "Balance: " << std::fixed << std::setprecision(2) << balance << " PLN\n";
}

void Slots::play() {
    //main game logic
    char ch;
    float stake;

    //ask user for stake he want to play check if stake is greater than 0 or lower/equal user balance

    std::cout << "Enter stake: ";
    std::cin >> stake;

    if(stake < 0 && stake >= balance) {
        std::cout << "Stake must be greater than 0 and lower/equal your balance\n";
        return;
    } 

    //play game while user will not choose to end
    do {
        //check if user still have balance to play with this stake
        if(stake > balance) {
            std::cout << "Not enough money to play with this stake!\n";
            return;
        }

        //take money from user balance
        balance -= stake;

        //load 3 symbols
        int s1 = loadSymbol();
        int s2 = loadSymbol();
        int s3 = loadSymbol();

        //show result
        std::cout << "Result: [" << symbols[s1] << "] [" << symbols[s2] << "] [" << symbols[s3] << "]\n";

        //multiplier logic
        int flames = (symbols[s1] == "🔥") + (symbols[s2] == "🔥") + (symbols[s3] == "🔥");

        if(flames == 1) nextMultiplier = 1.5;
        if(flames == 2) nextMultiplier = 2.0;
        if(flames == 3) nextMultiplier = 3.0;

        //win logic
        float win = 0;

        //when 3 symbols are the same
        if((s1 == s2 && s2 == s3) && flames == 0) {
            if(symbols[s1] == "💎") {
                win = stake * 20;
            } else if(symbols[s1] == "⭐") {
                win = stake * 10;
            } else {
                win = stake * 5;
            }

            std::cout << "THREE ARE THE SAME! You win: " << std::fixed << std::setprecision(2) << win << " PLN\n";
        } else if((s1 == s2 || s2 == s3 || s1 == s3) && flames == 0) {
            //when 2 symbols are the same
            //identify which symbols are pair
            std::string pairSymbol;
            bool isWin = false;

            if(s1 == s2) pairSymbol = symbols[s1];
            else if(s2 == s3) pairSymbol = symbols[s2];
            else pairSymbol = symbols[s1];

            //we check win only for these 3 symbols so when the other ones will be in pair there will be no win
            if(pairSymbol == "🍒") {
                win = stake * 1.2;
                isWin = true;
            } else if(pairSymbol == "🍋") {
                win = stake * 1.5;
                isWin = true;
            } else if(pairSymbol == "🍉") {
                win = stake * 2;
                isWin = true;
            } else {
                isWin = false;
            }

            if(isWin) {
                std::cout << "TWO ARE THE SAME! You win: " << std::fixed << std::setprecision(2) << win << " PLN\n";
            }
        } else {
            std::cout << "You win nothing!\n";
        }

        //check if there were active multiplier before win
        if(win > 0 && nextMultiplier > 1.0) {
            //store win value with multiplier
            float boosted = win * nextMultiplier;
            std::cout << "MULTIPLIER X" << nextMultiplier << "! Win increased from " << " PLN to: " << boosted << " PLN\n";

            win = boosted;
            nextMultiplier = 1.0;
        }

        //add cash to balance
        balance += win;

        //display user balance and ask to play again with the same stake
        checkBalance();
        std::cout << "Play again with the same stake? Stake: " << stake << " PLN (y/n)";
        std::cin >> ch;

    } while(ch == 'y' && stake <= balance);
}