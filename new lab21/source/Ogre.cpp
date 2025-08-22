#include "Ogre.h"

Ogre::Ogre(const std::string& name, const std::vector<int>& stats)
    : Character(name, stats[0], stats[1], stats[2], stats[3]), evilness(stats[4]) {
    inventory = { "Club", "Armor", "Helmet" };
}

void Ogre::battleCry() const {
    std::cout << "Ogre " << name << " bellows: Smash everything!\n";
}

void Ogre::attack() {
    std::cout << name << " delivers a crushing blow!\n";
}

void Ogre::showInventory() const {
    std::cout << "Inventory of " << name << ":\n";
    for (const auto& item : inventory) {
        std::cout << "- " << item << "\n";
    }
}

void Ogre::printStats() const {
    Character::printStats();
    std::cout << "Evilness: " << evilness << "\n";
}

std::string Ogre::getType() const {
    return "Ogre";
}

Ogre::~Ogre() {}
