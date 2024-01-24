// Created by ethan on 23/12/2023.

// Include necessary library for input/output/map operations.
#include <string>
#include <map>

// Header guard to prevent multiple inclusions of the same header file.
#ifndef CASINO_ROULETTE_H
#define CASINO_ROULETTE_H

// Declaration of the Roulette class.
class Roulette {
public:
    // Constructor that takes an initial balance as a parameter.
    Roulette(int initialBalance);

    // Initialization function.
    bool init();

    // Function to start the Roulette game.
    void play();

    // Function to retrieve the current balance.
    int getBalance();

    // Function to build the game structure.
    std::map<std::string, std::pair<std::string, bool>> build();

    // Function to display the current state of the game based on bets.
    std::string showGame(std::map<std::string, int> bets);

private:
    // Private data members for the Roulette class.
    int balance;

    // Private game for the Roulette class.
    std::string game;

    // Function to get user bets based on the available choices.
    std::map<std::string, int> getBet(std::map<std::string, std::pair<std::string, bool>> betChoice);

    // Function to add additional bets to the existing ones.
    std::map<std::string, int> addBet(std::map<std::string, std::pair<std::string, bool>> betChoice, std::map<std::string, int> bet, int betAddValue);

    // Function to simulate the spinning of the roulette wheel.
    std::string spin();

    // Function to display the result of the spin based on user bets.
    void displaySpin(std::map<std::string, std::pair<std::string, bool>> betChoice, std::string result);

    // Function to calculate the result of the spin based on user bets and the actual result.
    std::map<std::string, std::pair<std::string, bool>> makeResult(std::map<std::string, std::pair<std::string, bool>> betChoice, std::string result);

    // Function to calculate the final outcome based on user bets and the actual result.
    int calcResult(std::map<std::string, std::pair<std::string, bool>> betResult, std::map<std::string, int> bet);
};

// End of the header guard.
#endif //CASINO_ROULETTE_H
