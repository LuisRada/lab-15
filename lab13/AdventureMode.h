#pragma once
#include <iostream>
namespace AdventureMode {
class Character {
public:
    virtual void attack();
    virtual ~Character();
};
class Warrior : public Character {
public:
    void attack() override;
};
}
