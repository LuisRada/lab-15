#include <iostream>
#include <string>
#include "ArenaMode.h"
#include "AdventureMode.h"

using namespace std;

int main() {
    // Task 2
    cout << "Default Mage mana: " << ArenaMode::Mage::getDefaultMana() << endl;

    string mode;
    cout << "Choose the Mode (Arena/Adventure): ";
    getline(cin, mode);

    if (mode == "Arena" || mode == "arena") {
        string category;
        cout << "Choose your fighter category (Hero/Monster): ";
        getline(cin, category);

        if (category == "Hero" || category == "hero") {
            string heroType;
            cout << "Choose Hero type (Mage/Warrior): ";
            getline(cin, heroType);

            if (heroType == "Mage" || heroType == "mage") {
                ArenaMode::Mage mage;
                cout << "Mage attacking in Arena mode" << endl;
                mage.attack();
            } else if (heroType == "Warrior" || heroType == "warrior") {
                ArenaMode::Warrior warrior;
                cout << "Warrior attacking in Arena mode" << endl;
                warrior.attack();
                warrior.shout("For glory!");
                const ArenaMode::Warrior constWarrior;
                //constWarrior.shout("Try shout from const object"); // non-const method on const object - Task 3
            } else {
                cout << "Invalid Hero type" << endl;
            }
        } else if (category == "Monster" || category == "monster") {
            string monsterType;
            cout << "Choose Monster type (Ogre/Thief): ";
            getline(cin, monsterType);

                if (monsterType == "Ogre" || monsterType == "ogre") {
                    ArenaMode::Ogre ogre;
                    cout << "Ogre attacking in Arena mode" << endl;
                    ogre.attack();

                    // Task 4
                    const ArenaMode::Ogre cOgre;
                    cout << "Const Ogre strength: " << cOgre.getStrength() << endl;
                }

                else if (monsterType == "Thief" || monsterType == "thief") {
                cout << "Thief attacking in Arena mode" << endl;
                
                } 

                else {
                cout << "Invalid Monster type" << endl;

                }
        } 
                
                else {
            cout << "Invalid fighter category" << endl;
    }
    } else if (mode == "Adventure" || mode == "adventure") {
        string category;
        cout << "Choose your fighter category (Hero/Monster): ";
        getline(cin, category);

        if (category == "Hero" || category == "hero") {
            string heroType;
            cout << "Choose Hero type (Mage/Warrior): ";
            getline(cin, heroType);

            if (heroType == "Mage" || heroType == "mage") {
                AdventureMode::Mage mage;
                cout << "Mage attacking in Adventure mode" << endl;
                mage.attack();
            } else if (heroType == "Warrior" || heroType == "warrior") {
                AdventureMode::Warrior warrior;
                cout << "Warrior attacking in Adventure mode" << endl;
                warrior.attack();
            } else {
                cout << "Invalid Hero type" << endl;
            }
        } else if (category == "Monster" || category == "monster") {
            string monsterType;
            cout << "Choose Monster type (Ogre/Thief): ";
            getline(cin, monsterType);

            if (monsterType == "Ogre" || monsterType == "ogre") {
                AdventureMode::Ogre ogre;
                cout << "Ogre attacking in Adventure mode" << endl;
                ogre.attack();
                //ogre.getStrength() = 200; // Error - Task 4
            } else if (monsterType == "Thief" || monsterType == "thief") {
                cout << "Thief attacking in Adventure mode" << endl;
            } else {
                cout << "Invalid Monster type" << endl;
            }
        } else {
            cout << "Invalid fighter category" << endl;
        }
    } else {
        cout << "Invalid mode" << endl;
    }

    // Task 1
    cout << "Total ArenaMode characters created: " << ArenaMode::Character::getObjectCount() << endl;
    cout << "Total AdventureMode characters created: " << AdventureMode::Character::getObjectCount() << endl;

    return 0;
}
