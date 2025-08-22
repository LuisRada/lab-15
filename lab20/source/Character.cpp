#include "Character.h"

Character::Character(const std::string& in_name, const std::vector<int>& in_stats)
    : name(in_name), stats(in_stats) {}

std::string Character::getName() const {
    return name;
}

void Character::attack() {

    std::string msg = name + " attacks with power " + std::to_string(getPowerLevel());
    notifyObservers(msg);
}

void Character::takeDamage(int dmg) {
    stats[0] -= dmg;
    if (stats[0] < 0) stats[0] = 0;
    std::string msg = name + " takes " + std::to_string(dmg) +
                      " damage, health now " + std::to_string(stats[0]);
    notifyObservers(msg);
}

std::vector<int> Character::getStats() const {
    return stats;
}

void Character::addObserver(Observer* o) {
    observers.push_back(o);
}

void Character::removeObserver(Observer* o) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            break;
        }
    }
}

void Character::notifyObservers(const std::string& message) {
    for (Observer* o : observers) {
        o->update(message);
    }
}

void Character::display() const {
  
    std::cout << "=== " << name << " ===\n";
    std::cout << "Health:      " << stats[0] << "\n";
    std::cout << "Strength:    " << stats[1] << "\n";
    std::cout << "Dexterity:   " << stats[2] << "\n";
    std::cout << "Endurance:   " << stats[3] << "\n";
    std::cout << "Intelligence:" << stats[4] << "\n";
    std::cout << "Charisma:    " << stats[5] << "\n";
  
}

void Character::logStatus() {}

Character::~Character() {}