//
// Created by ethan on 23/12/2023.
//

#include "../headers/Roulette.h"

#include <iostream>
#include <map>
#include <string>
#include <random>
#include <iomanip>

const std::string RESET = "\033[0m";
const std::string WHITE = "\033[37m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string MAGENTA = "\033[35m";

Roulette::Roulette(int initialBalance) : balance(initialBalance){}

bool Roulette::init() {
    std::cout << "\t\t\t\t\t +---------------------------------------------------+" << std::endl;
    std::cout << "\t\t\t\t\t |  " << CYAN << " W E L C O M E   T O   T H E   R O U L E T T E " << RESET << "  |" << std::endl;
    std::cout << "\t\t\t\t\t +---------------------------------------------------+" << std::endl;

    std::cout << "\n"
                 "Roulette, a casino classic, involves betting on where a spinning ball will land on a numbered wheel. \n"
                 "Players can choose specific numbers or broader options like red or black. It's a game of anticipation, \n"
                 "with straightforward rules and diverse betting choices, making roulette a timeless and thrilling casino experience.\n" << std::endl;

    std::string userChoice;
    std::cout << "Ready to play? (y/n)" << std::endl;
    std::cin >> userChoice;

    if (userChoice == "y" || userChoice == "Y") {
        return true;
    } else {
        return false;
    }
}

std::string Roulette::showGame(std::map<std::string, int> bets) {

    game = "\n" + WHITE + "+-------+-----+-----+-----+------+------+------+------+------+------+------+------+------+--------+" + RESET + "\n"
            + WHITE + "|       |     |     |     |      |      |      |      |      |      |      |      |      |        |" + RESET + "\n"

            + WHITE + "|       | " + RED + " 3 " + WHITE + " | " + RESET + " 6 " + WHITE + " | " + RED + " 9 " + WHITE + " | " + RED
            + " 12 " + WHITE + " | " + RESET + " 15 " + WHITE + " | " + RED + " 18 " + WHITE + " | " + RED + " 21 " + WHITE + " | " + RESET
            + " 24 " + WHITE + " | " + RED + " 27 " + WHITE + " | " + RED + " 30 " + WHITE + " | " + RESET + " 33 " + WHITE + " | " + RED
            + " 36 " + WHITE + " | " + YELLOW + " 2to1 " + WHITE + " |" + RESET + "\n"

            + WHITE + "|       |     |     |     |      |      |      |      |      |      |      |      |      |        |" + RESET + "\n"
            + WHITE + "|       +-----+-----+-----+-----+-------+------+------+------+------+------+------+------+--------+" + RESET + "\n"
            + WHITE + "|       |     |     |     |      |      |      |      |      |      |      |      |      |        |" + RESET + "\n"

            + WHITE + "|  " + GREEN + " 0 " + WHITE + "  | " + RESET + " 2 " + WHITE + " | " + RED + " 5 " + WHITE + " | " + RESET
            + " 8 " + WHITE + " | " + RESET + " 11 " + WHITE + " | " + RED + " 14 " + WHITE + " | " + RESET + " 17 " + WHITE + " | " + RESET
            + " 20 " + WHITE + " | " + RED + " 23 " + WHITE + " | " + RESET + " 26 " + WHITE + " | " + RESET + " 29 " + WHITE + " | " + RED
            + " 32 " + WHITE + " | " + RESET + " 35 " + WHITE + " | " + YELLOW + " 2to1 " + WHITE + " |" + RESET + "\n"

            + WHITE + "|       |     |     |     |      |      |      |      |      |      |      |      |      |        |" + RESET + "\n"
            + WHITE + "|       +-----+-----+-----+-----+-------+------+------+------+------+------+------+------+--------+" + RESET + "\n"
            + WHITE + "|       |     |     |     |      |      |      |      |      |      |      |      |      |        |" + RESET + "\n"

            + WHITE + "|       | " + RED + " 1 " + WHITE + " | " + RESET + " 4 " + WHITE + " | " + RED + " 7 " + WHITE + " | " + RESET
            + " 10 " + WHITE + " | " + RESET + " 13 " + WHITE + " | " + RED + " 16 " + WHITE + " | " + RED + " 19 " + WHITE + " | " + RESET
            + " 22 " + WHITE + " | " + RED + " 25 " + WHITE + " | " + RESET + " 28 " + WHITE + " | " + RESET + " 31 " + WHITE + " | " + RED
            + " 34 " + WHITE + " | " + YELLOW + " 2to1 " + WHITE + " |" + RESET + "\n"

            + WHITE + "|       |     |     |     |      |      |      |      |      |      |      |      |      |        |" + RESET + "\n"
            + WHITE + "+-------+-----+-----+-----+------+------+------+------+------+------+------+------+------+--------+" + RESET + "\n"
            + WHITE + "        |                        |                           |                           |" + RESET + "\n"

            + WHITE + "        |        " + YELLOW + " 1st12  " + WHITE + "        |          " + YELLOW + " 2nd12  " + WHITE
            + "         |          " + YELLOW + " 3rd12  " + WHITE + "         |" + RESET + "\n"

            + WHITE + "        |                        |                           |                           |" + RESET + "\n"
            + WHITE + "        +-----------+------------+-------------+-------------+-------------+-------------+" + RESET + "\n"
            + WHITE + "        |           |            |             |             |             |             |" + RESET + "\n"

            + WHITE + "        | " + YELLOW + "  1to18  " + WHITE + " |   " + CYAN + " EVEN " + WHITE + "   |    " + RED + " RED "
            + WHITE + "    | " + RESET + "   BLACK   " + WHITE + " |    " + CYAN + " ODD " + WHITE + "    |  " + YELLOW + "  19to36  " + WHITE
            + " |" + RESET + "\n"

            + WHITE + "        |           |            |             |             |             |             |" + RESET + "\n"
            + WHITE + "        +-----------+------------+-------------+-------------+-------------+-------------+" + RESET + "\n";

    for (const auto& pair : bets) {
        size_t found;
        std::string replaceString;
        int len = pair.first.length();
        if (pair.second >= 100) {
            found = game.find(" " + pair.first + " ");
            if (len >= 6) {
                replaceString = "  " + MAGENTA + std::to_string(pair.second) + WHITE + "   ";
            } else if (len >= 5) {
                replaceString = "  " + MAGENTA + std::to_string(pair.second) + WHITE + "  ";
            } else if (len >= 4) {
                replaceString = "  " + MAGENTA + std::to_string(pair.second) + WHITE + " ";
            } else if (len >= 3) {
                replaceString = " " + MAGENTA + std::to_string(pair.second) + WHITE + " ";
            } else if (len >= 2) {
                replaceString = MAGENTA + std::to_string(pair.second) + WHITE + " ";
            } else {
                replaceString = MAGENTA + std::to_string(pair.second) + WHITE;
            }
            len = len + 2;
        } else if (pair.second >= 10) {
            found = game.find(" " + pair.first + " ");
            if (len >= 6) {
                replaceString = "   " + MAGENTA + std::to_string(pair.second) + WHITE + "   ";
            } else if (len >= 5) {
                replaceString = "  " + MAGENTA + std::to_string(pair.second)[0];
                replaceString = replaceString + " " + std::to_string(pair.second)[1];
                replaceString = replaceString + WHITE + "  ";
            } else if (len >= 4) {
                replaceString = "  " + MAGENTA + std::to_string(pair.second) + WHITE + "  ";
            } else if (len >= 3) {
                replaceString = " " + MAGENTA + std::to_string(pair.second)[0];
                replaceString = replaceString + " " + std::to_string(pair.second)[1];
                replaceString = replaceString + WHITE + " ";
            } else if (len >= 2) {
                replaceString = " " + MAGENTA + std::to_string(pair.second) + WHITE + " ";
            } else {
                replaceString = MAGENTA + std::to_string(pair.second)[0];
                replaceString = replaceString + " " + std::to_string(pair.second)[1];
                replaceString = replaceString + WHITE;
            }
            len = len + 2;
        } else {
            found = game.find(" " + pair.first + " ") + 1;
            if (len >= 6) {
                replaceString = "  " + MAGENTA + std::to_string(pair.second) + WHITE + "   ";
            } else if (len >= 5) {
                replaceString = "  " + MAGENTA + std::to_string(pair.second) + WHITE + "  ";
            } else if (len >= 4) {
                replaceString = "  " + MAGENTA + std::to_string(pair.second) + WHITE + " ";
            } else if (len >= 3) {
                replaceString = " " + MAGENTA + std::to_string(pair.second) + WHITE + " ";
            } else if (len >= 2) {
                replaceString = MAGENTA + std::to_string(pair.second) + WHITE + " ";
            } else {
                replaceString = MAGENTA + std::to_string(pair.second) + WHITE;
            }
        }
        if (found != std::string::npos) {
            game.replace(found, len, replaceString);
        }
    }
    std::cout << game << std::endl;
    return game;
}

int Roulette::getBalance() {
    return balance;
}

void Roulette::play() {
    if (balance <= 0) {
        return;
    }
    int initialBalance = balance;
    std::map<std::string, std::pair<std::string, bool>>  betChoice = build();
    std::map<std::string, int> bet = getBet(betChoice);
    std::string result = spin();
    std::cout << game << std::endl;
    displaySpin(betChoice, result);
    std::map<std::string, std::pair<std::string, bool>>  betResult = makeResult(betChoice, result);
    calcResult(betResult, bet);

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

std::map<std::string, std::pair<std::string, bool>> Roulette::build() {
    std::map<std::string, std::pair<std::string, bool>> bet;
    bet["RED"] = std::make_pair("RED", false); bet["BLACK"] = std::make_pair("BLACK", false);
    bet["EVEN"] = std::make_pair("", false); bet["ODD"] = std::make_pair("", false);
    bet["1to18"] = std::make_pair("", false); bet["19to36"] = std::make_pair("", false);
    bet["1st12"] = std::make_pair("", false); bet["2nd12"] = std::make_pair("", false); bet["3rd12"] = std::make_pair("", false);
    bet["0"] = std::make_pair("", false);
    bet["1"] = std::make_pair("RED", false); bet["2"] = std::make_pair("BLACK", false); bet["3"] = std::make_pair("RED", false);
    bet["4"] = std::make_pair("BLACK", false); bet["5"] = std::make_pair("RED", false); bet["6"] = std::make_pair("BLACK", false);
    bet["7"] = std::make_pair("RED", false); bet["8"] = std::make_pair("BLACK", false); bet["9"] = std::make_pair("RED", false);
    bet["10"] = std::make_pair("BLACK", false); bet["11"] = std::make_pair("BLACK", false); bet["12"] = std::make_pair("RED", false);
    bet["13"] = std::make_pair("BLACK", false); bet["14"] = std::make_pair("RED", false); bet["15"] = std::make_pair("BLACK", false);
    bet["16"] = std::make_pair("RED", false); bet["17"] = std::make_pair("BLACK", false); bet["18"] = std::make_pair("RED", false);
    bet["19"] = std::make_pair("RED", false); bet["20"] = std::make_pair("BLACK", false); bet["21"] = std::make_pair("RED", false);
    bet["22"] = std::make_pair("BLACK", false); bet["23"] = std::make_pair("RED", false); bet["24"] = std::make_pair("BLACK", false);
    bet["25"] = std::make_pair("RED", false); bet["26"] = std::make_pair("BLACK", false); bet["27"] = std::make_pair("RED", false);
    bet["28"] = std::make_pair("BLACK", false); bet["29"] = std::make_pair("BLACK", false); bet["30"] = std::make_pair("RED", false);
    bet["31"] = std::make_pair("BLACK", false); bet["32"] = std::make_pair("RED", false); bet["33"] = std::make_pair("BLACK", false);
    bet["34"] = std::make_pair("RED", false); bet["35"] = std::make_pair("BLACK", false); bet["36"] = std::make_pair("RED", false);
    return bet;
}

std::map<std::string, int> Roulette::getBet(std::map<std::string, std::pair<std::string, bool>> betChoice) {
    std::map<std::string, int> bet;
    do {
        game = showGame(bet);
        std::string betValueChoice;
        std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  | YOUR BALANCE : " << RED << std::setw(8) << std::right << balance << RESET << " |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+\n" << std::endl;

        std::cout << "\t\t\t\t\t\t +-------- " << MAGENTA << "0" << RESET << " --------+ " <<
                  "  +-------- " << MAGENTA << "1" << RESET << " --------+" << std::endl;
        std::cout << "\t\t\t\t\t\t |     " << CYAN << " S T O P " << RESET << "     | " << "  |     " << YELLOW << " ALL  IN " << RESET << "     |" << std::endl;
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
        std::cin >> betValueChoice;
        if (betValueChoice == "1") {
            bet = addBet(betChoice, bet, balance);
        } else if (betValueChoice == "2") {
            bet = addBet(betChoice, bet, 1);
        } else if (betValueChoice == "3" && balance >= 5) {
            bet = addBet(betChoice, bet, 5);
        } else if (betValueChoice == "4" && balance >= 10) {
            bet = addBet(betChoice, bet, 10);
        } else if (betValueChoice == "5" && balance >= 25) {
            bet = addBet(betChoice, bet, 25);
        } else if (betValueChoice == "6" && balance >= 50) {
            bet = addBet(betChoice, bet, 50);
        } else if (betValueChoice == "7" && balance >= 100) {
            bet = addBet(betChoice, bet, 100);
        } else {
            break;
        }
    } while (balance > 0);
    return bet;
}

std::map<std::string, int> Roulette::addBet(std::map<std::string, std::pair<std::string, bool>> betChoice, std::map<std::string, int> bet, int betAddValue) {
    std::string betAddChoice;
    std::cout << "What do you want to add your bet to?" << std::endl;
    std::cin >> betAddChoice;
    if (betChoice.find(betAddChoice) != betChoice.end()) {
        if (bet.find(betAddChoice) != bet.end()) {
            bet[betAddChoice] = bet[betAddChoice] + betAddValue;
        } else {
            bet[betAddChoice] = betAddValue;
        }
    } else {
        return bet;
    }
    balance -= betAddValue;
    return bet;
}

std::string Roulette::spin() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 36);
    int randomNum = dis(gen);
    std::string randomNumStr = std::to_string(randomNum);
    return randomNumStr;
}

