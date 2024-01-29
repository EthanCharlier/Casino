// Created by ethan on 22/12/2023.

#include "../headers/SlotMachine.h" // Include the header file for the SlotMachine class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <iomanip>

// Define ANSI escape codes for colored console output
const std::string RESET = "\033[0m";
const std::string WHITE = "\033[37m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string MAGENTA = "\033[35m";

// Constructor for the SlotMachine class, initializing the balance
SlotMachine::SlotMachine(int initialBalance) : balance(initialBalance) {}

// Initialization function for the game
bool SlotMachine::init() {
    // Display welcome message and game rules
    // Prompt user if they are ready to play
    std::cout << "\t\t\t\t +-----------------------------------------------------------+" << std::endl;
    std::cout << "\t\t\t\t |  " << CYAN << " W E L C O M E   T O   T H E   S L O T   M A C H I N E " << RESET << "  |" << std::endl;
    std::cout << "\t\t\t\t +-----------------------------------------------------------+" << std::endl;

    std::cout << "\n"
                 " +-------------------------------------------------------------------------------------------+\n"
                 " |  Slot machines, casino staples, involve spinning reels and aligning symbols for potential |\n"
                 " |    payouts. No intricate rules—just insert credits, spin, and hope for winning combos.    |\n"
                 " |   Themes, bonuses, and jackpots enhance the excitement, making slots a favorite for all   |\n"
                 " |                                     types of players..                                    |\n"
                 " +-------------------------------------------------------------------------------------------+\n"<< std::endl;

    std::string userChoice;
    std::cout << "Ready to play? (y/n)" << std::endl;
    std::cin >> userChoice;

    // Return true if the user wants to play, otherwise false
    if (userChoice == "y" || userChoice == "Y") {
        return true;
    } else {
        return false;
    }
}

// Function to get the current balance
int SlotMachine::getBalance() {
    return balance;
}

// Main game loop
void SlotMachine::play() {
    // Check if the balance is zero or negative, if so, return without playing
    if (balance <= 0) {
        return;
    }

    // Save the initial balance
    int initialBalance = balance;

    // Get the bet style of the slot machine
    int userChoice = slotMachineTypeChoice();

    // Get the bet amount from the user
    int bet = getBet();

    // Subtract the bet amount from the balance
    balance -= bet;

    // Roll and calculate the result
    std::string reels[5];
    spinReels(reels, userChoice);
    std::map<std::string, int> results = displayReels(reels);
    int result = calcResult(results, bet);

    // Add the result to the balance
    balance += result;

    // Display the result and updated balance
    if (balance - initialBalance < 0) {
        std::cout << "\n\t\t\t\t\t\t\t\t\t+---------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t| YOUR LOST : " << RED << std::setw(7) << std::right << balance - initialBalance << RESET << " |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t+---------------------+\n" << std::endl;
    } else if (balance - initialBalance > 0) {
        std::cout << "\n\t\t\t\t\t\t\t\t\t+---------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t| YOUR WON : " << RED << std::setw(8) << std::right << balance - initialBalance << RESET << " |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t+---------------------+\n" << std::endl;
    }

    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  | YOUR BALANCE : " << RED << std::setw(8) << std::right << balance << RESET << " |" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+\n" << std::endl;
}

// Function to get the style of the slot machine
int SlotMachine::slotMachineTypeChoice() {
    std::string userChoice;

    std::cout << "        +-----------+------------+-------------+-------------+-------------+-----------+" << std::endl;
    std::cout << "        |                                                                              |" << std::endl;
    std::cout << "        |\t\t +--------- " << CYAN << "Default" << RESET << " ---------+   +---------- " << CYAN << "Sweet" << RESET << " ----------+         |" << std::endl;
    std::cout << "        |\t\t | 🍇 🍉 🍊 🍋 🍌 🍎 🍒 🥝 |   | 🍦 🍧 🍨 🍩 🍪 🍫 🍬 🍭 |         |"<< std::endl;
    std::cout << "        |\t\t +------------ " << MAGENTA << "0" << RESET << " ------------+   +------------ " << MAGENTA << "1" << RESET << " ------------+         |" << std::endl;
    std::cout << "        |                                                                              |" << std::endl;
    std::cout << "        |\t\t +---------- " << CYAN << "Heart" << RESET << " ----------+   +---------- " << CYAN << "Moons" << RESET << " ----------+         |" << std::endl;
    std::cout << "        |\t\t | 🩷 🧡 💛 💚 💙 🩵 💜 🤎 |   | 🌑 🌒 🌓 🌔 🌕 🌖 🌗 🌘 |         |"<< std::endl;
    std::cout << "        |\t\t +------------ " << MAGENTA << "2" << RESET << " ------------+   +------------ " << MAGENTA << "3" << RESET << " ------------+         |" << std::endl;
    std::cout << "        |                                                                              |" << std::endl;
    std::cout << "        |\t\t +--------- " << CYAN << "Weather" << RESET << " ---------+   +--------- " << CYAN << "Animals" << RESET << " ---------+         |" << std::endl;
    std::cout << "        |\t\t | ☁️ ⛅ ☀️ 🌨️ 🌩️ 🌪️ 🌧️ 🌤️ |   | 🐻 🐨 🐼 🐵 🐷 🦊 🐮 🐯 |         |"<< std::endl;
    std::cout << "        |\t\t +------------ " << MAGENTA << "4" << RESET << " ------------+   +------------ " << MAGENTA << "5" << RESET << " ------------+         |" << std::endl;
    std::cout << "        |                                                                              |" << std::endl;
    std::cout << "        +-----------+------------+-------------+-------------+-------------+-----------+" << std::endl;

    std::cout << "\nWhich options do you choose?" << std::endl;
    std::cin >> userChoice;
    return std::stoi(userChoice);
}

// Function to get the bet amount from the user
int SlotMachine::getBet() {
    int bet;
    std::string betChoice;

    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  | YOUR BALANCE : " << RED << std::setw(8) << std::right << balance << RESET << " |" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+\n" << std::endl;

    std::cout << "\t\t\t\t\t\t +-------- " << MAGENTA << "0" << RESET << " --------+ " <<
              "  +-------- " << MAGENTA << "1" << RESET << " --------+" << std::endl;
    std::cout << "\t\t\t\t\t\t |   " << CYAN << " C U S T O M " << RESET << "   | " << "  |     " << YELLOW << " ALL  IN " << RESET << "     |" << std::endl;
    std::cout << "\t\t\t\t\t\t +-------- " << MAGENTA << "0" << RESET << " --------+ " <<
              "  +-------- " << MAGENTA << "1" << RESET << " --------+" << std::endl;

    if (balance >= 100) {
        std::cout << " +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "4" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "5" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "6" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "7" << RESET << " ----+ " << std::endl;
        std::cout << " |           |   |           |   |           |   |           |   |           |   |           |" << std::endl;
        std::cout << " |    " << RED << " 1 " << RESET << "    |   |    " << RED << " 5 " << RESET << "    |   |   " << RED << " 1 0 " << RESET << "   |   |   " << RED << " 2 5 " << RESET << "   |   |   " << RED << " 5 0 " << RESET << "   |   |  " << RED << " 1 0 0 " << RESET << "  |" << std::endl;
        std::cout << " |           |   |           |   |           |   |           |   |           |   |           |" << std::endl;
        std::cout << " +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "4" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "5" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "6" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "7" << RESET << " ----+ " << std::endl;
    } else if (balance >= 50) {
        std::cout << "\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "4" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "5" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "6" << RESET << " ----+ " << std::endl;
        std::cout << "\t\t |           |   |           |   |           |   |           |   |           |" << std::endl;
        std::cout << "\t\t |    " << RED << " 1 " << RESET << "    |   |    " << RED << " 5 " << RESET << "    |   |   " << RED << " 1 0 " << RESET << "   |   |   " << RED << " 2 5 " << RESET << "   |   |   " << RED << " 5 0 " << RESET << "   |"<< std::endl;
        std::cout << "\t\t |           |   |           |   |           |   |           |   |           |" << std::endl;
        std::cout << "\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "4" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "5" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "6" << RESET << " ----+ " << std::endl;
    } else if (balance >= 25) {
        std::cout << "\t\t\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "4" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "5" << RESET << " ----+ " << std::endl;
        std::cout << "\t\t\t\t |           |   |           |   |           |   |           |" << std::endl;
        std::cout << "\t\t\t\t |    " << RED << " 1 " << RESET << "    |   |    " << RED << " 5 " << RESET << "    |   |   " << RED << " 1 0 " << RESET << "   |   |   " << RED << " 2 5 " << RESET << "   |"<< std::endl;
        std::cout << "\t\t\t\t |           |   |           |   |           |   |           |" << std::endl;
        std::cout << "\t\t\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "4" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "5" << RESET << " ----+ " << std::endl;
    } else if (balance >= 10) {
        std::cout << "\t\t\t\t\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "4" << RESET << " ----+ " << std::endl;
        std::cout << "\t\t\t\t\t\t |           |   |           |   |           |" << std::endl;
        std::cout << "\t\t\t\t\t\t |    " << RED << " 1 " << RESET << "    |   |    " << RED << " 5 " << RESET << "    |   |   " << RED << " 1 0 " << RESET << "   |"<< std::endl;
        std::cout << "\t\t\t\t\t\t |           |   |           |   |           |" << std::endl;
        std::cout << "\t\t\t\t\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "4" << RESET << " ----+ " << std::endl;
    } else if (balance >= 5) {
        std::cout << "\t\t\t\t\t\t\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t |           |   |           |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t |    " << RED << " 1 " << RESET << "    |   |    " << RED << " 5 " << RESET << "    |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t |           |   |           |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " <<
                  "  +---- " << MAGENTA << "3" << RESET << " ----+ " << std::endl;
    } else {
        std::cout << "\t\t\t\t\t\t\t\t\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t\t |           |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t\t |    " << RED << " 1 " << RESET << "    |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t\t |           |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t\t +---- " << MAGENTA << "2" << RESET << " ----+ " << std::endl;
    }

    std::cout << "\nWhich options do you choose?" << std::endl;
    std::cin >> betChoice;
    if (betChoice == "1") {
        bet = balance;
    } else if (betChoice == "2") {
        bet = 1;
    } else if (betChoice == "3" && balance >= 5) {
        bet = 5;
    } else if (betChoice == "4" && balance >= 10) {
        bet = 10;
    } else if (betChoice == "5" && balance >= 25) {
        bet = 25;
    } else if (betChoice == "5" && balance >= 25) {
        bet = 25;
    } else if (betChoice == "7" && balance >= 100) {
        bet = 100;
    } else {
        do {
            std::cout << "How much is your bet? (" << balance << ")" << std::endl;
            std::cin >> bet;
        } while (bet < 1 || bet > balance);
    }
    return bet;
}

// Function to spin the reels
void SlotMachine::spinReels(std::string reels[5], int userChoice) {
    const std::string* symbols;
    switch (userChoice) {
        case 1:
            symbols = symbolsTypeSweets;
            break;
        case 2:
            symbols = symbolsTypeHearts;
            break;
        case 3:
            symbols = symbolsTypeMoon;
            break;
        case 4:
            symbols = symbolsTypeWeather;
            break;
        case 5:
            symbols = symbolsTypeAnimals;
            break;
        default:
            symbols = symbolsTypeFruits;
            break;
    }
    srand(time(0));
    for (int i = 0; i < 5; ++i) {
        int randomIndex = rand() % 8;
        reels[i] = symbols[randomIndex];
    }
}

// Function to display the result of the spin
std::map<std::string, int> SlotMachine::displayReels(std::string reels[5]) {
    // Display the result in a stylized manner
    std::map<std::string, int> results;
    std::cout << "\n\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  |   ";
    for (int i = 0; i < 5; ++i ) {
        std::cout << reels[i] << "  ";
        if (results.find(reels[i]) != results.end()) {
            results[reels[i]] = results[reels[i]] + 1;
        } else {
            results[reels[i]] = 1;
        }
    }
    std::cout << " |\n\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
    return results;
}

// Function to calculate the result based on the spin
int SlotMachine::calcResult(std::map<std::string, int> results, int bet) {
    switch (results.size()) {
        case 1: // {"A":?}
            return bet * 7;
        case 2: // {"A":?, "B":?}
            if (results.begin()->second == 4 || results.begin()->second == 1) { // {"A":4, "B":?} || {"A":1, "B":?}
                return bet * 5;
            } else { // {"A":3, "B":2} || {"A":2, "B":3}
                return bet * 4;
            }
        case 3: // {"A":?, "B":?, "C":?}
            if (results.begin()->second == 3 || (results.begin()->second == 1 && results.rbegin()->second != 2)) { // {"A":3, "B":?, "C":?} || {"A":1, "B":?, "C":?}
                return bet * 2;
            } else { // {"A":2, "B":?, "C":?}
                return bet * 3;
            }
        case 4: // {"A":?, "B":?, "C":?, "D": ?}
            return bet * 1;
        default:
            return 0;
    }
}
