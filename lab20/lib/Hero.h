#pragma once
#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include <string>
#include <vector>

#include <thread>
#include <chrono>

class Hero : public Character {
public:
    Hero(const std::string& name, const std::vector<int>& stats);
    virtual void battleCry() const = 0;

    void performTask() override

    {
        std :: this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Hero task complete" << std::endl;
    }

    virtual ~Hero() = default;
};

#endif