#include "Ogre.h"

Ogre::Ogre(const std::string& name, const std::vector<int>& stats)
    : Monster(name, stats) {}

void Ogre::taunt() const {
    std::cout << name << " taunts: Feel my wrath!" << std::endl;
}

void Ogre::display() const {
    Monster::display();
}

void Ogre::describe() const {
    int bruteForce = stats[MANA];
    std::cout << "Ogre: " << name << ", Brute Force: " << bruteForce << std::endl;
}

int Ogre::getPowerLevel() const {
    int bruteForce = stats[MANA];
    return stats[STRENGTH] + stats[DEXTERITY] + stats[ENDURANCE] + stats[INTELLIGENCE] + stats[CHARISMA] + stats[RESPECT] + stats[SACRED_ARMOR] + bruteForce;
}

std::vector<int> Ogre::getStats() const {
    int bruteForce = stats[MANA];
    return { stats[HEALTH], stats[STRENGTH], stats[DEXTERITY], stats[ENDURANCE], stats[INTELLIGENCE], stats[CHARISMA], stats[RESPECT], stats[SACRED_ARMOR], bruteForce };
}


void Ogre::attack() {
    std::string msg = name + " Ogre is attacking " + std::to_string(getPowerLevel());
    notifyObservers(msg);
}

void Ogre::logStatus() {}


Ogre::~Ogre() {}