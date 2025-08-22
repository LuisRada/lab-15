#pragma once
#ifndef THIEF_H
#define THIEF_H

#include "MonsterList.h"
#include <vector>
#include <iostream>

class Thief : public Monster {
    int stealth;

public:
    Thief(const std::string& name, const std::vector<int>& stats);
    void taunt() const override;
    void display() const override;
    void describe() const override;
    virtual int getPowerLevel() const override;
    virtual std::vector<int> getStats() const override;
    ~Thief() override;
};

#endif
