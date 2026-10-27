#include <iostream>

int main() {
    int a, b, q=0, r=0;

    std::cout << "Please enter a and b " << std::endl;
    std::cin >> a >> b;

    while (a>=b) {
        a -= b;
        ++q;
        r=a;
    }
    std::cout << "The quotient is " << q << std::endl;
    std::cout << "The remainder is " << r << std::endl;
}