#include "Special_Character.h"
#include <iostream>
using namespace std;

Special_Character::Special_Character(string name, int in_health)
    : Character(in_health)
{
    Character::name = name;
}

void Special_Character::describe() const {
    cout << name << " is special." << endl;
}

void Special_Character::display() const {
    cout << "Special Character: " << name
         << ", Health: " << health << endl;
}

void Special_Character::increaseHealth(int value) {
    health += value;
}

int Special_Character::getPowerLevel() const {
    return health;
}

Special_Character::~Special_Character() {}
