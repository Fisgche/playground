#include "hashtable.hpp"

Node::Node(){
    this->key = 0;
    this->value = 0;
}
int Node::GetKey(){
    return this->key;
}
int Node::GetValue(){
    return this->value;
}

Node::Node(int key, int value){
    this->key = key;
    this->value =  value;
}

HashTable::HashTable(){
    this->hashTable.resize(CAPACITY);
    this->capacity = CAPACITY;
    this->size = 0;
}

int HashTable::Hash(int key){
    return key % this->capacity;
}

bool HashTable::Insert(Node* node){
    int index = this->Hash(node->GetKey());
    this->hashTable[index].push_front(*node);
    this->size++;
    return true;
}

bool HashTable::Delete(Node* node){
    int index = this->Hash(node->GetKey());

    for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
        if (it->GetKey() == node->GetKey()) {
            hashTable[index].erase(it);
            this->size--;
            return true;
        }
    }

    return false;
}

Node* HashTable::Get(int key){
    int index = this->Hash(key);
    for (Node& node : hashTable[index]) {
        if (node.GetKey() == key) {
            return &node;
        }
    }

    return nullptr;
}

void HashTable::Print(){
    for(int i = 0; i < this->hashTable.size(); i++){
        std::cout << "Bucket " << i << ": ";
        for (Node& node : hashTable[i]) {
            std::cout << node.GetValue() << " | ";
        }
        std::cout << std::endl;
    }
}
