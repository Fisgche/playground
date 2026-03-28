//Problem: Describe how you could use a sigle array to implement three stacks.

//[][] [][] [][]
//Tem que definir o inicio de cada pilha e o tamanho de cada uma
//Ao inserir um elemento ele sera incluido na ultima posicao preenchida do vetor pois nesse caso a complexidade de tempo é de o(1)
//Será definido um contador para simbolizar onde esta definido o inicio da stack
#include <iostream>
#define SIZE_ARRAY 12


class ThreeStack{

    public:
        void Push(int x, int list);
        int Pop(int list);
        int Get(int x, int  list);
        ThreeStack(int size);
        void Print();
    private:
        int sizeStack; 
        int count1;
        int count2;
        int count3;
        int array[SIZE_ARRAY] = {0};
};

ThreeStack::ThreeStack(int size){
    this->sizeStack = size;
    this->count1 = 0;  
    this->count2 = count1 + size;
    this->count3 = count2 + size;
}

void ThreeStack::Push(int x, int stack){
    int * count;
    if(stack == 1){
        count = &count1;
    }
    else if(stack == 2){
        count = &count2;
    }
    else if (stack == 3)
    {
        count = &count3;
    }
    else{
        std::cout << "Invalid stack" << std::endl;
        return;
    }
    

    if(*count >= (this->sizeStack * stack)){
        std::cout << "Stack "  << stack << " full" << std::endl;
        return;
    }

    this->array[*count] = x;
    *count = *count + 1;
}

int ThreeStack::Pop(int stack){
    int * count;
    int value;
    if(stack == 1){
        count = &count1;
    }
    else if(stack == 2){
        count = &count2;
    }
    else if (stack == 3)
    {
        count = &count3;
    }
    else{
        std::cout << "Invalid stack" << std::endl;
        return 0;
    }

    if(*count == (this->sizeStack * (stack - 1))){
        std::cout << "Stack " << stack << " empty" << std::endl;
        return 0;
    }
    value = this->array[*count - 1];
    this->array[*count - 1] = 0;
    *count = *count - 1;
    return value;
}



int ThreeStack::Get(int x, int stack){
    int * count;
    int value;
    if(stack == 1){
        count = &count1;
    }
    else if(stack == 2){
        count = &count2;
    }
    else if (stack == 3)
    {
        count = &count3;
    }

    for(int i = *count - 1 ; i> (this->sizeStack * (stack - 1)); i--){
        
        if(this->array[i] == x){
            std::cout<<"Find value: " << this->array[i] <<std::endl;
            return  array[i];
        }
    }

    std::cout<<"Value not found in this stack" << std::endl;
    return 0;
}

void ThreeStack::Print(){
    for(int i = SIZE_ARRAY - 1 ; i >= 0; i--){
        std::cout << " [" << this->array[i] <<  "] "; 
    }
    std::cout << std::endl;
    
}

int main(){

    ThreeStack* threeStack = new ThreeStack(4);
    threeStack->Print();
    threeStack->Push(1, 2);
    threeStack->Push(7, 2);
    threeStack->Push(7, 2);
    threeStack->Push(7, 2);
    threeStack->Push(7, 2);

    threeStack->Push(2, 3);
    threeStack->Push(2, 1);
    threeStack->Push(4, 1);
    threeStack->Print();
    for(int i = 0; i<3; i++){
        threeStack->Pop(2);
    }
    
    threeStack->Print();

}