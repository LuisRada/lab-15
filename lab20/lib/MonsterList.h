#pragma once
#ifndef MONSTERLIST_H
#define MONSTERLIST_H

#include "Character.h"
#include <vector>
#include <string>
#include <iostream>

#include <thread>
#include <chrono>

class Monster : public Character {
public:
    Monster(const std::string& name, const std::vector<int>& stats);
    virtual void taunt() const = 0;
    virtual void describe() const = 0;
    void display() const override;
    int getPowerLevel() const override;
    std::vector<int> getStats() const override;

    

    void performTask() override

    {
        std :: this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Monster task complete" << std::endl;
    }
    virtual ~Monster();
};

#endif
