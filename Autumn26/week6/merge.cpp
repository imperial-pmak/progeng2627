#include <iostream>
#include <fstream>
#include <vector>

void merge_vectors_int(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& merged) {
    int i = 0, j = 0;
    int n1 = v1.size(), n2 = v2.size();
    
    while (i<n1 && j<n2) {
        if (v1[i] == v2[j]) {
            merged.push_back(v1[i]);
            merged.push_back(v1[i]);
            ++i; ++j;
        }
        else if (v1[i] < v2[j]) {
            merged.push_back(v1[i]);
            ++i;
        }
        else if (v2[j] < v1[i]) {
            merged.push_back(v2[j]);
            ++j;
        }

        if (i == n1) {
            for (; j<n2; ++j) {
                merged.push_back(v2[j]);
            }
        }
        else if (j == n2) {
            for (; i<n1; ++i) {
                merged.push_back(v1[i]);
            }
        }
    }
}

int main(){
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    std::vector<int> expected_output;

    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }

    out.clear();
    v1 = {1, 3, 5, 7, 9};
    v2 = {2, 4, 6, 7, 8, 9};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 9};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
}