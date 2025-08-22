#include "ArenaMode.h"
#include <iostream>
namespace ArenaMode {
void Character::attack() {}
Character::~Character() {}
void Warrior::attack() {
    std::cout << "Attacking in arena mode" << std::endl;
}
}
