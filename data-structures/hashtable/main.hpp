#pragma once
#include <list>
#include <vector>
#include <iostream>
#define CAPACITY 20

class Node{
    public:
        Node();
        Node(int key, int value);
        int GetKey();
        int GetValue();
    private:
        int key;
        int value;
};


class HashTable{
    public:
        HashTable();
        bool Insert(Node* node);
        bool Delete(Node* Node);
        Node* Get(int key);
        void Print();
    private:
        std::vector<std::list<Node>> hashTable;
        int Hash(int key);
        int size;
        int capacity;
};