#include <iostream>

void int_div(int a, int b, int& quotient, int& remainder) {
    quotient = a/b;
    remainder = a%b;
}

int main() {
    int a, b, q, r;
    std::cout << "Enter two integers: " << std::endl;
    std::cin >> a >> b;

    int_div(a, b, q, r);

    std::cout << "The quotient is " << q << " and the remainder is " << r << std::endl;
}