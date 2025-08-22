#pragma once
#include "Observer.h"
#include <iostream>
#include <string>


class Subject {
public:
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
    virtual ~Subject() = default;
};
