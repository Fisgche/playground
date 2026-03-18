#include <iostream>
#include <set>
#include <string>

bool isUnique(std::string text){
    bool chars[256] = {false};

    for(char c : text){
        if(chars[c]){
            return false;
        }
        chars[c] = true;
    }

    return true;
}

int main(){
    std::string text = "test";
    if(isUnique(text)){
        std::cout << "The string is unique";
    }
    else{
        std::cout << "The string is not unique";
    }
}