#include <iostream>

double mypow(double base, int exp){
    double result = 1; 

    for (int i=0; i<exp; ++i) {
        result *= base;
    }

    return result;
    // at the end we return the value we computed
    // we *do not print* anything in the function
}

double sum_powers(double base, int n) {
    double result = 0;

    for (int i=1; i<=n; ++i) {
        result += mypow(base, i);
    }

    return result;
}

int main() {
    double x; int n;

    std::cout << "Enter base x and maximum exponent n" << std::endl;
    std::cin >> x >> n;

    std::cout << "The sum of powers = " << sum_powers(x, n) << std::endl;
}