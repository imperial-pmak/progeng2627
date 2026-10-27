#include <iostream>

void myswap(double& a, double& b) {
    double tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void sort_three_numbers(double& a, double& b, double& c) {

    if (a>b) {
        myswap(a, b);
    }
    if (a>c) {
        myswap(a, c);
    }
    if (b>c) {
        myswap(b,c);
    }
}

int main() {
    double a, b, c;
    
    std::cout << "Enter three numbers: " << std::endl;
    std::cin >> a >> b >> c;

    sort_three_numbers(a, b, c);

    std::cout << a << " " << b << " " << c << std::endl;
}