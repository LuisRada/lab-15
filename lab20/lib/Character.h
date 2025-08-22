#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Subject.h"
#include "Observer.h"



class Character {

public:
    virtual void performTask() = 0;
    
    
    Character(const std::string& in_name, const std::vector<int>& in_stats);
    virtual std::string getName() const;
    virtual void attack();
    virtual void takeDamage(int dmg);
    virtual int getPowerLevel() const = 0;
    virtual void describe() const = 0;
    virtual std::vector<int> getStats() const;

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers(const std::string& message) override;
    virtual void display() const;

    virtual void logStatus() = 0;

    
    virtual ~Character();
};

#endif
