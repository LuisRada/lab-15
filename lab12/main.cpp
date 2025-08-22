#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
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

// Here I made the classes that later are gonna be used on the 'compare' mode, with the different operators

Character* makeSample(const string& type) {
    if (type == "Mage")
        return new Mage("Gandalf", {100,10,5,5,5,5,5,5,10});
    if (type == "Warrior")
        return new Warrior("Aragorn", {100,12,7,6,4,3,3,3,8});
    if (type == "Berserker")
        return new Berserker("Conan", {100,15,6,6,5,2,2,2,12});
    if (type == "Thief")
        return new Thief("Locke", {100,8,10,4,6,7,4,4,9});
    if (type == "Ogre")
        return new Ogre("Shrek", {100,20,4,12,3,2,6,6,3});
    return nullptr;
}

int main() {
    srand((unsigned)time(0));
    cout << "Enter mode (fight/compare): ";
    string mode; cin >> mode;

    if (mode == "fight") {
        string choice, name;
        int str, dex, end, intl, cha, respect, armor, extra;
        cout << "Choose your Hero (Mage, Warrior, Berserker): "; cin >> choice;
        cout << "Enter hero name: "; cin >> name;
        cout << "Enter strength: "; cin >> str;
        cout << "Enter dexterity: "; cin >> dex;
        cout << "Enter endurance: "; cin >> end;
        cout << "Enter intelligence: "; cin >> intl;
        cout << "Enter charisma: "; cin >> cha;
        cout << "Enter respect: "; cin >> respect;
        cout << "Enter sacred armor: "; cin >> armor;
        Hero* hero = nullptr;
        vector<int> statsH = {100, str, dex, end, intl, cha, respect, armor, 0};
        if (choice == "Mage") {
            cout << "Enter mana: "; cin >> extra;
            statsH[8] = extra;
            hero = new Mage(name, statsH);
        }
        else if (choice == "Warrior") {
            cout << "Enter stamina: "; cin >> extra;
            statsH[8] = extra;
            hero = new Warrior(name, statsH);
        }
        else if (choice == "Berserker") {
            cout << "Enter rage: "; cin >> extra;
            statsH[8] = extra;
            hero = new Berserker(name, statsH);
        }
        if (!hero) return 1;

        cout << "Choose your Monster (Thief, Ogre): "; cin >> choice;
        cout << "Enter monster name: "; cin >> name;
        cout << "Enter strength: "; cin >> str;
        cout << "Enter dexterity: "; cin >> dex;
        cout << "Enter endurance: "; cin >> end;
        cout << "Enter intelligence: "; cin >> intl;
        cout << "Enter charisma: "; cin >> cha;
        cout << "Enter evilness: "; cin >> respect;
        cout << "Enter evil armor: "; cin >> armor;
        Monster* monster = nullptr;
        vector<int> statsM = {100, str, dex, end, intl, cha, respect, armor, 0};
        if (choice == "Thief") {
            cout << "Enter stealth: "; cin >> extra;
            statsM[8] = extra;
            monster = new Thief(name, statsM);
        }
        else if (choice == "Ogre") {
            cout << "Enter brute force: "; cin >> extra;
            statsM[8] = extra;
            monster = new Ogre(name, statsM);
        }
        if (!monster) { delete hero; return 1; }

        cout << "\nBattle begins between " << hero->getName()
             << " and " << monster->getName() << "!\n";

        battlescream trigger;
        trigger.heroscreams(hero);

        bool heroWins = (rand() % 2 == 0);
        if (heroWins) cout << hero->getName() << " wins the fight!\n";
        else          cout << monster->getName() << " wins the fight!\n";

        if (heroWins) {
            if (Mage* m = dynamic_cast<Mage*>(hero)) {
                FieldModifier<Mage> fm; fm.increaseHealth(m, 30);
            }
            FieldModifier<Hero> fh; fh.printStats(hero);
        } else {
            FieldModifier<Monster> fm; fm.printStats(monster);
        }

         Special_Character* special = new Special_Character("Mystery", 80);
        FieldModifier<Special_Character> fs;
        fs.increaseHealth(special, 20);
        fs.printStats(special);
    }
    
    else if (mode == "compare") {
        cout << "Choose operator (+, ==, &&): ";
        string op; cin >> op;
        cout << "Available types: Mage, Warrior, Berserker, Thief, Ogre\n";
        cout << "First character type: "; string a; cin >> a;
        cout << "Second character type: "; string b; cin >> b;

        Character* A = makeSample(a);
        Character* B = makeSample(b);

        if (op == "+") {
            vector<int> statsA = A->getStats();
            vector<int> statsB = B->getStats();
            vector<int> combined(9);
            for (int i = 0; i < 9; ++i) {
                combined[i] = statsA[i] + statsB[i];
            }
            cout << "Enter name for new character: ";
            string newName; cin >> newName;
            cout << "\nName: " << newName
                 << "\nStrength: " << combined[1]
                 << "\nDexterity: " << combined[2]
                 << "\nEndurance: " << combined[3]
                 << "\nIntelligence: " << combined[4]
                 << "\nCharisma: " << combined[5]
                 << "\nRespect: " << combined[6]
                 << "\nSacred Armor: " << combined[7]
                 << "\nMana: " << combined[8]
                 << endl;
        }
        else if (op == "==") {
            bool equal = (*A == *B);
            if (!equal) {
                cout << "false\n";
            }
            else {
                vector<int> statsA = A->getStats();
                vector<int> statsB = B->getStats();
                static const char* names[9] = {
                    "Health", "Strength", "Dexterity", "Endurance",
                    "Intelligence", "Charisma", "Respect", "Sacred Armor", "Mana"
                };
                for (int i = 0; i < 9; ++i) {
                    if (statsA[i] == statsB[i]) {
                        cout << "true, value of " << names[i] << " = " << statsA[i] << " is the same for both\n";
                        break;
                    }
                }
            }
        }
        else if (op == "&&") {
            bool both = (*A && *B);
            if (!both) {
                cout << "false\n";
            } else {
                vector<int> statsA = A->getStats();
                vector<int> statsB = B->getStats();
                static const char* names[9] = {
                    "Health", "Strength", "Dexterity", "Endurance",
                    "Intelligence", "Charisma", "Respect", "Sacred Armor", "Mana"
                };
                bool firstPrinted = false;
                cout << "true, properties > 8 for both: ";
                for (int i = 0; i < 9; ++i) {
                    if (statsA[i] > 8 && statsB[i] > 8) {
                        if (firstPrinted) cout << ", ";
                        cout << names[i];
                        firstPrinted = true;
                    }
                }
                cout << "\n";
            }
        }

    }

    return 0;
}
