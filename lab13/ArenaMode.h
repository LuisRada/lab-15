#pragma once
#include <iostream>
namespace ArenaMode {
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
