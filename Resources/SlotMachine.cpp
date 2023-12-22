//
// Created by ethan on 22/12/2023.
//

#include "../headers/SlotMachine.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>

SlotMachine::SlotMachine(int initialBalance) : balance(initialBalance) {}

void SlotMachine::init() {
    std::cout << "Welcome to the slot machine!" << std::endl;
}

int SlotMachine::getBalance() {
    return balance;
}

void SlotMachine::play() {
    if (balance <= 0) {
        return;
    }
    int bet = getBet();
    balance -= bet;

    std::string reels[5];
    spinReels(reels);
    std::map<std::string, int> results = displayReels(reels);

    int result = calcResult(results, bet);
    balance += result;

    std::cout << "Your balance: " << balance << std::endl;
    std::cout << "----------" << std::endl;
}

int SlotMachine::getBet() {
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

void SlotMachine::spinReels(std::string reels[5]) {
    const std::string symbols[] = {"🍀", "💲", "💵", "🍇", "🍋", "🍒", "🎲", "7"};
    srand(time(0));
    for (int i = 0; i < 5; ++i) {
        int randomIndex = rand() % (sizeof(symbols) / sizeof(symbols[0]));
        reels[i] = symbols[randomIndex];
    }
}

std::map<std::string, int> SlotMachine::displayReels(std::string reels[5]) {
    std::map<std::string, int> results;
    for (int i = 0; i < 5; ++i ) {
        std::cout << reels[i] << " ";
        if (results.find(reels[i]) != results.end()) {
            results[reels[i]] = results[reels[i]] + 1;
        } else {
            results[reels[i]] = 1;
        }
    }
    std::cout << std::endl;
    std::cout << "----------" << std::endl;
    return results;
}

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
