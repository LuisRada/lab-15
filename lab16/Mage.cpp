#include "Mage.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Mage::Mage(string n, int str, int dex, int end, int intl, int cha, int r, int sa, int m)
    : Hero(n, str, dex, end, intl, cha, r, sa), mana(m) {}

void Mage::learnSpell(const string& spellName) {
    if (spellName == "Meteor") {
        if (mana < 10) throw logic_error("Not enough mana to learn Meteor");
        cout << name << " has learned Meteor spell!" << endl;
        mana -= 10;
    } else {
        throw logic_error("Unknown spell");
    }
}

void Mage::display() {
    cout << "Mage: " << name << " Strength: " << strength << " Dexterity: " << dexterity
         << " Endurance: " << endurance << " Intelligence: " << intelligence
         << " Charisma: " << charisma << " Respect: " << respect
         << " Sacred Armor: " << sacredArmor << " Mana: " << mana << endl;
}

void Mage::increaseHealth(int value) {
    endurance += value;
}