#include "linked-list.hpp"
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
    this->size++;
}

void List::Print(){
    Node* aux = this->firstNode;
    int count = 0;
    while(aux != nullptr){
        std::cout << aux->value << " | ";
        aux = aux->next;
        count++;
    }
    std::cout << std::endl;
}

bool List::CheckIndex(int index){
    if(index > this->size || index < 0){
        std::cout << "This node doesn't exist" << std::endl;
        return false;
    }

    return true;
}

bool List::Remove(int index){
    Node * nodeRemoved; 
    Node * before;
    
    if(!CheckIndex(index)){
        return false;
    }    

    if(index == 0){
        nodeRemoved = this->firstNode;
        this->firstNode = this->firstNode->next;
    }
    else{
        nodeRemoved = List::Get(index);
        before = List::Get(index - 1);
        before->next = nodeRemoved->next;
    }

    this->size--;
    
    return true;
}

bool List::Insert(int index, Node* nodeInsert){
    Node * node; 
    
    if(!CheckIndex(index)){
        return false;
    }    

    if(index == 0){
        nodeInsert->next = this->firstNode;
        this->firstNode = nodeInsert;
    }
    else{
        node = List::Get(index);
        nodeInsert->next = node->next;
        node->next = nodeInsert;
    }

    this->size++;
    
    return true;
}

Node* List::Get(int index){
    
    if(!List::CheckIndex(index)){
        return nullptr;
    }

    Node* aux = this->firstNode;
    int count = 0;
    while(count != index){
        aux = aux->next;
        count++;
    }

    return aux;
}

void List::Print(int index){

    Node* node = List::Get(index);

    if(node == nullptr){
        return;
    }

    std::cout << node->value << std::endl;
}

