#pragma once
#include "CharacterFactory.h"

template <typename T>
class AutoFactory : public CharacterFactory {
public:
    std::unique_ptr<Character> create(const std::string& name, const std::vector<int>& stats) const override {
        return std::make_unique<T>(name, stats);
    }
};