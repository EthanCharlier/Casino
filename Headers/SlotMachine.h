//
// Created by ethan on 22/12/2023.
//

#include <string>
#include <map>

#ifndef CASINO_SLOTMACHINE_H
#define CASINO_SLOTMACHINE_H

class SlotMachine {
public:
    SlotMachine(int initialBalance);
    void init();
    void play();
    int getBalance();

private:
    int balance;
    int getBet();
    void spinReels(std::string reels[5]);
    std::map<std::string, int> displayReels(std::string reels[5]);
    int calcResult(std::map<std::string, int> results, int bet);
};

#endif //CASINO_SLOTMACHINE_H
