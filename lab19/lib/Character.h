#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Subject.h"
#include "Observer.h"

enum StatIndex {
    HEALTH = 0,
    STRENGTH = 1,
    DEXTERITY = 2,
    ENDURANCE = 3,
    INTELLIGENCE = 4,
    CHARISMA = 5,
    RESPECT = 6,
    SACRED_ARMOR = 7,
    MANA = 8
};

class Character : public Subject {
protected:
    std::string name;
    std::vector<int> stats;
    std::vector<Observer*> observers;

public:
    Character(const std::string& in_name, const std::vector<int>& in_stats);
    virtual std::string getName() const;
    virtual void attack();
    virtual void takeDamage(int dmg);
    virtual int getPowerLevel() const = 0;
    virtual void describe() const = 0;
    virtual std::vector<int> getStats() const;

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers(const std::string& message) override;
    virtual void display() const;

    virtual void logStatus() = 0;
    virtual ~Character();
};

#endif
