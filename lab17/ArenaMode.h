#ifndef ARENAMODE_H
#define ARENAMODE_H

#include <string>
#include <vector>
#include "Observer.h"

namespace ArenaMode {

class Character : public Subject {
protected:
    std::string name;
    static int objectCount;
    std::vector<Observer*> observers;

    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;
    int health;

public:
    Character(const std::string& n, const std::vector<int>& stats);
    virtual void attack() = 0;
    virtual void takeDamage(int amount);
    virtual ~Character();

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers(const std::string& message) override;

    static int getObjectCount();
};

class Mage : public Character {
    int mana;

public:
    Mage(const std::vector<int>& stats);
    void attack() override;
    static int getDefaultMana();
};

class Warrior : public Character {
    int rage;

public:
    Warrior(const std::vector<int>& stats);
    void attack() override;
    void shout(const std::string& phrase);
};

class Thief : public Character {
    int stealth;

public:
    Thief(const std::vector<int>& stats);
    void attack() override;
};

class Ogre : public Character {
    int bruteForce;

public:
    Ogre(const std::vector<int>& stats);
    void attack() override;
    int getBruteForce() const;
};

} 

#endif
