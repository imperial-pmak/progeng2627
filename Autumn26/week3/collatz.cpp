#include <iostream>

int main() {
    int n, step_count = 0, max = 0;

    std::cout << "Please enter the number " << std::endl;
    std::cin >> n;

    std::cout << n << " ";

    while (n!=1) {
        max = std::max(max, n);
        if (n%2==0) {
            n /= 2;
        }
        else {
            n = 3*n + 1;
        }
        ++step_count;
        std::cout << n << " ";
    }
    std::cout << std::endl << "Number of steps = " << step_count << std::endl;
    std::cout << "Maximum number reached = " << max << std::endl;
}