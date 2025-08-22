#include "GameEngine.h"
#include <iostream>
namespace GameEngine {
Character::Character(const std::string& n, const std::vector<int>& stats)
    : name(n),
      strength(stats[1]), dexterity(stats[2]), endurance(stats[3]),
      intelligence(stats[4]), charisma(stats[5]), health(stats[0]) {}
void Character::display() const {
    std::cout << "Name: " << name
              << "\nStrength: " << strength
              << "\nDexterity: " << dexterity
              << "\nEndurance: " << endurance
              << "\nIntelligence: " << intelligence
              << "\nCharisma: " << charisma
              << "\nHealth: " << health << std::endl;
}
Character::~Character() {}

Hero::Hero(const std::string& n, const std::vector<int>& stats)
    : Character(n, stats),
      respect(stats[6]), sacredArmor(stats[7]), mana(stats[8]) {}
void Hero::display() const {
    Character::display();
    std::cout << "Respect: " << respect
              << "\nSacred Armor: " << sacredArmor
              << "\nMana: " << mana << std::endl;
}
Hero::~Hero() {}

Mage::Mage(const std::string& n, const std::vector<int>& stats)
    : Hero(n, stats) {}
void Mage::display() const {
    Hero::display();
    std::cout << "Class: Mage" << std::endl;
}
Mage::~Mage() {}

Warrior::Warrior(const std::string& n, const std::vector<int>& stats)
    : Hero(n, stats) {}
void Warrior::display() const {
    Hero::display();
    std::cout << "Class: Warrior" << std::endl;
}
Warrior::~Warrior() {}

Monster::Monster(const std::string& n, const std::vector<int>& stats)
    : Character(n, stats),
      evilness(stats[6]), evilArmor(stats[7]) {}
void Monster::display() const {
    Character::display();
    std::cout << "Evilness: " << evilness
              << "\nEvil Armor: " << evilArmor << std::endl;
}
Monster::~Monster() {}

Thief::Thief(const std::string& n, const std::vector<int>& stats)
    : Monster(n, stats) {}
void Thief::display() const {
    Monster::display();
    std::cout << "Class: Thief" << std::endl;
}
Thief::~Thief() {}

Ogre::Ogre(const std::string& n, const std::vector<int>& stats)
    : Monster(n, stats) {}
void Ogre::display() const {
    Monster::display();
    std::cout << "Class: Ogre" << std::endl;
}
Ogre::~Ogre() {}
}
