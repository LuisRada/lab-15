#pragma once
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual void addobserver() const = 0;
    virtual ~Observer() = default;
};