#include "AdventureMode.h"
#include <iostream>
namespace AdventureMode {
void Character::attack() {}
Character::~Character() {}
void Warrior::attack() {
    std::cout << "Attacking in adventure mode" << std::endl;
}
}
