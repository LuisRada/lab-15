#include "../lib/Berserker.h"
using namespace std;

Berserker::Berserker(const string& name, const vector<int>& stats)
    : Hero(name, stats) {}

void Berserker::battleCry() const {
    cout << "Berserker: For Glory!" << endl;
}


void Berserker::display() const {
    Hero::display();
}

void Berserker::describe() const {
    cout << "Berserker: " << getName() << ", Rage: " << stats[8] << endl;
}

int Berserker::getPowerLevel() const {
    return stats[1] + stats[2] + stats[3] + stats[4] + stats[5] + stats[7] + stats[8];
}

vector<int> Berserker::getStats() const {
    return stats;
}

void Berserker::attack() {
    std::string msg = name + " Berserker is attacking " + std::to_string(getPowerLevel());
    notifyObservers(msg);
}

void Berserker::logStatus() {}

Berserker::~Berserker() {
    cout << "Berserker destructor called" << endl;
}
