#pragma once
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Character.h"
#include "Mage.h"
#include "Warrior.h"
#include "Berserker.h"
#include "Ogre.h"
#include <vector>
#include <string>

class Simulation {
public:
    static void SimulateMage() {
        std::vector<int> stats = {1, 7, 1, 8, 3, 0, 0, 0, 0};
        Character* mage = new Mage("jj", stats);
        mage->attack();
        delete mage;
    }

    static void SimulateWarrior() {
        std::vector<int> stats = {4, 6, 1, 8, 9, 0, 0, 0, 0};
        Character* warrior = new Warrior("niko", stats);
        warrior->attack();
        delete warrior;
    }

    void runObjectWithStatus(Character* obj)
    {
        obj ->attack();
        obj->logStatus();
        delete obj;

    }

};

#endif
