#include "Mage.h"
using namespace std;

Mage::Mage(string name, int str, int dex, int end, int intl, int cha, int respect, int sacredArmor, int mana)
    : Hero(name, str, dex, end, intl, cha, respect, sacredArmor), mana(mana) { health = 100; }
Mage::Mage(int mana) : Hero("DefaultMage", 5,5,5,5,5,5,5), mana(mana) { health = 100; }
void Mage::battleCry() const { cout << "Mage: Fireball!" << endl; }
void Mage::display() const {
    Hero::display();
    cout << "Mana: " << mana
         << ", Health: " << health << endl;
}
void Mage::describe() const { cout << "Mage: " << name << ", Mana: " << mana << endl; }
void Mage::increaseHealth(int amount) { health += amount; }
void Mage::displayStats() const { display(); }
Mage::~Mage() { cout << "Mage destructor called" << endl; }
