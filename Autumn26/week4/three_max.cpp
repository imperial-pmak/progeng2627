#include <iostream>

int three_max(int a, int b, int c) {
    if (a>=b && a>=c) {
        return a;
    }
    else if (b>=a && b>=c) {
        return b;
    }
    else {
        return c;
    }
}

int main() {
    int a, b, c;

    std::cout << "Enter three numbers: " << std::endl;
    std::cin >> a >> b >> c;
    std::cout << "The maximum is: " <<  three_max(a, b, c) << std::endl;

}