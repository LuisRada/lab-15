#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
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


template<class A, class B>
void getHigherStat(const A* a, const B* b, const string& fieldName) {
    if (!a || !b) {
        cout << "Null pointer passed to getHigherStat." << endl;
        return;
    }
    int valA = a->getHealth();
    int valB = b->getHealth();
    if (valA > valB) {
        cout << a->getName() << " has " << fieldName << " = "
             << valA << " (higher than "
             << b->getName() << "'s " << fieldName << " = "
             << valB << ")." << endl;
    }
    else if (valB > valA) {
        cout << b->getName() << " has " << fieldName << " = "
             << valB << " (higher than "
             << a->getName() << "'s " << fieldName << " = "
             << valA << ")." << endl;
    }
    else {
        cout << "Tie: both " << a->getName() << " and "
             << b->getName() << " have " << fieldName
             << " = " << valA << "." << endl;
    }
}

template <class T>
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
    if (choice == "Mage") {
        cout << "Enter mana: "; cin >> extra;
        return new Mage(name, str, dex, end, intl, cha, respect, sacredArmor, extra);
    }
    if (choice == "Warrior") {
        cout << "Enter stamina: "; cin >> extra;
        return new Warrior(name, str, dex, end, intl, cha, respect, sacredArmor, extra);
    }
    if (choice == "Berserker") {
        cout << "Enter rage: "; cin >> extra;
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
    if (choice == "Thief") {
        cout << "Enter stealth: "; cin >> extra;
        return new Thief(name, str, dex, end, intl, cha, evilness, evilArmor, extra);
    }
    if (choice == "Ogre") {
        cout << "Enter brute force: "; cin >> extra;
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
    if (!monster) {
        delete hero;
        return 1;
    }

    cout << "\nBattle begins between "
         << hero->getName()
         << " and " << monster->getName()
         << "!" << endl;

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
        }
        FieldModifier<Hero> heroField;
        heroField.printStats(hero);
    } else {
        FieldModifier<Monster> monsterField;
        monsterField.printStats(monster);
    }

    Special_Character* mySpecial = new Special_Character("Mystery", 80);
    FieldModifier<Special_Character> specialModifier;
    specialModifier.increaseHealth(mySpecial, 20);
    specialModifier.printStats(mySpecial);

    if (heroWins) {
        getHigherStat(hero, mySpecial, "health");
    } else {
        getHigherStat(monster, mySpecial, "health");
    }

    delete monster;
    delete hero;
    delete mySpecial;
    return 0;
}
