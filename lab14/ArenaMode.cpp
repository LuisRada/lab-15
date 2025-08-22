#include "ArenaMode.h"

namespace ArenaMode {

    int Character::objectCount = 0;

    int Character::getObjectCount() {
        return objectCount;
    }

    Mage::Mage() : mana(getDefaultMana()) {
        Character::objectCount++;
    }

    void Mage::attack() {
        std::cout << "Mage attacking in Arena mode" << std::endl;
    }

    int Mage::getDefaultMana() {
        return 100;
    }

    Warrior::Warrior() {
        Character::objectCount++;
    }

    void Warrior::attack() {
        std::cout << "Warrior attacking in Arena mode" << std::endl;
    }

    void Warrior::shout(const std::string& phrase) {
        std::cout << phrase << std::endl;
    }

    Ogre::Ogre(int str) : strength(str) {
        Character::objectCount++;
    }

    void Ogre::attack() {
        std::cout << "Ogre attacking in Arena mode" << std::endl;
    }

    int ArenaMode::Ogre::getStrength() const {
    // strength += 10; - Here is the error, I cannot modify in a const metod
    return strength;
    }


}