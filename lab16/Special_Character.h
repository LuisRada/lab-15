#pragma once
#include <iostream>
#include <string>
using namespace std;

class Special_Character {
    string name;
    int health;
public:
    Special_Character(string n, int h);
    void display() const;
    void increaseHealth(int value);
    int getHealth() const;
};

