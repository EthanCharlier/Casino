// Created by ethan on 10/01/2024.

// Include necessary library for input/output operations.
#include <iostream>
#include <utility>
#include <list>
#include <map>

// Header guard to prevent multiple inclusions of the same header file.
#ifndef CASINO_SICBO_H
#define CASINO_SICBO_H

// Declaration of the SicBo class.
class SicBo {
public:
    // Constructor that takes an initial balance as a parameter.
    SicBo(int initialBalance);

    // Initialization function.
    bool init();

    // Function to start the Craps game.
    void play();

    // Function to retrieve the current balance.
    int getBalance();

private:
    // Private data members for the Craps class.
    int balance;

    // Function to get user bets and amount to bet.
    std::pair<std::string, int> getBet();

    // Function to simulate the rolling of three six-sided dice.
    std::list<int> rollDices();

    // Function to display the result of the dice roll.
    std::map<int, int> displayRoll(std::list<int> diceList);

    // Function to calculate the result of the Sic Bo game based on user bets and the dice roll.
    int calcResult(std::pair<std::string, int> bet, std::map<int, int> diceList);

    // Function to calculate the sum of the three dice.
    int makeSum(std::map<int, int> diceList);
};

// End of the header guard.
#endif //CASINO_SICBO_H
