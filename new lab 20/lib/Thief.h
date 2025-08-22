#pragma once
#ifndef THIEF_H
#define THIEF_H

#include "Character.h"
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

class Thief : public Character {
private:
    int agility;
    std::vector<std::string> inventory;
public:
    Thief(const std::string& name, const std::vector<int>& stats);
    void battleCry() const override;
    void attack() override;
    void showInventory() const override;
    void printStats() const override;
    std::string getType() const override;
    void performTask() override;
    std::string computeResult() override;
    ~Thief() override;

};

#endif
