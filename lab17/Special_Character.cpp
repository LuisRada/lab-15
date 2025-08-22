#include "Special_Character.h"
using namespace std;

Special_Character::Special_Character(string n, int h)
    : name(n), health(h) {}

void Special_Character::display() const {
    cout << "Special Character: " << name << ", Health: " << health << endl;
}

void Special_Character::increaseHealth(int value) {
    health += value;
}

int Special_Character::getHealth() const {
    return health;
}
