#include <iostream>
int main(){
    unsigned long long i = 10;
    while(i > 1){
        i = i * i;
        std::cout << "*" << std::endl;
    }
    std::cout << "x" << std::endl;
}