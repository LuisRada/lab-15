#include "ArenaMode.h"
#include <iostream>

namespace ArenaMode {

int Character::objectCount = 0;

Character::Character(const std::string& n, const std::vector<int>& stats)
    : name(n),
      strength(stats[1]), dexterity(stats[2]), endurance(stats[3]),
      intelligence(stats[4]), charisma(stats[5]), health(stats[0]) {
    ++objectCount;
}

Character::~Character() {
    --objectCount;
}

void Character::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
    notifyObservers(name + " takes " + std::to_string(amount) + " damage, health now " + std::to_string(health));
}

void Character::addObserver(Observer* o) {
    observers.push_back(o);
    o->update(name + " is now being observed");
}

void Character::removeObserver(Observer* o) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            break;
        }
    }
}

void Character::notifyObservers(const std::string& message) {
    for (auto& o : observers) {
        o->update(message);
    }
}

int Character::getObjectCount() {
    return objectCount;
}

// --------------------------

Mage::Mage(const std::vector<int>& stats)
    : Character("ArenaMage", stats),
      mana(stats[8]) {}

void Mage::attack() {
    notifyObservers(name + " (Mage) attacks!");
}

int Mage::getDefaultMana() {
    return 50;
}

// --------------------------

Warrior::Warrior(const std::vector<int>& stats)
    : Character("ArenaWarrior", stats),
      rage(stats[8]) {}

void Warrior::attack() {
    notifyObservers(name + " (Warrior) attacks!");
}

void Warrior::shout(const std::string& phrase) {
    notifyObservers(name + " shouts: " + phrase);
}

// --------------------------

Thief::Thief(const std::vector<int>& stats)
    : Character("ArenaThief", stats),
      stealth(stats[8]) {}

void Thief::attack() {
    notifyObservers(name + " (Thief) attacks!");
}

// --------------------------

Ogre::Ogre(const std::vector<int>& stats)
    : Character("ArenaOgre", stats),
      bruteForce(stats[8]) {}

void Ogre::attack() {
    notifyObservers(name + " (Ogre) attacks!");
}

int Ogre::getBruteForce() const {
    return bruteForce;
}

} 
