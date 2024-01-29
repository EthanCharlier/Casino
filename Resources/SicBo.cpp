// Created by ethan on 10/01/2024.

#include "../headers/SicBo.h" // Include the header file for the SicBo class

#include <iostream>
#include <iomanip>
#include <utility>
#include <list>
#include <algorithm>
#include <map>

// Define ANSI escape codes for colored console output
const std::string RESET = "\033[0m";
const std::string WHITE = "\033[37m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string MAGENTA = "\033[35m";

// Constructor for the SicBo class, initializing the balance
SicBo::SicBo(int initialBalance) : balance(initialBalance){}

// Initialization function for the game
bool SicBo::init() {
    // Display welcome message and game rules
    // Prompt user if they are ready to play
    std::cout << "\t\t\t\t\t +---------------------------------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t |    " << CYAN << " W E L C O M E   T O   T H E   S I C   B O " << RESET << "    |" << std::endl;
    std::cout << "\t\t\t\t\t +---------------------------------------------------+" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Display game rules
    std::cout << "\n"
                 " +-------------------------------------------------------------------------------------------+\n"
                 " |        The objective of Sic Bo is to predict the outcome of the roll of three dice.       |\n"
                 " |            Players place bets on different combinations and try to predict the            |\n"
                 " |                    specific numbers or combinations that will appear.                     |\n"
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
int SicBo::getBalance() {
    return balance;
}

// Main game loop
void SicBo::play() {
    // Check if the balance is zero or negative, if so, return without playing
    if (balance <= 0) {
        return;
    }

    // Save the initial balance
    int initialBalance = balance;

    // Get the bet amount from the user
    std::pair<std::string, int> bet = getBet();

    // Subtract the bet amount from the balance
    balance -= bet.second;

    // Roll the dice, display it and calculate the result
    std::list<int> diceList = rollDices();
    std::map<int, int> diceListFormatted = displayRoll(diceList);
    int result = calcResult(bet, diceListFormatted);

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

// Function to get the bet amount from the user
std::pair<std::string, int> SicBo::getBet() {
    std::pair<std::string, int> bet;
    std::string betType;
    int betNumber;

    std::string betTypeChoice;
    std::string betChoice;

    // Display current balance
    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  | YOUR BALANCE : " << RED << std::setw(8) << std::right << balance << RESET << " |"
              << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+\n" << std::endl;

    // Display betting options
    std::cout << "\t\t\t\t\t\t\t +------ " << MAGENTA << "0" << RESET << " ------+   +------ " << MAGENTA << "1"
              << RESET << " ------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t |   " << CYAN << "S M A L L" << RESET << "   |   |     " << CYAN << "B I G" << RESET
              << "     |" << std::endl;
    std::cout << "\t\t\t\t\t\t\t +------ " << MAGENTA << "0" << RESET << " ------+   +------ " << MAGENTA << "1"
              << RESET << " ------+" << std::endl;

    std::cout << "\t\t\t\t\t\t\t   +-------------- " << MAGENTA << "2" << RESET << " --------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t   |   " << CYAN << "S I N G L E   N U M B E R" << RESET << "   |" << std::endl;
    std::cout << "\t\t\t\t\t\t\t   +-------------- " << MAGENTA << "2" << RESET << " --------------+" << std::endl;

    std::cout << "\t\t\t\t\t   +---------------------- " << MAGENTA << "3" << RESET << " ----------------------+"
              << std::endl;
    std::cout << "\t\t\t\t\t   |   " << CYAN << "T W O - D I C E   C O M B I N A T I O N S" << RESET << "   |"
              << std::endl;
    std::cout << "\t\t\t\t\t   +---------------------- " << MAGENTA << "3" << RESET << " ----------------------+"
              << std::endl;

    std::cout << "\t\t\t\t\t\t\t +---------------- " << MAGENTA << "4" << RESET << " ----------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t |   " << CYAN << "T H R E E - O F - A - K I N D" << RESET << "   |" << std::endl;
    std::cout << "\t\t\t\t\t\t\t +---------------- " << MAGENTA << "4" << RESET << " ----------------+" << std::endl;

    std::cout << "\t\t\t\t\t\t\t  +--------------- " << MAGENTA << "5" << RESET << " ---------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t  |   " << CYAN << "S P E C I F I C   T O T A L" << RESET << "   |" << std::endl;
    std::cout << "\t\t\t\t\t\t\t  +--------------- " << MAGENTA << "5" << RESET << " ---------------+" << std::endl;

    std::cout << "\nWhich options do you choose?" << std::endl;
    std::cin >> betTypeChoice;

    if (betTypeChoice == "2") {
        std::string singleNumberDice;
        std::string singleNumberNumber;

        std::cout << "\t\t\t\t\t\t\t\t    +--------- " << MAGENTA << "1" << RESET << " ---------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t    |   " << CYAN << "O N E   D I C E" << RESET << "   |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t    +--------- " << MAGENTA << "1" << RESET << " ---------+" << std::endl;

        std::cout << "\t\t\t\t\t\t\t\t   +---------- " << MAGENTA << "2" << RESET << " ----------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t   |    " << CYAN << "T W O   D I C E" << RESET << "    |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t   +---------- " << MAGENTA << "2" << RESET << " ----------+" << std::endl;

        std::cout << "\t\t\t\t\t\t\t\t  +----------- " << MAGENTA << "3" << RESET << " -----------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  |   " << CYAN << "T H R E E   D I C E" << RESET << "   |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  +----------- " << MAGENTA << "3" << RESET << " -----------+" << std::endl;

        std::cout << "\nWhich options do you choose?" << std::endl;
        std::cin >> singleNumberDice;

        std::cout << " +---- " << MAGENTA << "1" << RESET << " ----+  "
                                                             " +---- " << MAGENTA << "2" << RESET << " ----+  "
                                                                                                     " +---- " << MAGENTA << "3" << RESET << " ----+  "
                                                                                                                                             " +---- " << MAGENTA << "4" << RESET << " ----+  "
                                                                                                                                                                                     " +---- " << MAGENTA << "5" << RESET << " ----+  "
                                                                                                                                                                                                                             " +---- " << MAGENTA << "6" << RESET << " ----+" << std::endl;
        std::cout << " |           |   |  ▫        |   |  ▫        |   |  ▫     ▫  |   |  ▫     ▫  |   |  ▫     ▫  |" << std::endl;
        std::cout << " |     ▫     |   |           |   |     ▫     |   |           |   |     ▫     |   |  ▫     ▫  |" << std::endl;
        std::cout << " |           |   |        ▫  |   |        ▫  |   |  ▫     ▫  |   |  ▫     ▫  |   |  ▫     ▫  |" << std::endl;
        std::cout << " +---- " << MAGENTA << "1" << RESET << " ----+  "
                                                             " +---- " << MAGENTA << "2" << RESET << " ----+  "
                                                                                                     " +---- " << MAGENTA << "3" << RESET << " ----+  "
                                                                                                                                             " +---- " << MAGENTA << "4" << RESET << " ----+  "
                                                                                                                                                                                     " +---- " << MAGENTA << "5" << RESET << " ----+  "
                                                                                                                                                                                                                             " +---- " << MAGENTA << "6" << RESET << " ----+" << std::endl;

        std::cout << "\nWhich options do you choose?" << std::endl;
        std::cin >> singleNumberNumber;

        betType = betTypeChoice + singleNumberDice + singleNumberNumber;
    } else if (betTypeChoice == "3"){
        std::string firstDice;
        std::string secondDice;

        std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  |   " << CYAN << "F I R S T   D I C E" << RESET << "   |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;

        std::cout << " +---- " << MAGENTA << "1" << RESET << " ----+  "
                                                             " +---- " << MAGENTA << "2" << RESET << " ----+  "
                                                                                                     " +---- " << MAGENTA << "3" << RESET << " ----+  "
                                                                                                                                             " +---- " << MAGENTA << "4" << RESET << " ----+  "
                                                                                                                                                                                     " +---- " << MAGENTA << "5" << RESET << " ----+  "
                                                                                                                                                                                                                             " +---- " << MAGENTA << "6" << RESET << " ----+" << std::endl;
        std::cout << " |           |   |  ▫        |   |  ▫        |   |  ▫     ▫  |   |  ▫     ▫  |   |  ▫     ▫  |" << std::endl;
        std::cout << " |     ▫     |   |           |   |     ▫     |   |           |   |     ▫     |   |  ▫     ▫  |" << std::endl;
        std::cout << " |           |   |        ▫  |   |        ▫  |   |  ▫     ▫  |   |  ▫     ▫  |   |  ▫     ▫  |" << std::endl;
        std::cout << " +---- " << MAGENTA << "1" << RESET << " ----+  "
                                                             " +---- " << MAGENTA << "2" << RESET << " ----+  "
                                                                                                     " +---- " << MAGENTA << "3" << RESET << " ----+  "
                                                                                                                                             " +---- " << MAGENTA << "4" << RESET << " ----+  "
                                                                                                                                                                                     " +---- " << MAGENTA << "5" << RESET << " ----+  "
                                                                                                                                                                                                                             " +---- " << MAGENTA << "6" << RESET << " ----+" << std::endl;
        std::cout << "\nWhich options do you choose?" << std::endl;
        std::cin >> firstDice;

        std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  |  " << CYAN << "S E C O N D   D I C E" << RESET << "  |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;

        std::cout << " +---- " << MAGENTA << "1" << RESET << " ----+  "
                                                             " +---- " << MAGENTA << "2" << RESET << " ----+  "
                                                                                                     " +---- " << MAGENTA << "3" << RESET << " ----+  "
                                                                                                                                             " +---- " << MAGENTA << "4" << RESET << " ----+  "
                                                                                                                                                                                     " +---- " << MAGENTA << "5" << RESET << " ----+  "
                                                                                                                                                                                                                             " +---- " << MAGENTA << "6" << RESET << " ----+" << std::endl;
        std::cout << " |           |   |  ▫        |   |  ▫        |   |  ▫     ▫  |   |  ▫     ▫  |   |  ▫     ▫  |" << std::endl;
        std::cout << " |     ▫     |   |           |   |     ▫     |   |           |   |     ▫     |   |  ▫     ▫  |" << std::endl;
        std::cout << " |           |   |        ▫  |   |        ▫  |   |  ▫     ▫  |   |  ▫     ▫  |   |  ▫     ▫  |" << std::endl;
        std::cout << " +---- " << MAGENTA << "1" << RESET << " ----+  "
                                                             " +---- " << MAGENTA << "2" << RESET << " ----+  "
                                                                                                     " +---- " << MAGENTA << "3" << RESET << " ----+  "
                                                                                                                                             " +---- " << MAGENTA << "4" << RESET << " ----+  "
                                                                                                                                                                                     " +---- " << MAGENTA << "5" << RESET << " ----+  "
                                                                                                                                                                                                                             " +---- " << MAGENTA << "6" << RESET << " ----+" << std::endl;
        std::cout << "\nWhich options do you choose?" << std::endl;
        std::cin >> secondDice;

        betType = betTypeChoice + firstDice + secondDice;
    } else if (betTypeChoice == "4") {
        std::string diceNumber;

        std::cout << " +---- " << MAGENTA << "1" << RESET << " ----+  "
                                                             " +---- " << MAGENTA << "2" << RESET << " ----+  "
                                                                                                     " +---- "
                  << MAGENTA << "3" << RESET << " ----+  "
                                                " +---- " << MAGENTA << "4" << RESET << " ----+  "
                                                                                        " +---- " << MAGENTA << "5"
                  << RESET << " ----+  "
                              " +---- " << MAGENTA << "6" << RESET << " ----+" << std::endl;
        std::cout << " |           |   |  ▫        |   |  ▫        |   |  ▫     ▫  |   |  ▫     ▫  |   |  ▫     ▫  |"
                  << std::endl;
        std::cout << " |     ▫     |   |           |   |     ▫     |   |           |   |     ▫     |   |  ▫     ▫  |"
                  << std::endl;
        std::cout << " |           |   |        ▫  |   |        ▫  |   |  ▫     ▫  |   |  ▫     ▫  |   |  ▫     ▫  |"
                  << std::endl;
        std::cout << " +---- " << MAGENTA << "1" << RESET << " ----+  "
                                                             " +---- " << MAGENTA << "2" << RESET << " ----+  "
                                                                                                     " +---- "
                  << MAGENTA << "3" << RESET << " ----+  "
                                                " +---- " << MAGENTA << "4" << RESET << " ----+  "
                                                                                        " +---- " << MAGENTA << "5"
                  << RESET << " ----+  "
                              " +---- " << MAGENTA << "6" << RESET << " ----+" << std::endl;
        std::cout << "\nWhich options do you choose?" << std::endl;
        std::cin >> diceNumber;

        betType = betTypeChoice + diceNumber;
    } else if (betTypeChoice == "5") {
        std::string diceNumber;
        std::cout << "\nWhich number do you choose?" << std::endl;
        std::cin >> diceNumber;

        betType = betTypeChoice + diceNumber;
    } else {
        betType = betTypeChoice;
    }

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
        betNumber = balance;
    } else if (betChoice == "2") {
        betNumber = 1;
    } else if (betChoice == "3" && balance >= 5) {
        betNumber = 5;
    } else if (betChoice == "4" && balance >= 10) {
        betNumber = 10;
    } else if (betChoice == "5" && balance >= 25) {
        betNumber = 25;
    } else if (betChoice == "5" && balance >= 25) {
        betNumber = 25;
    } else if (betChoice == "7" && balance >= 100) {
        betNumber = 100;
    } else {
        do {
            std::cout << "How much is your bet? (" << balance << ")" << std::endl;
            std::cin >> betNumber;
        } while (betNumber < 1 || betNumber > balance);
    }

    return std::make_pair(betType, betNumber);
}

// Function to roll three six-sided dice and return the sum
std::list<int> SicBo::rollDices() {
    std::list<int> diceList;
    int first = rand() % 6 + 1;
    diceList.push_back(first);
    int second = rand() % 6 + 1;
    diceList.push_back(second);
    int third = rand() % 6 + 1;
    diceList.push_back(third);
    return diceList;
}

// Function to display the result of the roll
std::map<int, int> SicBo::displayRoll(std::list<int> diceList) {
    std::map<int, int> diceListFormatted;
    for (const int& dice : diceList) {
        switch (dice) {
            case 1:
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |           |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |     ▫     |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |           |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                break;
            case 2:
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫        |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |           |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |        ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                break;
            case 3:
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫        |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |     ▫     |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |        ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                break;
            case 4:
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫     ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |           |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫     ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                break;
            case 5:
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫     ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |     ▫     |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫     ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                break;
            default :
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫     ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫     ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t |  ▫     ▫  |  " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t\t +-----------+  " << std::endl;
                break;
        }
        auto it = std::find(diceList.begin(), diceList.end(), dice);
        if (it != diceList.end()) {
            diceListFormatted[*it] = diceListFormatted[*it] + 1;
        } else {
            diceListFormatted[dice] = 1;
        }
    }
    return diceListFormatted;
}

// Function to calculate the result based on the roll of the dice
int SicBo::calcResult(std::pair<std::string, int> bet, std::map<int, int> diceList) {
    if (bet.first[0] == '0') {
        int sum = makeSum(diceList);
        if ((4 <= sum) && (sum <= 10)) {
            return bet.second;
        } else {
            return 0;
        }
    } else if (bet.first[0] == '1') {
        int sum = makeSum(diceList);
        if ((11 <= sum) && (sum <= 17)) {
            return bet.second;
        } else {
            return 0;
        }
    } else if (bet.first[0] == '2') {
        if ((bet.first[1] == '3') && (diceList[std::stoi(std::string(1, bet.first[2]))] == 3)) {
            return bet.second * 3;
        } else if ((bet.first[1] == '2') && (diceList[std::stoi(std::string(1, bet.first[2]))] == 2)) {
            return bet.second * 2;
        } else if ((bet.first[1] == '1') && (diceList[std::stoi(std::string(1, bet.first[2]))] == 1)) {
            return bet.second;
        } else {
            return 0;
        }
    } else if (bet.first[0] == '3') {
        if ((diceList[std::stoi(std::string(1, bet.first[1]))]) && (diceList[std::stoi(std::string(1, bet.first[2]))])) {
            return bet.second * 2;
        } else {
            return 0;
        }
    } else if (bet.first[0] == '4') {
        if (diceList[std::stoi(std::string(1, bet.first[1]))] == 3) {
            return bet.second * 3;
        } else {
            return 0;
        }
    } else if (bet.first[0] == '5') {
        int sum = makeSum(diceList);
        if (bet.first.length() == 3) {
            if (std::stoi(std::string(1, bet.first[1]) + std::string(1, bet.first[2])) == sum) {
                return bet.second * 5;
            } else {
                return 0;
            }
        } else {
            if (std::stoi(std::string(1, bet.first[1])) == sum) {
                return bet.second * 5;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

// Function to make the sum of the rolled dices
int SicBo::makeSum(std::map<int, int> diceList) {
    int sum = 0;
    for (const auto& entry : diceList) {
        sum += entry.first * entry.second;
    }
    return sum;
}