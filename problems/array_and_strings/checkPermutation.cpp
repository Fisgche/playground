#include <iostream>
#include <string>

bool checkPermutation(std::string str1, std::string str2){
    int size1 = str1.size();
    int size2 = str2.size();
    if(size1 != size2){
        return false;
    }
    //ASCII Table
    int chars[256] = {0};

    for(int i = 0; i < size1; i++){
        chars[str1[i]]++;
    }

    for(int i = 0; i < size2; i++){
        chars[str2[i]]--;

        if(chars[str2[i]] < 0){
            return false;
        }
    }
    
    return true;
}



int main(){

    std::string str1 = "test";
    std::string str2 = "ttse";
    if(checkPermutation(str1, str2)){
        std::cout << "Is a permutation";
    }
    else{
        std::cout << "Is not a permutation";
    }

}