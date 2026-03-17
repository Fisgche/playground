#include "main.hpp"

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

int main(){

    Node* node1 = new Node(99,2);
    Node* node2 = new Node(25,66);
    Node* node3 = new Node(5,100);

    HashTable* hashTable = new HashTable();
    hashTable->Insert(node1);
    hashTable->Insert(node2);
    hashTable->Insert(node3);
    hashTable->Print();
    hashTable->Delete(node2);
    hashTable->Print();
    Node * node = hashTable->Get(99);
    std::cout << node->GetValue();

}