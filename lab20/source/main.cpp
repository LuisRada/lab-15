#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <ctime>
#include <cstdlib>

#include "../lib/UI.h"
#include "../lib/CharacterFactory.h"
#include "../lib/ActualFactory.h"
#include "../lib/Character.h"
#include "../lib/Berserker.h"
#include "../lib/Ogre.h"
#include "../lib/Simulation.h"



#include <type_traits>


int main() {


/*
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    CharacterFactory* factory = new ActualFactory();

    std::vector<int> heroStats = {90, 8, 6, 5, 4, 3, 2, 1, 10};
    std::vector<int> ogreStats = {120, 9, 3, 6, 2, 1, 4, 2, 15};

    Character* hero = factory->createHero("Mage", "Gandalf", heroStats);
    Character* monster = factory->createMonster("Ogre", "Gorgoth", ogreStats);

    if (!hero || !monster) {
        std::cout << "Failed to create either hero or monster via factory.\n";
        delete factory;
        return 1;
    }

    UI ui;
    hero->addObserver(&ui);
    monster->addObserver(&ui);

    hero->attack();
    monster->attack();

    hero->takeDamage(12);
    monster->takeDamage(20);

    int coin = std::rand() % 2;
    Character* winner = (coin == 0 ? hero : monster);

    std::cout << "\n=== Battle Over! ===\n";
    std::cout << "Winner is: " << winner->getName() << "\n";
    std::cout << "Full stats of " << winner->getName() << ":\n";

    std::vector<int> wstats = winner->getStats();
    std::cout << "[ ";
    for (size_t i = 0; i < wstats.size(); ++i) {
        std::cout << wstats[i] << (i + 1 < wstats.size() ? ", " : " ");
    }
    std::cout << "]\n";

    delete hero;
    delete monster;

  */ 

    Character* hero = new Hero();
    Character* monster = new Monster();
    

    Simulation* simulation = new Simulation();

    std::future<void> f1 = std:: async(std::launch::async, &Simulation::runPerformTask, simulation, hero);
    std::future<void> f2 = std:: async(std::launch::async, &Simulation::runPerformTask, simulation, monster);



    return 0;
}   

