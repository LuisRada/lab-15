#pragma once
#ifndef BERSERKER_H
#define BERSERKER_H

#include "Hero.h"
#include <vector>
#include <iostream>

class Berserker : public Hero {
public:
    Berserker(const std::string& name, const std::vector<int>& stats);
    void battleCry() const override;
    void attack() override;
    void display() const override;
    void describe() const override;
    int getPowerLevel() const override;
    std::vector<int> getStats() const override;

    void logStatus() override
    {
        std::cout<<"Berserker says hes okay :)))";
    }

    ~Berserker() override;
};

#endif

