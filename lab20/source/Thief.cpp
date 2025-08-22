#include "../lib/Thief.h"
using namespace std;

Thief::Thief(const string& name, const vector<int>& stats)
    : Monster(name, stats), stealth(stats[8]) {}

void Thief::taunt() const {
    cout << "Thief: You can't catch me!" << endl;
}

void Thief::display() const {
    Monster::display();
    cout << "Stealth: " << stealth << endl;
}

void Thief::describe() const {
    cout << "Thief: " << getName() << ", Stealth: " << stealth << endl;
}

int Thief::getPowerLevel() const {
    const vector<int>& stats = getStats(); 
    return stats[1] + stats[2] + stats[3] + stats[4] + stats[5] + stats[6] + stats[7] + stealth;
}

vector<int> Thief::getStats() const {
    vector<int> baseStats = Monster::getStats();
    baseStats.push_back(stealth); 
    return baseStats;
}

Thief::~Thief() {
    cout << "Thief destructor called" << endl;
}