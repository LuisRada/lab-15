#ifndef ARENAMODE_H
#define ARENAMODE_H

#include <string>
#include <iostream>

namespace ArenaMode {

    class Character {
    protected:
        std::string name;
    public:
        static int objectCount;

        Character() = default;
        virtual ~Character() = default;
        virtual void attack() = 0;

        // Task 1
        static int getObjectCount();
    };

    class Mage : public Character {
        int mana;
    public:

        Mage();

        void attack() override;

        // Task 2
        static int getDefaultMana();
    };

    class Warrior : public Character {
    public:
        Warrior();

        void attack() override;

        // Task 3
        void shout(const std::string& phrase);
    };

    class Ogre : public Character {
        int strength;
    public:
    
        explicit Ogre(int str = 100);

        void attack() override;

        // Task 4
        int getStrength() const;
    };

} 

#endif 
