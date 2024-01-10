#include "headers/SlotMachine.h"
#include "headers/Craps.h"
#include "headers/Roulette.h"
#include "headers/SicBo.h"

#include <iostream>
#include <string>
#include <iomanip>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string MAGENTA = "\033[35m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";

int slotMachineGame(int balance) {
    SlotMachine slotMachine(balance);
    if (!slotMachine.init()) {
        return balance;
    }
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
    if (!craps.init()) {
        return balance;
    }
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
    if (!roulette.init()) {
        return balance;
    }
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

int sicBoGame(int balance) {
    SicBo sicBo(balance);
    if (!sicBo.init()) {
        return balance;
    }
    char playAgain;
    do {
        sicBo.play();
        if (sicBo.getBalance() > 0) {
            std::cout << "Play again? (y/n) ";
            std::cin >> playAgain;
            std::cin.ignore();
            std::cout << std::endl;
        } else {
            break;
        }
    } while (playAgain == 'y' || playAgain == 'Y');
    std::cout << "Thank you!" << std::endl;
    return sicBo.getBalance();
}

int main() {
    int userBalance = 300;

    bool stop = false;

    do {
        if (userBalance == 0) {
            break;
        }
        std::string gameChoice;

        std::cout << "\n\t\t\t\t\t\t\t   +-------------------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t   |        " << CYAN << " W E L C O M E " << RESET << "        |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t   +-------------------------------+\n\n" << std::endl;

        std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  | YOUR BALANCE : " << RED << std::setw(8) << std::right << userBalance << RESET << " |" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t  +-------------------------+\n" << std::endl;

        std::cout << "\t\t\t\t\t\t   +------------------ " << MAGENTA << "1" << RESET << " ------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t   |       " << YELLOW << " S L O T   M A C H I N E " << RESET << "       |" << std::endl;
        std::cout << "\t\t\t\t\t\t   +------------------ " << MAGENTA << "1" << RESET << " ------------------+\n" << std::endl;

        std::cout << "\t\t\t\t\t\t   +------------------ " << MAGENTA << "2" << RESET << " ------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t   |         " << YELLOW << " C R A P S   G A M E " << RESET << "         |" << std::endl;
        std::cout << "\t\t\t\t\t\t   +------------------ " << MAGENTA << "2" << RESET << " ------------------+\n" << std::endl;

        std::cout << "\t\t\t\t\t\t   +------------------ " << MAGENTA << "3" << RESET << " ------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t   |           " << YELLOW << " R O U L E T T E " << RESET << "           |" << std::endl;
        std::cout << "\t\t\t\t\t\t   +------------------ " << MAGENTA << "3" << RESET << " ------------------+\n" << std::endl;

        std::cout << "\t\t\t\t\t\t   +------------------ " << MAGENTA << "4" << RESET << " ------------------+" << std::endl;
        std::cout << "\t\t\t\t\t\t   |             " << YELLOW << " S I C   B O " << RESET << "             |" << std::endl;
        std::cout << "\t\t\t\t\t\t   +------------------ " << MAGENTA << "4" << RESET << " ------------------+\n" << std::endl;

        std::cout << "\t\t\t\t\t\t\t\t\t +-------- " << MAGENTA << "0" << RESET << " --------+ " << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t |     " << CYAN << " S T O P " << RESET << "     | " << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t\t +-------- " << MAGENTA << "0" << RESET << " --------+ " << std::endl;

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
            case 4:
                userBalance = sicBoGame(userBalance);
                break;
            default:
                stop = true;
                std::cout << "\n\t\t\t\t\t\t\t\t +-----------------------+" << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t |    " << CYAN << " G O O D B Y E " << RESET << "    | " << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t +-----------------------+\n" << std::endl;
                break;
        }
    } while (!stop);
    return userBalance;
}