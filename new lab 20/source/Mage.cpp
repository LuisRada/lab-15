#include "Mage.h"
#include <thread>
#include <chrono>
#include <iostream>

Mage::Mage(const std::string& name, const std::vector<int>& stats)
    : Character(name, stats[0], stats[1], stats[2], stats[3]), mana(stats[4]) {
    inventory = { "Staff", "Robe", "Spellbook" };
}

void Mage::battleCry() const {
    std::cout << "Mage " << name << " shouts: Feel the wrath of my magic!\n";
}

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

void Mage::performTask() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Mage task complete\n";
}

std::string computeResult() override
{
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return "result from Mage";
}


Mage::~Mage() {}
