#include <iostream>
#include <cmath>

bool is_prime(int n) {
    int stop = sqrt(n)+1;
    for (int i=2; i<=stop; ++i) {
        if (n%i==0 && n != i) {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b;

    std::cout << "Enter the endpoints of the range " << std::endl;
    std::cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (is_prime(i)) {
            std::cout << i << std::endl;
        }
    }
}