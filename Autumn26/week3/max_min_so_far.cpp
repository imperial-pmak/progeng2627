#include <iostream>

int main() {
    int n=1, max=0, min;
    bool min_set = false;

    while (n!=0) {
        std::cout << "please enter number: " << std::endl;
        std::cin >> n;

        max = std::max(n, max);
        if (min_set) min = std::min(n, min);
        else {
            min = n;
            min_set = true;
        }

        std::cout << "maximum so far: " << max << std::endl;
        std::cout << "minimum so far: " << min << std::endl;
    }
}