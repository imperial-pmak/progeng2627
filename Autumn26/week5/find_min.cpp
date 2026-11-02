#include <iostream>
#include <vector>

int min_vector_element(const std::vector<double>& vin) {
    if (vin.size()==0) {
        return -1;
    }
    
    int i_min = 0;
    double min = vin[0];

    for (int i=1; i < vin.size(); ++i) {
        if (vin[i] < min) {
            i_min = i;
            min = vin[i];
        }
    }
    return i_min;
}

int main() {
    std::vector<double> v1{0., 1., 3., 5., -1.};
    std::cout << min_vector_element(v1) << std::endl;

    std::vector<double> v2{0.};
    std::cout << min_vector_element(v2) << std::endl;

    std::vector<double> v3;
    std::cout << min_vector_element(v3) << std::endl;
}