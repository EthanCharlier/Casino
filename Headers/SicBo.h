//
// Created by ethan on 10/01/2024.
//

#include <iostream>
#include <utility>
#include <list>
#include <map>

#ifndef CASINO_SICBO_H
#define CASINO_SICBO_H

class SicBo {
public:
    SicBo(int initialBalance);
    bool init();
    void play();
    int getBalance();

private:
    int balance;
    std::pair<std::string, int> getBet();
    std::list<int> rollDices();
    std::map<int, int> displayRoll(std::list<int> diceList);

    int calcResult(std::pair<std::string, int> bet, std::map<int, int> diceList);
    int makeSum(std::map<int, int> diceList);
};

#endif //CASINO_SICBO_H
