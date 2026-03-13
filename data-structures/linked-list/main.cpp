#include "main.hpp"
#include <iostream>

Node::Node(type_value value){
    this->value = value;
    this->next = nullptr;
}


List::List(){
    this->firstNode = nullptr;
    this->size = 0;
}

void List::Add(Node* node){

    if(this->firstNode == nullptr){
        this->firstNode = node;
        return;
    }

    Node* aux = this->firstNode;
    while(aux->next != nullptr){
        aux = aux->next;
    }

    aux->next = node;
}

void List::Print(){
    Node* aux = this->firstNode;
    while(aux != nullptr){
        std::cout << aux->value << std::endl;
        aux = aux->next;
    }
}



int main(){
    List* list = new List();
    Node node1(1);
    Node node2(2);
    Node node3(3);
    list->Add(&node1);
    list->Add(&node2);
    list->Add(&node3);

    list->Print();
}