#pragma once
#include "node-stack.hpp"

class Stack{
public:
    void Push(type_value x);
    type_value Pop();
    type_value Get(type_value x);
    void Print();

private:
    NodeStack* Top;

};