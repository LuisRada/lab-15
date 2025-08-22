#pragma once
#include <iostream>
using namespace std;

template <class T>
class FieldModifier {
public:
    void increaseHealth(T* obj, int amount) {
        obj->increaseHealth(amount);
    }

    void printStats(T* obj) {
        obj->displayStats();
    }
};
