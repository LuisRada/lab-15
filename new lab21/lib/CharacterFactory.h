#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Character.h"

class CharacterFactory {
public:
    virtual std::unique_ptr<Character> create(const std::string& name, const std::vector<int>& stats) const = 0;
    virtual ~CharacterFactory() = default;
};