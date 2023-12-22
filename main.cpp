#include "headers/SlotMachine.h"

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

int main() {
    int userBalance = 300;

    std::string gameChoice;
    std::cout << "\nWelcome to our casino!\n" << std::endl;
    std::cout << "Here is the list of our games:" << std::endl;
    std::cout << "1: Slot Machine" << std::endl;
    std::cout << "2: work in progress" << std::endl;
    std::cout << "3: work in progress" << std::endl;
    std::cout << "\nYour balance: " << userBalance << std::endl;
    std::cout << "\nWhat game would you like to play?" << std::endl;
    std::cin >> gameChoice;
    switch (std::stoi(gameChoice)) {
        case 1:
            userBalance = slotMachineGame(userBalance);
    }

    return userBalance;
}