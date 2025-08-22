#include "Mage.h"

Mage::Mage(const std::string& name, const std::vector<int>& stats)
    : Hero(name, stats) {}

void Mage::battleCry() const {
    std::cout << name << " shouts: For the arcane!" << std::endl;
}

void Mage::attack() {
    std::string msg = name + " casts a powerful spell with power " + std::to_string(getPowerLevel());
    notifyObservers(msg);
}

void Mage::display() const {
    std::cout << "Mage: " << name << std::endl;
}

void Mage::describe() const {
    std::cout << "Mage: " << name << ", Mana: " << stats[MANA] << std::endl;
}

void Mage::increaseHealth(int amount) {
    stats[HEALTH] += amount;
}

void Mage::displayStats() const {
    std::cout << "Stats: ";
    for (auto s : stats) std::cout << s << " ";
    std::cout << std::endl;
}

int Mage::getPowerLevel() const {
    return stats[STRENGTH] + stats[DEXTERITY] + stats[ENDURANCE] + stats[INTELLIGENCE] + stats[CHARISMA] + stats[SACRED_ARMOR] + stats[MANA];
}

std::vector<int> Mage::getStats() const {
    return stats;
}

Mage::~Mage() {}