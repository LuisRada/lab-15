#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "GameEngine.h"
#include "ArenaMode.h"
#include "AdventureMode.h"
using namespace std;

int main() {
    srand((unsigned)time(0));

    //Task 1 and Task 2

    GameEngine::Example* example = new GameEngine::Example();
    example->doSth();
    delete example;

    string mode;
    cout << "Choose the Mode (Arena/Adventure): ";
    cin >> mode;

    string category;
    cout << "Choose your fighter category (Hero/Monster): ";
    cin >> category;

    string type;
    if (category == "Hero") {
        cout << "Choose Hero type (Mage/Warrior): ";
        cin >> type;
    } else if (category == "Monster") {
        cout << "Choose Monster type (Ogre/Thief): ";
        cin >> type;
    } else {
        cout << "Invalid category." << endl;
        return 1;
    }

    if (mode == "Arena") {
        ArenaMode::Character* fighter = nullptr;
        if (type == "Mage" || type == "Warrior") {
            fighter = new ArenaMode::Warrior();
        } else if (type == "Ogre" || type == "Thief") {
            fighter = new ArenaMode::Warrior();
        } else {
            cout << "Invalid type." << endl;
            return 1;
        }
        cout << type << " attacking in Arena mode" << endl;
        delete fighter;
    } else if (mode == "Adventure") {
        AdventureMode::Character* fighter = nullptr;
        if (type == "Mage" || type == "Warrior") {
            fighter = new AdventureMode::Warrior();
        } else if (type == "Ogre" || type == "Thief") {
            fighter = new AdventureMode::Warrior();
        } else {
            cout << "Invalid type." << endl;
            return 1;
        }
        cout << type << " attacking in Adventure mode" << endl;
        delete fighter;
    } else {
        cout << "Invalid mode." << endl;
        return 1;
    }

    return 0;
}
