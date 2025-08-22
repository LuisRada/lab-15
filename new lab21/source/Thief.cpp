#include "Thief.h"

Thief::Thief(const std::string& name, const std::vector<int>& stats)
    : Character(name, stats[0], stats[1], stats[2], stats[3]), agility(stats[4]) {
    inventory = { "Dagger", "Lockpick", "Cloak" };
}

void Thief::battleCry() const {
    std::cout << "Thief " << name << " whispers: You'll never see me coming!\n";
}

void Thief::attack() {
    std::cout << name << " strikes from the shadows!\n";
}

void Thief::showInventory() const {
    std::cout << "Inventory of " << name << ":\n";
    for (const auto& item : inventory) {
        std::cout << "- " << item << "\n";
    }
}

void Thief::printStats() const {
    Character::printStats();
    std::cout << "Agility: " << agility << "\n";
}

std::string Thief::getType() const {
    return "Thief";
}

Thief::~Thief() {}
