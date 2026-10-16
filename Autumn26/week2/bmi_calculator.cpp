#include <iostream>

int main() {
    double weight, height, bmi;

    std::cout << "Please enter your weight (in kg) " << std::endl;
    std::cin >> weight;

    std::cout << "Please enter your height (in m) " << std::endl;
    std::cin >> height;

    bmi = weight / (height*height);

    std::cout << "You BMI is " << bmi << std::endl;
}