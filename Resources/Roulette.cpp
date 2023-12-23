//
// Created by ethan on 23/12/2023.
//

#include "../headers/Roulette.h"

#include <iostream>
#include <map>
#include <string>
#include <random>

Roulette::Roulette(int initialBalance) : balance(initialBalance){}

void Roulette::init() {
    std::cout << "Welcome to the roulette game!" << std::endl;
}

int Roulette::getBalance() {
    return balance;
}

void Roulette::play() {
    if (balance <= 0) {
        return;
    }
    std::map<std::string, std::pair<std::string, bool>>  betChoice = build();
    std::map<std::string, int> bet = getBet(betChoice);
    displayBet(bet);
    std::string result = spin();
    displaySpin(betChoice, result);
    std::map<std::string, std::pair<std::string, bool>>  betResult = makeResult(betChoice, result);
    calcResult(betResult, bet);

    std::cout << "Your balance: " << balance << std::endl;
    std::cout << "----------" << std::endl;
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
        std::string betValueChoice;
        int i = 0;
        std::cout << "----------" << std::endl;
        std::cout << "Your balance: " << balance << std::endl;
        std::cout << "----------" << std::endl;
        std::cout <<  i << ": Stop" << std::endl;
        i++;
        std::cout <<  i << ": All-In" << std::endl;
        i++;
        std::cout << i << ": 1" << std::endl;
        i++;
        if (balance >= 5) {
            std::cout <<  i << ": 5" << std::endl;
            i++;
        }
        if (balance >= 10) {
            std::cout <<  i << ": 10" << std::endl;
            i++;
        }
        if (balance >= 25) {
            std::cout <<  i << ": 25" << std::endl;
            i++;
        }
        if (balance >= 50) {
            std::cout <<  i << ": 50" << std::endl;
            i++;
        }
        if (balance >= 100) {
            std::cout <<  i << ": 100" << std::endl;
            i++;
        }
        std::cout << "----------" << std::endl;
        std::cout << "Which options do you choose?" << std::endl;
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
    } while (balance > 100);
    return bet;
}

std::map<std::string, int> Roulette::addBet(std::map<std::string, std::pair<std::string, bool>> betChoice, std::map<std::string, int> bet, int betAddValue) {
    std::string betAddChoice;
    std::cout << "----------" << std::endl;
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

void Roulette::displayBet(std::map<std::string, int> bet) {
    std::cout << "----------" << std::endl;
    std::cout << "Here is the list of your bets:" << std::endl;
    for (const auto& pair : bet) {
        if (pair.first == "RED") {
            std::cout << "🔴 " << pair.second << std::endl;
        } else if (pair.first == "BLACK"){
            std::cout << "⚫ " << pair.second << std::endl;
        } else if (pair.first == "0") {
            std::cout << "❇️ " << pair.second << std::endl;
        } else {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
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
    if (result.length() > 1) {
        if (betChoice[result].first == "RED") {
            std::cout << "┌───────┐\n" << "│ " << result << " 🔴" << " |\n" << "└───────┘" << std::endl;
        } else {
            std::cout << "┌───────┐\n" << "│ " << result << " ⚫" << " |\n" << "└───────┘" << std::endl;
        }
    } else {
        if (betChoice[result].first == "RED") {
            std::cout << "┌──────┐\n" << "│ " << result << " 🔴" << " |\n" << "└──────┘" << std::endl;
        } else if (betChoice[result].first == "BLACK"){
            std::cout << "┌──────┐\n" << "│ " << result << " ⚫" << " |\n" << "└──────┘" << std::endl;
        } else {
            std::cout << "┌──────┐\n" << "│ " << result << " ❇️" << " |\n" << "└──────┘" << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
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