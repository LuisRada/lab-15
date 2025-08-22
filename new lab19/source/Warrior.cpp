#include "Warrior.h"

Warrior::Warrior(const std::string& name, const std::vector<int>& stats)
    : Character(name, stats[0], stats[1], stats[2], stats[3]), strength(stats[4]) {
    inventory = { "Sword", "Shield", "Armor" };
}

void Warrior::battleCry() const {
    std::cout << "Warrior " << name << " roars: For honor and glory!\n";
}

void Warrior::attack() {
    std::cout << name << " swings a mighty sword!\n";
}

void Warrior::showInventory() const {
    std::cout << "Inventory of " << name << ":\n";
    for (const auto& item : inventory) {
        std::cout << "- " << item << "\n";
    }
}

void Warrior::printStats() const {
    Character::printStats();
    std::cout << "Strength: " << strength << "\n";
}

std::string Warrior::getType() const {
    return "Warrior";
}

Warrior::~Warrior() {}
