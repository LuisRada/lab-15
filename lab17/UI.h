#pragma once
#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <string>

class UI : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "[UI] " << message << std::endl;
    }
};
