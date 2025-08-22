#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
#include <future>
#include "../lib/AutoFactory.h"
#include "../lib/Character.h"
#include "../lib/Mage.h"
#include "../lib/Warrior.h"
#include "../lib/Ogre.h"
#include "../lib/Thief.h"
#include "../lib/Simulation.h"
#include <type_traits>

int getValidatedChoice(int min, int max) {
    std::string input;
    int choice;
    while (true) {
        std::getline(std::cin, input);
        try {
            choice = std::stoi(input);
            if (choice >= min && choice <= max) {
                return choice;
            } else {
                std::cout << "Invalid answer, try again: ";
            }
        } catch (...) {
            std::cout << "Invalid answer, try again: ";
        }
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<std::unique_ptr<Character>> characters;
    characters.push_back(std::make_unique<Mage>("Gandalf", std::vector<int>{80, 10, 30, 20, 100}));
    characters.push_back(std::make_unique<Warrior>("Aragorn", std::vector<int>{120, 30, 5, 10, 50}));
    characters.push_back(std::make_unique<Ogre>("Gorg", std::vector<int>{150, 40, 3, 5, 80}));
    characters.push_back(std::make_unique<Thief>("Locke", std::vector<int>{70, 20, 15, 30, 60}));

    while (true) {
        std::cout << "Welcome to the game\n";
        std::cout << "What would you like to do?\n";
        std::cout << "1 See list of characters\n";
        std::cout << "2 Check inventory of a character\n";
        std::cout << "3 Fight\n";
        std::cout << "4 Exit\n";
        std::cout << "Enter choice: ";
        int choice = getValidatedChoice(1, 4);
        if (choice == 1) {
            std::cout << "List of characters:\n";
            for (size_t i = 0; i < characters.size(); ++i) {
                std::cout << i + 1 << ". " << characters[i]->getType() << " " << characters[i]->getName() << "\n";
            }
        } else if (choice == 2) {
            std::cout << "Select a character to view inventory:\n";
            for (size_t i = 0; i < characters.size(); ++i) {
                std::cout << i + 1 << ". " << characters[i]->getType() << " " << characters[i]->getName() << "\n";
            }
            std::cout << "Enter choice: ";
            int idx = getValidatedChoice(1, characters.size()) - 1;
            characters[idx]->showInventory();
        } else if (choice == 3) {
            std::cout << "Select first fighter:\n";
            for (size_t i = 0; i < characters.size(); ++i) {
                std::cout << i + 1 << ". " << characters[i]->getType() << " " << characters[i]->getName() << "\n";
            }
            std::cout << "Enter choice: ";
            int idx1 = getValidatedChoice(1, characters.size()) - 1;
            std::cout << "Select second fighter:\n";
            for (size_t i = 0; i < characters.size(); ++i) {
                std::cout << i + 1 << ". " << characters[i]->getType() << " " << characters[i]->getName() << "\n";
            }
            std::cout << "Enter choice: ";
            int idx2;
            while (true) {
                idx2 = getValidatedChoice(1, characters.size()) - 1;
                if (idx2 != idx1) break;
                std::cout << "Invalid answer, try again: ";
            }
            Character* fighter1 = characters[idx1].get();
            Character* fighter2 = characters[idx2].get();
            fighter1->battleCry();
            fighter2->battleCry();
            fighter1->attack();
            fighter2->attack();
            int winner = std::rand() % 2;
            Character* victor = (winner == 0) ? fighter1 : fighter2;
            std::cout << victor->getType() << " " << victor->getName() << " won the battle\n";
            victor->printStats();

        } else if (choice == 4) {
            break;
        }
            
            Simulation*simulation = new Simulation();
            std::future<void> f1 = std::async(std::launch::async, &Simulation::runPerformTask, &simulation, fighter1);
            std::future<void> f2 = std::async(std::launch::async, &Simulation::runPerformTask, &simulation, fighter2);
            f1.get();
            f2.get();
        

            std::vector<Character*> characters = { new fighter1(), new fighter2() };
            std::vector<std::future<std::string>>futures;

            for (Character* character : characters)
            {
                futures.push_back(std::async(std::launch::async, &Simulation::runComputeResult, simulation, character));

            }

            for (auto& f : futures)
            {
                std::cout << f.get() << std::endl:

            }

            for (Character* character : characters)
            {
                delete character;
            }
    }

    return 0;
}
