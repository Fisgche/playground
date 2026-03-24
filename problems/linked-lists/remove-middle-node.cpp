#include <forward_list>
#include <iostream>
#include "../../data-structures/linked-list/main.hpp"

void RemoveMiddleNode(Node* node){
    Node* aux = node->next;
    node->value = aux->value;
    node->next = aux->next;
    aux->next = nullptr;
}

int main(){
    List * linkedList = new List();

    Node node1(5);
    Node node2(9);
    Node node3(8);
    Node node4(10);

    linkedList->Add(&node1);
    linkedList->Add(&node2);
    linkedList->Add(&node3);
    linkedList->Add(&node4);

    linkedList->Print();

    RemoveMiddleNode(&node2);

    linkedList->Print();
}