#include <iostream>

int main() {
    double length, width, perimeter, area;

    std::cout << "Please enter length of rectangle " << std::endl;
    std::cin >> length;
    
    std::cout << "Please enter width of rectangle " << std::endl;
    std::cin >> width;

    perimeter = 2*(length + width);
    area = length * width;

    std::cout << "Perimeter of rectangle = " << perimeter << std::endl;
    std::cout << "Area of rectangle = " << area << std::endl;
}