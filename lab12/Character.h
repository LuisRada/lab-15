#pragma once
#include <string>
#include <vector>
using namespace std;

class Character {
protected:
    string name;
    int strength, dexterity, endurance, intelligence, charisma;
    int health;

public:
    Character(int in_health);
    Character(string name, int str, int dex, int end, int intl, int cha);
    Character(vector<int> stats);

    string getName() const;
    virtual void describe() const = 0;
    virtual void display() const;
    virtual int getPowerLevel() const = 0;
    virtual vector<int> getStats() const = 0;

    int operator+(Character const& o) const {
        return getPowerLevel() + o.getPowerLevel();
    }
    bool operator==(Character const& o) const {
        return health == o.health;
    }
    bool operator&&(Character const& o) const {
        return strength > 1 && o.strength > 1;
    }

    virtual ~Character();
};
