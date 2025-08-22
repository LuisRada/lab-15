#pragma once
#ifndef OGRE_H
#define OGRE_H

#include "MonsterList.h"
#include <vector>
#include <string>
#include <iostream>

class Ogre : public Monster {
public:
    Ogre(const std::string& name, const std::vector<int>& stats);
    void taunt() const override;
    void attack() override;
    void display() const override;
    void describe() const override;
    int getPowerLevel() const override;
    std::vector<int> getStats() const override;

    void logStatus() override
    {
        std::cout<<"ogre says hes okay :)))";
    }

    ~Ogre() override;
};

#endif
