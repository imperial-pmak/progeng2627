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

int smallest_factor(int n) {
    int stop = sqrt(n)+1;
    for (int i=2; i<=stop; ++i) {
        if (n%i==0 && is_prime(i)) {
            return i;
        }
    }
    return 0;
}

int main() {
    int n;

    std::cout << "Please enter number: " << std::endl;
    std::cin >> n;

    std::cout << "Smallest prime factor is " << smallest_factor(n);
}