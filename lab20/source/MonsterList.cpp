#include "MonsterList.h"

Monster::Monster(const std::string& name, const std::vector<int>& stats)
    : Character(name, stats) {}

void Monster::display() const {
    Character::display();
    std::cout << "Evilness:   " << stats[RESPECT] << "\n";
    std::cout << "Evil Armor: " << stats[SACRED_ARMOR] << std::endl;
}

int Monster::getPowerLevel() const {
    return stats[STRENGTH] + stats[DEXTERITY] + stats[ENDURANCE] + stats[INTELLIGENCE] + stats[CHARISMA] + stats[RESPECT] + stats[SACRED_ARMOR];
}

std::vector<int> Monster::getStats() const {
    return stats;
}

Monster::~Monster() {}