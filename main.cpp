#include "headers/SlotMachine.h"
#include "headers/Craps.h"
#include "headers/Roulette.h"

#include <iostream>
#include <string>

int slotMachineGame(int balance) {
    SlotMachine slotMachine(balance);
    slotMachine.init();
    char playAgain;
    do {
        slotMachine.play();
        if (slotMachine.getBalance() > 0) {
            std::cout << "Play again? (y/n) ";
            std::cin >> playAgain;
            std::cin.ignore();
            std::cout << std::endl;
        } else {
            break;
        }
    } while (playAgain == 'y' || playAgain == 'Y');
    std::cout << "Thank you!" << std::endl;
    return slotMachine.getBalance();
}

int crapsGame(int balance) {
    Craps craps(balance);
    craps.init();
    char playAgain;
    do {
        craps.play();
        if (craps.getBalance() > 0) {
            std::cout << "Play again? (y/n) ";
            std::cin >> playAgain;
            std::cin.ignore();
            std::cout << std::endl;
        } else {
            break;
        }
    } while (playAgain == 'y' || playAgain == 'Y');
    std::cout << "Thank you!" << std::endl;
    return craps.getBalance();
}

int rouletteGame(int balance) {
    Roulette roulette(balance);
    roulette.init();
    char playAgain;
    do {
        roulette.play();
        if (roulette.getBalance() > 0) {
            std::cout << "Play again? (y/n) ";
            std::cin >> playAgain;
            std::cin.ignore();
            std::cout << std::endl;
        } else {
            break;
        }
    } while (playAgain == 'y' || playAgain == 'Y');
    std::cout << "Thank you!" << std::endl;
    return roulette.getBalance();
}

int main() {
    int userBalance = 99;

    bool stop = false;

    do {
        if (userBalance == 0) {
            break;
        }
        std::string gameChoice;
        std::cout << "\nWelcome to our casino!\n" << std::endl;
        std::cout << "Here is the list of our games:" << std::endl;
        std::cout << "1: Slot Machine" << std::endl;
        std::cout << "2: Craps" << std::endl;
        std::cout << "3: Roulette" << std::endl;
        std::cout << "\nYour balance: " << userBalance << std::endl;
        std::cout << "\nWhat game would you like to play?" << std::endl;
        std::cin >> gameChoice;
        switch (std::stoi(gameChoice)) {
            case 1:
                userBalance = slotMachineGame(userBalance);
                break;
            case 2:
                userBalance = crapsGame(userBalance);
                break;
            case 3:
                userBalance = rouletteGame(userBalance);
                break;
            default:
                stop = true;
                break;
        }
    } while (!stop);
    return userBalance;
}