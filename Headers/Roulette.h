//
// Created by ethan on 23/12/2023.
//

#include <string>
#include <map>

#ifndef CASINO_ROULETTE_H
#define CASINO_ROULETTE_H

class Roulette {
public:
    Roulette(int initialBalance);
    void init();
    void play();
    int getBalance();
    std::map<std::string, std::pair<std::string, bool>> build();
    void test();

private:
    int balance;
    std::map<std::string, int> getBet(std::map<std::string, std::pair<std::string, bool>> betChoice);
    std::map<std::string, int> addBet(std::map<std::string, std::pair<std::string, bool>> betChoice, std::map<std::string, int> bet, int betAddValue);
    void displayBet(std::map<std::string, int> bet);
    std::string spin();
    void displaySpin(std::map<std::string, std::pair<std::string, bool>> betChoice, std::string result);
    std::map<std::string, std::pair<std::string, bool>> makeResult(std::map<std::string, std::pair<std::string, bool>> betChoice, std::string result);
    int calcResult(std::map<std::string, std::pair<std::string, bool>> betResult, std::map<std::string, int> bet);
};

#endif //CASINO_ROULETTE_H
