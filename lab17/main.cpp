#include <iostream>
#include <string>
#include <vector>
#include "UI.h"

using namespace std;

int main() {
    UI ui;

    string mode;
    cout << "Choose the Mode (Arena/Adventure): ";
    getline(cin, mode);

    vector<int> heroStats = {100, 10, 5, 5, 5, 5, 5, 5, 20};
    vector<int> monsterStats = {120, 8, 4, 6, 3, 3, 4, 4, 10};

    if (mode == "Arena" || mode == "arena") {
        string category;
        cout << "Choose your fighter category (Hero/Monster): ";
        getline(cin, category);

        if (category == "Hero" || category == "hero") {
            string heroType;
            cout << "Choose Hero type (Mage/Warrior/Thief/Ogre): ";
            getline(cin, heroType);

            if (heroType == "Mage" || heroType == "mage") {
                ArenaMode::Mage mage(heroStats);
                    mage.addObserver(&ui);
                    mage.attack();
                    mage.takeDamage(15);

            } else if (heroType == "Warrior" || heroType == "warrior") {
                ArenaMode::Warrior warrior(heroStats);
                warrior.addObserver(&ui);
                warrior.attack();
                warrior.shout("For glory!");
                warrior.takeDamage(20);

            } else if (heroType == "Thief" || heroType == "thief") {
                ArenaMode::Thief thief(heroStats);
                thief.addObserver(&ui);
                thief.attack();
                thief.takeDamage(10);

            } else if (heroType == "Ogre" || heroType == "ogre") {
                ArenaMode::Ogre ogre(heroStats);
                ogre.addObserver(&ui);
                ogre.attack();
                ogre.takeDamage(25);

            } else {
                cout << "Invalid Hero type" << endl;
            }

        } else if (category == "Monster" || category == "monster") {
            string monsterType;
            cout << "Choose Monster type (Mage/Warrior/Thief/Ogre): ";
            getline(cin, monsterType);

            if (monsterType == "Mage" || monsterType == "mage") {
                ArenaMode::Mage mage(monsterStats);
                mage.addObserver(&ui);
                mage.attack();
                mage.takeDamage(18);

            } else if (monsterType == "Warrior" || monsterType == "warrior") {
                ArenaMode::Warrior warrior(monsterStats);
                warrior.addObserver(&ui);
                warrior.attack();
                warrior.shout("Roar!");
                warrior.takeDamage(22);

            } else if (monsterType == "Thief" || monsterType == "thief") {
                ArenaMode::Thief thief(monsterStats);
                thief.addObserver(&ui);
                thief.attack();
                thief.takeDamage(12);

            } else if (monsterType == "Ogre" || monsterType == "ogre") {
                ArenaMode::Ogre ogre(monsterStats);
                ogre.addObserver(&ui);
                ogre.attack();
                ogre.takeDamage(30);

            } else {
                cout << "Invalid Monster type" << endl;
            }
        } else {
            cout << "Invalid fighter category" << endl;
        }

    } else if (mode == "Adventure" || mode == "adventure") {
        string category;
        cout << "Choose your fighter category (Hero/Monster): ";
        getline(cin, category);

        if (category == "Hero" || category == "hero") {
            string heroType;
            cout << "Choose Hero type (Mage/Warrior/Thief/Ogre): ";
            getline(cin, heroType);

            if (heroType == "Mage" || heroType == "mage") {
                AdventureMode::Mage mage(heroStats);
                mage.addObserver(&ui);
                mage.attack();
                mage.takeDamage(12);

            } else if (heroType == "Warrior" || heroType == "warrior") {
                AdventureMode::Warrior warrior(heroStats);
                warrior.addObserver(&ui);
                warrior.attack();
                warrior.takeDamage(18);

            } else if (heroType == "Thief" || heroType == "thief") {
                AdventureMode::Thief thief(heroStats);
                thief.addObserver(&ui);
                thief.attack();
                thief.takeDamage(15);

            } else if (heroType == "Ogre" || heroType == "ogre") {
                AdventureMode::Ogre ogre(heroStats);
                ogre.addObserver(&ui);
                ogre.attack();
                ogre.takeDamage(28);

            } else {
                cout << "Invalid Hero type" << endl;
            }

        } else if (category == "Monster" || category == "monster") {
            string monsterType;
            cout << "Choose Monster type (Mage/Warrior/Thief/Ogre): ";
            getline(cin, monsterType);

            if (monsterType == "Mage" || monsterType == "mage") {
                AdventureMode::Mage mage(monsterStats);
                mage.addObserver(&ui);
                mage.attack();
                mage.takeDamage(14);

            } else if (monsterType == "Warrior" || monsterType == "warrior") {
                AdventureMode::Warrior warrior(monsterStats);
                warrior.addObserver(&ui);
                warrior.attack();
                warrior.takeDamage(20);

            } else if (monsterType == "Thief" || monsterType == "thief") {
                AdventureMode::Thief thief(monsterStats);
                thief.addObserver(&ui);
                thief.attack();
                thief.takeDamage(16);

            } else if (monsterType == "Ogre" || monsterType == "ogre") {
                AdventureMode::Ogre ogre(monsterStats);
                ogre.addObserver(&ui);
                ogre.attack();
                ogre.takeDamage(32);

            } else {
                cout << "Invalid Monster type" << endl;
            }
        } else {
            cout << "Invalid fighter category" << endl;
        }
    } else {
        cout << "Invalid mode" << endl;
    }

    cout << "Total ArenaMode characters created: " << ArenaMode::Character::getObjectCount() << endl;
    cout << "Total AdventureMode characters created: " << AdventureMode::Character::getObjectCount() << endl;

    return 0;
}
