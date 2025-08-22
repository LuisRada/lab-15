#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace GameEngine {
    class Example {
    public:
        void doSth() {
            std::cout << "Printing message from class wrapped around namespace" << std::endl;
        }
    };

class Character {
protected:
    std::string name;
    int strength, dexterity, endurance, intelligence, charisma, health;
public:
    Character(const std::string& n, const std::vector<int>& stats);
    virtual void display() const;
    virtual ~Character();
};
class Hero : public Character {
protected:
    int respect, sacredArmor, mana;
public:
    Hero(const std::string& n, const std::vector<int>& stats);
    void display() const override;
    virtual ~Hero();
};
class Mage : public Hero {
public:
    Mage(const std::string& n, const std::vector<int>& stats);
    void display() const override;
    ~Mage() override;
};
class Warrior : public Hero {
public:
    Warrior(const std::string& n, const std::vector<int>& stats);
    void display() const override;
    ~Warrior() override;
};
class Monster : public Character {
protected:
    int evilness, evilArmor;
public:
    Monster(const std::string& n, const std::vector<int>& stats);
    void display() const override;
    virtual ~Monster();
};
class Thief : public Monster {
public:
    Thief(const std::string& n, const std::vector<int>& stats);
    void display() const override;
    ~Thief() override;
};
class Ogre : public Monster {
public:
    Ogre(const std::string& n, const std::vector<int>& stats);
    void display() const override;
    ~Ogre() override;
};
}
