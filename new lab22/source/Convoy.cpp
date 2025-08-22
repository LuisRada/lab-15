#include "Convoy.h"

Convoy::Convoy(const std::string& name, const std::vector<int>& stats)
    : Character(name, stats[0], stats[1], stats[2], stats[3]), mana(stats[4]) {
    inventory = { "Staff", "Robe", "Spellbook" };
void Convoy::moves() const {}

void Convoy::add() const {}