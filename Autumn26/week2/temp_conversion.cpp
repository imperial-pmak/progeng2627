#include <iostream>

int main() {
    double celsius, fahrenheit;

    std::cout << "Please enter temperature in celsius degrees " << std::endl;
    std::cin >> celsius;

    fahrenheit = celsius*1.8 + 32;

    std::cout << "Temperature in fahrenheit is " << fahrenheit << " degrees" << std::endl;
}