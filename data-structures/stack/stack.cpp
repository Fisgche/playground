#include "stack.hpp"
#include "../../log/log.hpp"
#include <iostream>

void Stack::Push(type_value x){
    NodeStack* node = new NodeStack(x, this->Top);
    this->Top= node;
}

type_value Stack::GetTop(){
    if(this->Top == nullptr){
        Log::Print("Stack is empty");
        return -1;
    }
    return this->Top->GetValue();
}

type_value Stack::Pop(){
    type_value value;
    if(this->Top == nullptr){
        Log::Print("Stack is empty");
        return -1;   
    }
    value = this->Top->GetValue();
    NodeStack* node = this->Top;
    this->Top = this->Top->GetNext();
    free(node);
    return value;
}

type_value Stack::Get(type_value x){
    NodeStack* auxTop = this->Top;
    while(auxTop != nullptr){
        if(auxTop->GetValue() == x){
            return auxTop->GetValue();
        }
        auxTop = auxTop->GetNext();
    }
    Log::Print("Value not found");
    return -1;
}

void Stack::Print(){
    NodeStack* auxTop = this->Top;
    while(auxTop != nullptr){
        std::cout << " [" << auxTop->GetValue() << "] ";
        auxTop = auxTop->GetNext();
    }
    std::cout << std::endl;
}