void Roulette::displaySpin(std::map<std::string, std::pair<std::string, bool>> betChoice, std::string result) {
    if (result.length() >= 2) {
        if (betChoice[result].first == "RED") {
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|     " << RED << result[0] << " " << result[1] << WHITE << "     |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
        } else {
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|     " << RESET << result[0] << " " << result[1] << WHITE << "     |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
        }
    } else {
        if (betChoice[result].first == "RED") {
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|      " << RED << result << WHITE << "      |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
        } else if (betChoice[result].first == "BLACK"){
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|      " << WHITE << result << WHITE << "      |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
        } else {
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|      " << GREEN << result << WHITE << "      |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t|             |" << RESET << std::endl;
            std::cout << WHITE << "\t\t\t\t\t\t\t\t\t\t+------+------+" << RESET << std::endl;
        }
    }
}

std::map<std::string, std::pair<std::string, bool>> Roulette::makeResult(std::map<std::string, std::pair<std::string, bool>> betChoice, std::string result) {
    if (std::stoi(result) >= 1 && std::stoi(result) <= 18) {
        betChoice["1to18"].second = true;
        if (std::stoi(result) <= 12) {
            betChoice["1st12"].second = true;
        } else {
            betChoice["2nd12"].second = true;
        }
    } else if (std::stoi(result) <= 36) {
        betChoice["19to36"].second = true;
        if (std::stoi(result) <= 24) {
            betChoice["2nd12"].second = true;
        } else {
            betChoice["3rd12"].second = true;
        }
    }
    if ((std::stoi(result) % 2) == 0) {
        betChoice["EVEN"].second = true;
    } else {
        betChoice["ODD"].second = true;
    }
    if (betChoice[result].first == "RED") {
        betChoice["RED"].second = true;
    } else if (betChoice[result].first == "BLACK") {
        betChoice["BLACK"].second = true;
    }
    betChoice[result].second = true;
    return betChoice;
}

int Roulette::calcResult(std::map<std::string, std::pair<std::string, bool>> betResult, std::map<std::string, int> bet) {
    for (const auto& pair : bet) {
        if (betResult[pair.first].second) {
            balance += pair.second * 2;
        }
    }
    return balance;
}