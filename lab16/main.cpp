#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "Character.h"
#include "Hero.h"
#include "Mage.h"
#include "Warrior.h"
#include "Berserker.h"
#include "MonsterList.h"
#include "Thief.h"
#include "Ogre.h"
#include "Special_Character.h"
using namespace std;

template <typename T>
class FieldModifier {
public:
    void increaseHealth(T* obj, int value) {
        obj->increaseHealth(value);
    }
    void printStats(T* obj) {
        obj->display();
    }
};

Hero* chooseHero() {
    string choice, name;
    int str, dex, end, intl, cha, respect, sacredArmor, extra;

    cout << "Choose your Hero (Mage, Warrior, Berserker): "; cin >> choice;
    cout << "Enter hero name: "; cin >> name;

    cout << "Enter strength: "; cin >> str;
    cout << "Enter dexterity: "; cin >> dex;
    cout << "Enter endurance: "; cin >> end;
    cout << "Enter intelligence: "; cin >> intl;
    cout << "Enter charisma: "; cin >> cha;
    cout << "Enter respect: "; cin >> respect;
    cout << "Enter sacred armor: "; cin >> sacredArmor;

    if (str < 2 || dex < 2 || end < 2 || intl < 2 || cha < 2 || respect < 2 || sacredArmor < 2) {
        cout << "Invalid value: stats cannot be negative and must be at least 2." << endl;
        return nullptr;
    }

    if (choice == "Mage") {
        cout << "Enter mana: "; cin >> extra;
        if (extra < 2) { cout << "Invalid value: mana must be at least 2." << endl; return nullptr; }
        return new Mage(name, str, dex, end, intl, cha, respect, sacredArmor, extra);
    }
    if (choice == "Warrior") {
        cout << "Enter stamina: "; cin >> extra;
        if (extra < 2) { cout << "Invalid value: stamina must be at least 2." << endl; return nullptr; }
        return new Warrior(name, str, dex, end, intl, cha, respect, sacredArmor, extra);
    }
    if (choice == "Berserker") {
        cout << "Enter rage: "; cin >> extra;
        if (extra < 2) { cout << "Invalid value: rage must be at least 2." << endl; return nullptr; }
        return new Berserker(name, str, dex, end, intl, cha, respect, sacredArmor, extra);
    }

    cout << "Invalid hero choice." << endl;
    return nullptr;
}

Monster* chooseMonster() {
    string choice, name;
    int str, dex, end, intl, cha, evilness, evilArmor, extra;

    cout << "Choose your Monster (Thief, Ogre): "; cin >> choice;
    cout << "Enter monster name: "; cin >> name;

    cout << "Enter strength: "; cin >> str;
    cout << "Enter dexterity: "; cin >> dex;
    cout << "Enter endurance: "; cin >> end;
    cout << "Enter intelligence: "; cin >> intl;
    cout << "Enter charisma: "; cin >> cha;
    cout << "Enter evilness: "; cin >> evilness;
    cout << "Enter evil armor: "; cin >> evilArmor;

    if (str < 2 || dex < 2 || end < 2 || intl < 2 || cha < 2 || evilness < 2 || evilArmor < 2) {
        cout << "Invalid value: stats cannot be negative and must be at least 2." << endl;
        return nullptr;
    }

    if (choice == "Thief") {
        cout << "Enter stealth: "; cin >> extra;
        if (extra < 2) { cout << "Invalid value: stealth must be at least 2." << endl; return nullptr; }
        return new Thief(name, str, dex, end, intl, cha, evilness, evilArmor, extra);
    }
    if (choice == "Ogre") {
        cout << "Enter brute force: "; cin >> extra;
        if (extra < 2) { cout << "Invalid value: brute force must be at least 2." << endl; return nullptr; }
        return new Ogre(name, str, dex, end, intl, cha, evilness, evilArmor, extra);
    }

    cout << "Invalid monster choice." << endl;
    return nullptr;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    Hero* hero = chooseHero();
    if (!hero) return 1;

    Monster* monster = chooseMonster();
    if (!monster) { delete hero; return 1; }

    cout << "\nBattle begins between " << hero->getName()
         << " and " << monster->getName() << "!\n";

    battlescream* trigger = new battlescream();
    trigger->heroscreams(hero);

    bool heroWins = (rand() % 2 == 0);

    if (heroWins) {
        cout << hero->getName() << " wins the fight!" << endl;
    } else {
        cout << monster->getName() << " wins the fight!" << endl;
    }

    if (heroWins) {
        if (Mage* m = dynamic_cast<Mage*>(hero)) {
            FieldModifier<Mage> mageModifier;
            mageModifier.increaseHealth(m, 30);

            try {
                m->learnSpell("Meteor");
            } catch (logic_error& e) {
                cout << "Cannot learn spell: " << e.what() << endl;
            }
        }
        FieldModifier<Hero> heroField;
        heroField.printStats(hero);
    } else {
        FieldModifier<Monster> monsterField;
        monsterField.printStats(monster);
    }

    delete monster;
    delete hero;
    delete trigger;

    Special_Character* mySpecial = new Special_Character("Mystery", 80);
    FieldModifier<Special_Character> specialModifier;
    specialModifier.increaseHealth(mySpecial, 20);
    specialModifier.printStats(mySpecial);
    delete mySpecial;

    return 0;
}
