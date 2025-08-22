#pragma once
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Character.h"
#include "Mage.h"
#include "Warrior.h"
#include "Ogre.h"
#include <vector>
#include <string>

class Simulation {
public:
    
void runPerformTask(Character* character)
{
    character ->performTask();
}

};

#endif
