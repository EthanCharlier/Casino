//
// Created by ethan on 22/12/2023.
//

#include "../headers/Craps.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Craps::Craps(int initialBalance) : balance(initialBalance) {}

void Craps::init() {
    std::cout << "Welcome to the craps game!" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

int Craps::getBalance() {
    return balance;
}

void Craps::play() {
    if (balance <= 0) {
        return;
    }
    int bet = getBet();
    balance -= bet;

    int dices = rollDices();
    int result = calcResult(dices, bet);
    balance += result;
    std::cout << "----------" << std::endl;
    std::cout << "Your balance: " << balance << std::endl;
    std::cout << "----------" << std::endl;
}

int Craps::getBet() {
    int bet;
    std::string betChoice;
    int i = 1;
    std::cout << "----------" << std::endl;
    std::cout << "Your balance: " << balance << std::endl;
    std::cout << "----------" << std::endl;
    std::cout <<  i << ": All-In" << std::endl;
    i++;
    std::cout << i << ": 1" << std::endl;
    i++;
    if (balance >=10) {
        std::cout <<  i << ": 10" << std::endl;
        i++;
    }
    if (balance >=100) {
        std::cout <<  i << ": 100" << std::endl;
        i++;
    }
    std::cout <<  i << ": ..." << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "Which options do you choose?" << std::endl;
    std::cin >> betChoice;
    if (betChoice == "1") {
        bet = balance;
    } else if (betChoice == "2") {
        bet = 1;
    } else if (betChoice == "3" && balance >= 10) {
        bet = 10;
    } else if (betChoice == "4" && balance >= 100) {
        bet = 100;
    } else {
        std::cout << "----------" << std::endl;
        do {
            std::cout << "How much is your bet? (" << balance << ")" << std::endl;
            std::cin >> bet;
        } while (bet < 1 || bet > balance);
    }
    std::cout << "----------" << std::endl;
    return bet;
}

int Craps::rollDices() {
    int first = rand() % 6 + 1;
    int second = rand() % 6 + 1;
    int sum = first + second;
    return sum;
}

void Craps::displayRoll(int newResult, int point) {
    if (newResult == 7) {
        std::cout << " ❌ "<< newResult << std::endl;
    } else if (newResult == point) {
        std::cout << " ✅ "<< newResult << std::endl;
    } else {
        std::cout << " 🔀 "<< newResult << std::endl;
    }
}

int Craps::calcResult(int dices, int bet) {
    if (dices == 7 || dices == 11) {
        std::cout << "✅ "<< dices << std::endl;
        return bet * 2;
    } else if (dices == 2 || dices == 3 || dices == 12) {
        std::cout << "❌ "<< dices << std::endl;
        return bet * 0;
    } else {
        std::cout << "➡️ "<< dices << std::endl;
        int point = dices;
        while (true) {
            int newResult = rollDices();
            displayRoll(newResult, point);
            if (newResult == point) {
                return bet * 1;
            } else if (newResult == 7) {
                return bet * 0;
            }
        }
    }
}