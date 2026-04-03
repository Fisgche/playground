#include "../../data-structures/stack/stack.hpp"
#include <iostream>


class SetStack : public Stack{

    public:
        void PushStackSet(type_value x);
        type_value PopStackSet();
        type_value PopAt(int index);
        void Print();
        SetStack();
    private:
        void Resize();
        Stack ** Set;
        int Capacity;
        int Count;
        int Threshold;
};

SetStack::SetStack(){
    Capacity = 2;
    Count = 0;
    Threshold = 5;

    Set = new Stack*[Capacity];
    Set[Count] = new Stack();
    Count++;
}

void SetStack::Resize() {
    Capacity *= 2;

    Stack** newSet = new Stack*[Capacity];

    for (int i = 0; i < Count; i++) {
        newSet[i] = Set[i];
    }

    delete[] Set;
    Set = newSet;
}

void SetStack::PushStackSet(type_value x){
    if(Set[Count - 1]->Size() >= Threshold){
        if(Count >= Capacity){
            Resize();
        }
        Set[Count] = new Stack();
        Count++;  
    }
    Set[Count - 1]->Push(x);
}

type_value SetStack::PopStackSet(){

    if (Count == 0) {
        return -1; 
    }

    type_value value = Set[Count - 1]->Pop();

    if (Set[Count - 1]->Size() == 0) {
        if (Count > 1) {
            delete Set[Count - 1]; 
            Count--;
        }
    }

    return value;
}


type_value SetStack::PopAt(int index) {

    if (index < 0 || index >= Count) {
        return -1;
    }

    type_value value = Set[index]->Pop();

    if (Set[index]->Size() == 0 && index == Count - 1 && Count > 1) {
        delete Set[index];
        Count--;
    }

    return value;
}

void SetStack::Print() {

    if (Count == 0) {
        std::cout << "SetStack is empty\n";
        return;
    }

    for (int i = 0; i < Count; i++) {
        std::cout << "Stack " << i << ": ";
        Set[i]->Print();
    }
}

int main(){
    SetStack * set = new SetStack();
    set->PushStackSet(5);
    set->PushStackSet(4);
    set->PushStackSet(3);
    set->PushStackSet(2);
    set->PushStackSet(1);
    set->PushStackSet(1);
    set->PushStackSet(1);
    set->Print();
    set->PopStackSet();
    set->PopStackSet();
    set->Print();
    
}