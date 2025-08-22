#include <iostream>
#include <string>
#include <vector>
#include "ArenaMode.h"
#include "AdventureMode.h"
#include "CharacterFactory.h"
#include "ActualFactory.h"
#include "AutoFactory.h"
#include "UI.h"

using namespace std;

int main() {
    UI ui;

    CharacterFactory* factory = new ActualFactory();

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

            ArenaMode::Character* c = factory->createArenaCharacter(heroType, heroStats);
            if (c) {
                c->addObserver(&ui);
                c->attack();
                c->takeDamage(15);
                delete c;
            } else {
                cout << "Invalid Hero type" << endl;
            }

        } else if (category == "Monster" || category == "monster") {
            string monsterType;
            cout << "Choose Monster type (Mage/Warrior/Thief/Ogre): ";
            getline(cin, monsterType);

            ArenaMode::Character* c = factory->createArenaCharacter(monsterType, monsterStats);
            if (c) {
                c->addObserver(&ui);
                c->attack();
                c->takeDamage(18);
                delete c;
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

            AdventureMode::Character* c = factory->createAdventureCharacter(heroType, heroStats);
            if (c) {
                c->addObserver(&ui);
                c->attack();
                c->takeDamage(12);
                delete c;
            } else {
                cout << "Invalid Hero type" << endl;
            }

        } else if (category == "Monster" || category == "monster") {
            string monsterType;
            cout << "Choose Monster type (Mage/Warrior/Thief/Ogre): ";
            getline(cin, monsterType);

            AdventureMode::Character* c = factory->createAdventureCharacter(monsterType, monsterStats);
            if (c) {
                c->addObserver(&ui);
                c->attack();
                c->takeDamage(14);
                delete c;
            } else {
                cout << "Invalid Monster type" << endl;
            }

        } else {
            cout << "Invalid fighter category" << endl;
        }
    } else {
        cout << "Invalid mode" << endl;
    }

   
    AutoFactory<ArenaMode::Mage> arenaMageFactory;
    ArenaMode::Character* autoMage = arenaMageFactory.createArenaCharacter("Mage", heroStats);
    if (autoMage) {
        autoMage->addObserver(&ui);
        autoMage->attack();
        autoMage->takeDamage(10);
        delete autoMage;
    }

    AutoFactory<AdventureMode::Ogre> advOgreFactory;
    AdventureMode::Character* autoOgre = advOgreFactory.createAdventureCharacter("Ogre", monsterStats);
    if (autoOgre) {
        autoOgre->addObserver(&ui);
        autoOgre->attack();
        autoOgre->takeDamage(12);
        delete autoOgre;
    }

    delete factory;
    return 0;
}