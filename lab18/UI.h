#ifndef UI_H
#define UI_H

#include "Observer.h"
#include <iostream>
#include <string>

class UI : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

#endif
