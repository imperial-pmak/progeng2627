#include <iostream>
#include <cmath>

int main() {
    double a, b, c, perimeter, area, semiperimeter;
    
    std::cout << "Please enter the three sides of the triangle " << std::endl;
    std::cin >> a >> b >> c;

    bool valid = (a+b>c) && (a+c>b) && (b+c>a);

    if (valid) {
        if (a==b && b==c) {
            std::cout << "Sides form an equilateral triangle." << std::endl;
        }
        else if (a==b || b==c || a==c) {
            std::cout << "Sides form an isosceles triangle. " << std::endl;
        }
        else {
            std::cout << "Sides form a scalene triangle. " << std::endl;
        }

        perimeter = a+b+c;
        std::cout << "Perimter = " << perimeter << std::endl;

        semiperimeter = perimeter/2;
        
        area = std::sqrt(semiperimeter*(semiperimeter-a)*(semiperimeter-b)*(semiperimeter-c));

        std::cout << "Area of the triangle = " << area << std::endl;
    }
    else {
        std::cout << "Sides do not form a valid triangle. " << std::endl;
    }
}