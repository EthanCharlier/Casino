// Created by ethan on 22/12/2023.

// Include necessary library for input/output operations.
#include <iostream>

// Header guard to prevent multiple inclusions of the same header file.
#ifndef CASINO_CRAPS_H
#define CASINO_CRAPS_H

// Declaration of the Craps class.
class Craps {
public:
    // Constructor that takes an initial balance as a parameter.
    Craps(int initialBalance);

    // Initialization function.
    bool init();

    // Function to start the Craps game.
    void play();

    // Function to retrieve the current balance.
    int getBalance();

private:
    // Private data members for the Craps class.
    int balance;

    // Private function to get the user's bet.
    int getBet();

    // Private function to simulate rolling dice and calculate the sum.
    int rollDices();

    // Private function to display the result of the dice roll.
    void displayRoll(int newResult, int point);

    // Private function to calculate the result of the game based on the dice roll and the bet.
    int calcResult(int result, int bet);
};

// End of the header guard.
#endif //CASINO_CRAPS_H
