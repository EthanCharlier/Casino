//
// Created by ethan on 22/12/2023.
//

#include <iostream>

#ifndef CASINO_CRAPS_H
#define CASINO_CRAPS_H

class Craps {
public:
    Craps(int initialBalance);
    void init();
    void play();
    int getBalance();

private:
    int balance;
    int getBet();
    int rollDices();
    void displayRoll(int newResult, int point);
    int calcResult(int result, int bet);
};

#endif //CASINO_CRAPS_H
