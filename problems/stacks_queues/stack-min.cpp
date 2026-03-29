#include "../../data-structures/stack/stack.hpp"
#include <iostream>

class StackMin:Stack
{
    public:
        void PushMin(type_value x);
        type_value PopMin();
        type_value GetMin();
        void Print();
    private:
        Stack* minStack;
};

type_value StackMin::GetMin(){
    if(this->minStack->GetTop() == -1){
        return -1;
    }

    return this->minStack->GetTop();
}

void StackMin::PushMin(type_value x){
    if(minStack->GetTop() == -1){
        minStack->Push(x);
    }
    else{
        if(minStack->GetTop() <= x){
            minStack->Push(x);
        }
    }
    Push(x);
}

type_value StackMin::PopMin(){
    if(minStack->GetTop() ==  -1){
        return -1;
    }
    type_value x = Pop();

    if(minStack->GetTop() == x){
        minStack->Pop();
    }

    return x;
    
}

void StackMin::Print(){
    std::cout << "Min value: " << GetMin() << std::endl;
    Print();
}



int main(){
    StackMin* stack = new StackMin();
    stack->PushMin(7);
    stack->PushMin(8);
    stack->Print();
}