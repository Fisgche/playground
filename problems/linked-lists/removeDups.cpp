#include <list>
#include <iostream>

void Print(std::list<int>* list){
    std::list<int>::iterator it;
    for(it = list->begin(); it != list->end(); it++){
        std::cout << *it << " | ";
    }

    std::cout << std::endl;
}

void RemoveDups(std::list<int>* list){
    if(list->empty()) return;

    list->sort();

    auto it = list->begin();
    int lastElement = *it;
    it++;

    while(it != list->end()){
        if(*it == lastElement){
            it = list->erase(it);
        }
        else{
            lastElement = *it;
            it++;
        }
    }
}



int main(){
    std::list<int> list = {1, 0, 5, 1};
    RemoveDups(&list);
    Print(&list);
}