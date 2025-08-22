#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, int hp, int power, int intelligence, int ability)
    : name(name), hp(hp), power(power), intelligence(intelligence), ability(ability) {}

void Character::printStats() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "HP: " << hp << "\n";
    std::cout << "Power: " << power << "\n";
    std::cout << "Intelligence: " << intelligence << "\n";
    std::cout << "Ability: " << ability << "\n";
}

std::string Character::getName() const {
    return name;
}

Character::~Character() {}
