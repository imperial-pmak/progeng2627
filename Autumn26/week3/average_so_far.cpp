#include <iostream>

int main() {
    int n, count = 0;
    double sum = 0;
    double avg = 0;

    std::cout << "enter a number: " << std::endl;
    std::cin >> n;
    ++count;

    while (n != 0) {
        sum += n;
        avg = sum/count;

        std::cout << "the average so far is: " << std::endl;
        std::cout << avg << std::endl;

        std::cout << "enter a number: " << std::endl;
        std::cin >> n;
        ++count;
    }
}