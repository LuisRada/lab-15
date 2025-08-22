#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
protected:
    string name;
    int strength, dexterity, endurance, intelligence, charisma;
public:
    Character(string n, int str, int dex, int end, int intl, int cha)
        : name(n), strength(str), dexterity(dex), endurance(end), intelligence(intl), charisma(cha) {}
    virtual ~Character() {}
    string getName() const { return name; }
    virtual void display() = 0;
    virtual void increaseHealth(int value) = 0;
};

#endif



