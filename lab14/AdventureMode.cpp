#include "AdventureMode.h"

namespace AdventureMode {

    int Character::objectCount = 0;

    int Character::getObjectCount() {
        return objectCount;
    }
    
    Mage::Mage() : mana(getDefaultMana()) {
        Character::objectCount++; 
    }

    void Mage::attack() {
        std::cout << "Mage attacking in Adventure mode" << std::endl;
    }

    int Mage::getDefaultMana() {
        return 120;
    }
  
    Warrior::Warrior() {
        Character::objectCount++; 
    }

    void Warrior::attack() {
        std::cout << "Warrior attacking in Adventure mode" << std::endl;
    }

    void Warrior::shout(const std::string& phrase) {
        std::cout << phrase << std::endl;
    }

    Ogre::Ogre(int str) : strength(str) {
        Character::objectCount++;
    }

    void Ogre::attack() {
        std::cout << "Ogre attacking in Adventure mode" << std::endl;
    }

    int Ogre::getStrength() const {
        return strength;
    }

}
