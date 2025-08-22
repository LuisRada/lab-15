#include "Warrior.h"

Warrior::Warrior(const std::string& name, const std::vector<int>& stats)
    : Hero(name, stats) {}

void Warrior::battleCry() const {
    std::cout << name << " shouts: For honor and glory!" << std::endl;
}

void Warrior::attack() {
    std::string msg = name + " swings a mighty sword with power " + std::to_string(getPowerLevel());
    notifyObservers(msg);
}

void Warrior::display() const {
    std::cout << "Warrior: " << name << std::endl;
}

void Warrior::describe() const {
    std::cout << "Warrior: " << name << ", Stamina: " << stats[MANA] << std::endl;
}

int Warrior::getPowerLevel() const {
    return stats[STRENGTH] + stats[DEXTERITY] + stats[ENDURANCE] + stats[INTELLIGENCE] + stats[CHARISMA] + stats[SACRED_ARMOR] + stats[MANA];
}

std::vector<int> Warrior::getStats() const {
    return stats;
}

Warrior::~Warrior() {}