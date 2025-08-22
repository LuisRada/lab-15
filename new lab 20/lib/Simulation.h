#pragma once
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Character.h"

class Simulation {
public:
    void runPerformTask(Character* character) {
        character->performTask();
    }

    std:: string runComputeResult(Character* character){
        return character -> computeResult();
    }
};

#endif
