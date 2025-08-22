#pragma once
#include <string>
using namespace std;

class Character {
protected:
    string name;
    int strength, dexterity, endurance, intelligence, charisma;
    int health;

public:
    Character(int in_health);
    Character(string name, int str, int dex, int end, int intl, int cha);

    string getName() const;
    int getHealth() const;
    void increaseHealth(int value);

    virtual void describe() const = 0;
    virtual void display() const;

    virtual int getPowerLevel() const = 0;

    int operator+(Character const& o) const {
        return getPowerLevel() + o.getPowerLevel();
    }

    bool operator==(Character const& o) const {
        return getPowerLevel() == o.getPowerLevel();
    }

    bool operator&&(Character const& o) const {
        return getPowerLevel() > 30 && o.getPowerLevel() > 30;
    }

    virtual ~Character();
};
