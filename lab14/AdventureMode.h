#ifndef ADVENTUREMODE_H
#define ADVENTUREMODE_H

#include <string>
#include <iostream>

namespace AdventureMode {

    class Character {
    protected:
        std::string name;
    public:
        static int objectCount;

        Character() = default;
        virtual ~Character() = default;
        virtual void attack() = 0;

        static int getObjectCount();
    };

    class Mage : public Character {
        int mana;
    public:
        Mage();
        void attack() override;
        static int getDefaultMana();
    };

    class Warrior : public Character {
    public:
        Warrior();
        void attack() override;
        void shout(const std::string& phrase);
    };

    class Ogre : public Character {
        int strength;
    public:
        explicit Ogre(int str = 80);
        void attack() override;
        int getStrength() const;
    };

}

#endif
