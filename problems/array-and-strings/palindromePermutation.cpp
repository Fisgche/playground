#include <string>
#include <iostream>

bool CheckPalindromePermutaation(std::string str){
    int countChars = 0;
    int chars [128] = {0};

    for(int i = 0; i < str.size(); i++){
        if((str[i]<65 || str[i]>90) && (str[i]<97 || str[i]>122)){
            continue;
        }

        str[i] = std::tolower(str[i]); 
        chars[str[i]]++;
        countChars++;
    }

    int countOdd = 0;

    for(int i = 0; i < 128; i++){
        if(chars[i] % 2 != 0){
            countOdd++;
            if(countOdd > 1){
                return false;
            }
        }
    }

    return true;
}

int main(){

    std::string str = "Test";
    
    if(CheckPalindromePermutaation(str)){
        std::cout << "Is a Palindrome Permutation" << std::endl;
    }
    else{
        std::cout << "Is not a Palindrome Permutation" << std::endl;
    }


}