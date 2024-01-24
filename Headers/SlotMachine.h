// Created by ethan on 22/12/2023.

// Include necessary library for input/output operations.
#include <string>
#include <map>

// Header guard to prevent multiple inclusions of the same header file.
#ifndef CASINO_SLOTMACHINE_H
#define CASINO_SLOTMACHINE_H

// Declaration of the SlotMachine class.
class SlotMachine {
public:
    // Constructor that takes an initial balance as a parameter.
    SlotMachine(int initialBalance);

    // Initialization function.
    bool init();

    // Function to start the Craps game.
    void play();

    // Function to retrieve the current balance.
    int getBalance();

private:
    // Private data members for the Craps class.
    int balance;

    // Arrays to store different types of symbols for the slot machine.
    const std::string symbolsTypeFruits[8] = {"🍇", "🍉", "🍊", "🍋", "🍌", "🍎", "🍒", "🥝"};
    const std::string symbolsTypeSweets[8] = {"🍦", "🍧", "🍨", "🍩", "🍪", "🍫", "🍬", "🍭"};
    const std::string symbolsTypeHearts[8] = {"🩷", "🧡", "💛", "💚", "💙", "🩵", "💜", "🤎"};
    const std::string symbolsTypeMoon[8] = {"🌑", "🌒", "🌓", "🌔", "🌕", "🌖", "🌗", "🌘"};
    const std::string symbolsTypeWeather[8] = {"☁️", "⛅", "☀️", "🌨️", "🌩️", "🌪️", "🌧️", "🌤️"};
    const std::string symbolsTypeAnimals[8] = {"🐻", "🐨", "🐼", "🐵", "🐷", "🦊", "🐮", "🐯"};

    // Function to prompt the user to choose a slot machine type.
    int slotMachineTypeChoice();

    // Function to get the user's bet.
    int getBet();

    // Function to simulate spinning the reels of the slot machine.
    void spinReels(std::string reels[5], int userChoice);

    // Function to display the result of the slot machine reels.
    std::map<std::string, int> displayReels(std::string reels[5]);

    // Function to calculate the result of the Slot Machine game based on the displayed symbols and user's bet.
    int calcResult(std::map<std::string, int> results, int bet);
};

// End of the header guard.
#endif //CASINO_SLOTMACHINE_H
