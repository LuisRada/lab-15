#include "Mage.h"

Mage::Mage(const std::string& name, const std::vector<int>& stats)
    : Character(name, stats[0], stats[1], stats[2], stats[3]), mana(stats[4]) {
    inventory = { "Staff", "Robe", "Spellbook" };
}

void Mage::battleCry() const {
    std::cout << "Mage " << name << " shouts: Feel the wrath of my magic!\n";
}

void Mage::moves() const {}

void Mage::attack() {
    std::cout << name << " casts a fireball!\n";
}

void Mage::showInventory() const {
    std::cout << "Inventory of " << name << ":\n";
    for (const auto& item : inventory) {
        std::cout << "- " << item << "\n";
    }
}

void Mage::printStats() const {
    Character::printStats();
    std::cout << "Mana: " << mana << "\n";
}

std::string Mage::getType() const {
    return "Mage";
}

Mage::~Mage() {}
