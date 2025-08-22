#pragma once
#include "Character.h"

class Special_Character : public Character {
public:
    Special_Character(string name, int in_health);

    virtual void describe() const override;
    virtual void display() const override;
    void increaseHealth(int value);
    virtual int getPowerLevel() const override;
    virtual ~Special_Character();
};
