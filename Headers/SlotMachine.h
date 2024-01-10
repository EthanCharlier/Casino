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
    bool init();
    void play();
    int getBalance();

private:
    int balance;

    const std::string symbolsTypeFruits[8] = {"🍇", "🍉", "🍊", "🍋", "🍌", "🍎", "🍒", "🥝"};
    const std::string symbolsTypeSweets[8] = {"🍦", "🍧", "🍨", "🍩", "🍪", "🍫", "🍬", "🍭"};
    const std::string symbolsTypeHearts[8] = {"🩷", "🧡", "💛", "💚", "💙", "🩵", "💜", "🤎"};
    const std::string symbolsTypeMoon[8] = {"🌑", "🌒", "🌓", "🌔", "🌕", "🌖", "🌗", "🌘"};
    const std::string symbolsTypeWeather[8] = {"☁️", "⛅", "☀️", "🌨️", "🌩️", "🌪️", "🌧️", "🌤️"};
    const std::string symbolsTypeAnimals[8] = {"🐻", "🐨", "🐼", "🐵", "🐷", "🦊", "🐮", "🐯"};

    int slotMachineTypeChoice();

    int getBet();
    void spinReels(std::string reels[5], int userChoice);
    std::map<std::string, int> displayReels(std::string reels[5]);
    int calcResult(std::map<std::string, int> results, int bet);
};

#endif //CASINO_SLOTMACHINE_H
