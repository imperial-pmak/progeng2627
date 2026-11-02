#include <iostream>
#include <vector>

int main() {
    int n, t;
    std::cout << "Enter n " << std::endl;
    std::cin >> n;

    std::vector<int> v;
    for (int i=0; i<n; ++i) {
        std::cin >> t;
        v.push_back(t);
    }

    std::cout << "Enter t " << std::endl;
    std::cin >> t;

    for (int i=0; i<v.size(); ++i) {
        if (v[i]<t) {
            std::cout << v[i] << " ";
        }
    }
    std::cout << std::endl;
}