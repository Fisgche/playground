#pragma once
#define type_value int
class NodeStack{
public:
    NodeStack() {
        this->Value = 0;
        this->Next = nullptr;
    }
    NodeStack(type_value x, NodeStack* top) {
        this->Value = x;
        this->Next = top;
    }
    type_value GetValue(){
        return this->Value;
    }
    NodeStack* GetNext(){
        return this->Next;
    }


private :
    type_value Value;
    NodeStack* Next;
    
};