#pragma once

#include "CharacterFactory.h"
#include <string>
#include <vector>
#include <type_traits>

template <class T>
class AutoFactory : public CharacterFactory {
public:
    ArenaMode::Character* createArenaCharacter(const std::string& type, const std::vector<int>& stats) override {
        if constexpr (std::is_base_of<ArenaMode::Character, T>::value) {
            if (type == T::Type()) {
                return new T(stats);
            }
        }
        return nullptr;
    }

    AdventureMode::Character* createAdventureCharacter(const std::string& type, const std::vector<int>& stats) override {
        if constexpr (std::is_base_of<AdventureMode::Character, T>::value) {
            if (type == T::Type()) {
                return new T(stats);
            }
        }
        return nullptr;
    }
};