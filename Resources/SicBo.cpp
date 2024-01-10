//
// Created by ethan on 10/01/2024.
//

#include "../headers/SicBo.h"

#include <iostream>
#include <iomanip>
#include <utility>

const std::string RESET = "\033[0m";
const std::string WHITE = "\033[37m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string MAGENTA = "\033[35m";

SicBo::SicBo(int initialBalance) : balance(initialBalance){}

bool SicBo::init() {
    std::cout << "\t\t\t\t\t +---------------------------------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t |    " << CYAN << " W E L C O M E   T O   T H E   S I C   B O " << RESET << "    |" << std::endl;
    std::cout << "\t\t\t\t\t +---------------------------------------------------+" << std::endl;

    std::cout << "\n"
                 " +-------------------------------------------------------------------------------------------+\n"
                 " |        The objective of Sic Bo is to predict the outcome of the roll of three dice.       |\n"
                 " |            Players place bets on different combinations and try to predict the            |\n"
                 " |                    specific numbers or combinations that will appear.                     |\n"
                 " +-------------------------------------------------------------------------------------------+\n"<< std::endl;

    std::string userChoice;
    std::cout << "Ready to play? (y/n)" << std::endl;
    std::cin >> userChoice;

    if (userChoice == "y" || userChoice == "Y") {
        return true;
    } else {
        return false;
    }
}

int SicBo::getBalance() {
    return balance;
}

void SicBo::play() {
    if (balance <= 0) {
        return;
    }
    int initialBalance = balance;
    std::pair<std::string, int> bet = getBet();

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

std::pair<std::string, int> SicBo::getBet() {
    std::pair<std::string, int> bet;
    std::string betType;

    std::string betTypeChoice;
    std::string betChoice;

    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  | YOUR BALANCE : " << RED << std::setw(8) << std::right << balance << RESET << " |"
              << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+\n" << std::endl;

    std::cout << "\t\t\t\t\t\t\t +------ " << MAGENTA << "0" << RESET << " ------+   +------ " << MAGENTA << "1"
              << RESET << " ------+" << std::endl;
    std::cout << "\t\t\t\t\t\t\t |     " << CYAN << "B I G" << RESET << "     |   |   " << CYAN << "S M A L L" << RESET
              << "   |" << std::endl;
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

        std::cout << "\t\t\t\t\t\t\t\t    +--------- " << MAGENTA << "0" << RESET << " ---------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t    |   " << CYAN << "O N E   D I C E" << RESET << "   |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t    +--------- " << MAGENTA << "0" << RESET << " ---------+" << std::endl;

        std::cout << "\t\t\t\t\t\t\t\t   +---------- " << MAGENTA << "1" << RESET << " ----------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t   |    " << CYAN << "T W O   D I C E" << RESET << "    |"<< std::endl;
        std::cout << "\t\t\t\t\t\t\t\t   +---------- " << MAGENTA << "1" << RESET << " ----------+" << std::endl;

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

    return bet;
}