#include <iostream>
#include <vector>

unsigned long get_C_k(const std::vector<unsigned long> &c) {
    unsigned long answer = 0;
    int n = c.size();
    if (n == 0) {
        return 1;
    }
    for (int i=0; i < n; ++i) {
        answer += c[i]*c[n-1-i];
    }
    return answer;
}

std::vector<unsigned long> catalan_numbers(int n) {
    std::vector<unsigned long> v;
    unsigned long C_k;
    for (int i = 0; i <= n; ++i) {
        C_k = get_C_k(v);
        v.push_back(C_k);
    }

    return v;
}

int main() {
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<unsigned long> numbers = catalan_numbers(n);

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << "C" << i << " = " << numbers[i] << std::endl;
    }

    return 0;    
}