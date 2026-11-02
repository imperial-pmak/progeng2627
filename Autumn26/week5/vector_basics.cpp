#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);

    std::cout << v[0] << std::endl;

    v[0] = 15;

    std::cout << v[0] << std::endl;

    v.push_back(30);

    std::cout << v.size() << std::endl;
}