// Created by ethan on 22/12/2023.

#include "../headers/Craps.h" // Include the header file for the Craps class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Define ANSI escape codes for colored console output
const std::string RESET = "\033[0m";
const std::string WHITE = "\033[37m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string MAGENTA = "\033[35m";

// Constructor for the Craps class, initializing the balance
Craps::Craps(int initialBalance) : balance(initialBalance) {}

// Initialization function for the game
bool Craps::init() {
    // Display welcome message and game rules
    // Prompt user if they are ready to play
    std::cout << "\t\t\t\t  +----------------------------+----------------------------+" << std::endl;
    std::cout << "\t\t\t\t  |   " << CYAN << " W E L C O M E   T O   T H E   C R A P S   G A M E " << RESET << "   |" << std::endl;
    std::cout << "\t\t\t\t  +----------------------------+----------------------------+" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Display game rules
    std::cout << "\n"
                 " +-------------------------------------------------------------------------------------------+\n"
                 " |                Craps is a dynamic dice game played with two six-sided dice.               |\n"
                 " |  Participants bet on the outcome of the roll. A roll of 7 or 11 is a win for \"Pass Line\"  |\n"
                 " |     while 2, 3, or 12 results in a loss. \"Don't Pass Line\" bets win on 2 or 3 and lose    |\n"
                 " |   on 7 or 11. The game offers various betting choices, creating a thrilling and diverse   |\n"
                 " |                                     casino experience.                                    |\n"
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
int Craps::getBalance() {
    return balance;
}

// Main game loop
void Craps::play() {
    // Check if the balance is zero or negative, if so, return without playing
    if (balance <= 0) {
        return;
    }

    // Save the initial balance
    int initialBalance = balance;

    // Get the bet amount from the user
    int bet = getBet();

    // Subtract the bet amount from the balance
    balance -= bet;

    // Roll the dice and calculate the result
    int dices = rollDices();
    int result = calcResult(dices, bet);

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
int Craps::getBet() {
    int bet;
    std::string betChoice;

    // Display current balance
    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  | YOUR BALANCE : " << RED << std::setw(8) << std::right << balance << RESET << " |" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+\n" << std::endl;

    // Display betting options
    std::cout << "\t\t\t\t\t\t +-------- " << MAGENTA << "0" << RESET << " --------+ " <<
              "  +-------- " << MAGENTA << "1" << RESET << " --------+" << std::endl;
    std::cout << "\t\t\t\t\t\t |   " << CYAN << " C U S T O M " << RESET << "   | " << "  |     " << YELLOW << " ALL  IN " << RESET << "     |" << std::endl;
    std::cout << "\t\t\t\t\t\t +-------- " << MAGENTA << "0" << RESET << " --------+ " <<
              "  +-------- " << MAGENTA << "1" << RESET << " --------+" << std::endl;

    // Determine the bet amount based on user's choice
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

// Function to roll two six-sided dice and return the sum
int Craps::rollDices() {
    int first = rand() % 6 + 1;
    int second = rand() % 6 + 1;
    int sum = first + second;
    return sum;
}

// Function to display the result of the roll
void Craps::displayRoll(int newResult, int point) {
    // Display the result in a stylized manner
    if (newResult == 7) {
        std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
        std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
        std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |     " << RED << newResult << WHITE << "     |" << RESET << std::endl;
        std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
        std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
    } else if (newResult == point) {
        if (newResult < 10) {
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |     " << GREEN << newResult << WHITE << "     |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
        } else {
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |    " << GREEN << std::to_string(newResult)[0] << " " << std::to_string(newResult)[1] << WHITE << "    |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
        }
    } else {
        if (newResult < 10) {
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |     " << CYAN << newResult << WHITE << "     |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
        } else {
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |    " << CYAN << std::to_string(newResult)[0] << " " << std::to_string(newResult)[1] << WHITE << "    |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t |           |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t +-----------+" << RESET << std::endl;
        }
    }
}

// Function to calculate the result of the roll and return the corresponding payout
int Craps::calcResult(int dices, int bet) {
    // Calculate the result based on the roll of the dice
    if (dices == 7 || dices == 11) {
        if (dices == 7) {
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|      " << GREEN << dices << YELLOW << "      |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
        } else {
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|     " << GREEN << std::to_string(dices)[0] << " " << std::to_string(dices)[1] << YELLOW << "     |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
        }
        return bet * 2;
    } else if (dices == 2 || dices == 3 || dices == 12) {
        if (dices == 2 || dices == 3) {
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|      " << RED << dices << YELLOW << "      |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
        } else {
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|     " << RED << std::to_string(dices)[0] << " " << std::to_string(dices)[1] << YELLOW << "     |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
        }
        return bet * 0;
    } else {
        if (dices < 10) {
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|      " << CYAN << dices << YELLOW << "      |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
        } else {
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|     " << CYAN << std::to_string(dices)[0] << " " << std::to_string(dices)[1] << YELLOW << "     |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << YELLOW << "\t\t\t\t\t\t\t\t\t\t+-------------+" << RESET << std::endl;
        }
        int point = dices;
        while (true) {
            int newResult = rollDices();
            displayRoll(newResult, point);
            if (newResult == point) {
                return bet * 2;
            } else if (newResult == 7) {
                return bet * 0;
            }
        }
    }
}