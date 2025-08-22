#pragma once
#ifndef MAGE_H
#define MAGE_H

#include "Hero.h"
#include <vector>
#include <string>
#include <iostream>

#include <thread>
#include <chrono>

class Mage : public Hero {
public:
    //Mage(const std::string& name, const std::vector<int>& stats);
    
    void performTask() override

    {
        std :: this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Mage task complete" << std::endl;
    }

    /*
    void battleCry() const override;
    void attack() override;
    void display() const override;
    void describe() const override;
    void increaseHealth(int amount);
    void displayStats() const;
    int getPowerLevel() const override;
    std::vector<int> getStats() const override;

    */
    ~Mage() override;
};

#endif

