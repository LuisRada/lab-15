#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

class Warrior : public Character {
private:
    int strength;
    std::vector<std::string> inventory;
public:
    Warrior(const std::string& name, const std::vector<int>& stats);
    void battleCry() const override;
    void attack() override;
    void showInventory() const override;
    void printStats() const override;
    std::string getType() const override;
    void performTask() override;
    std::string computeResult() override;
    ~Warrior() override;
};

#endif
