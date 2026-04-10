#include "binary-search-tree.hpp"
#include <iostream>

Node::Node(tpye_value x){
    this->Right = nullptr;
    this->Left = nullptr;
    this->Value = x;
}

Tree::Tree(tpye_value x){
    Node * node = new Node(x);
    this->Root = node;
}

void Tree::Insert(tpye_value x){

     Node* node = new Node(x);

    if(this->Root == nullptr){
        this->Root = node;
        return;
    }

    Node* aux = this->Root;
    Node* parent = nullptr;

    while(aux != nullptr){
        parent = aux;

        if(x <= aux->Value){
            aux = aux->Left;
        } else {
            aux = aux->Right;
        }
    }

    if(x <= parent->Value){
        parent->Left = node;
    } else {
        parent->Right = node;
    } 
}

void Tree::PrintInOrder(Node* node){
    if(node == nullptr) return;

    PrintInOrder(node->Left);
    std::cout << node->Value << " ";
    PrintInOrder(node->Right);
}

void Tree::Print(){
    PrintInOrder(this->Root);
    std::cout << std::endl;
}