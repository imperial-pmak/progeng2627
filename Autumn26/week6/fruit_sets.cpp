#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

bool is_present(std::string s, const std::vector<std::string> &v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i] == s) {
            return true;
        }
    }
    return false;
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout) {
    int n = vin1.size();
    for (int i = 0; i < n; ++i) {
        vout.push_back(vin1[i]);
    }

    n = vin2.size();
    for (int i = 0; i < n; ++i) {
        if (!is_present(vin2[i], vout)) {
            vout.push_back(vin2[i]);
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout) {
    int n1 = vin1.size(), n2 = vin2.size();

    if (n1 > n2) {
        for (int i = 0; i < n1; ++i) {
            if (is_present(vin1[i], vin2)) {
                vout.push_back(vin1[i]);
            }
        }
    }
    else {
        for (int i = 0; i < n2; ++i) {
            if (!is_present(vin2[i], vin1)) {
                vout.push_back(vin2[i]);
            }
        }
    }
}


void efficient_union_vector (const std::vector<std::string> &vin1, const std::vector<std::string> &vin2, std::vector<std::string> &vout) {
    int i = 0, j = 0;
    int n1 = vin1.size(), n2 = vin2.size();
    
    while (i<n1 && j<n2) {
        if (vin1[i] == vin2[j]) {
            vout.push_back(vin1[i]);
            ++i; ++j;
        }
        else if (vin1[i] < vin2[j]) {
            vout.push_back(vin1[i]);
            ++i;
        }
        else if (vin2[j] < vin1[i]) {
            vout.push_back(vin2[j]);
            ++j;
        }

        if (i == n1) {
            for (; j<n2; ++j) {
                vout.push_back(vin2[j]);
            }
        }
        else if (j == n2) {
            for (; i<n1; ++i) {
                vout.push_back(vin1[i]);
            }
        }
    }
}

int main() {
    std::string infile1_name = "warehouse1.txt";
    std::string infile2_name = "warehouse2.txt";
    std::ifstream infile1;
    std::ifstream infile2;
    infile1.open(infile1_name);
    infile2.open(infile2_name);

    std::string union_file_name = "union.txt";
    std::string int_file_name = "intersection.txt"; 
    std::ofstream union_file;
    std::ofstream int_file;
    union_file.open(union_file_name);
    int_file.open(int_file_name);

    std::vector<std::string> v1;
    std::vector<std::string> v2;

    if (!infile1.is_open() or !infile2.is_open()) {
        std::cout << "Error opening input files" << std::endl;
        return EXIT_FAILURE;
    }
    if (!union_file.is_open() or !int_file.is_open()) {
        std::cout << "Error opening output files" << std::endl;
        return EXIT_FAILURE;
    }

    std::string t;
    while (infile1 >> t) v1.push_back(t);
    while (infile2 >> t) v2.push_back(t);
    
    for (int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << std::endl;
    }

    std::vector<std::string> v_union;
    std::vector<std::string> v_int;

    union_vector(v1, v2, v_union);
    for (int i = 0; i < v_union.size(); ++i) {
        union_file << v_union[i] << std::endl;
    }

    intersection_vector(v1, v2, v_int);
    for (int i = 0; i < v_int.size(); ++i) {
        int_file << v_int[i] << std::endl;
    }

    infile1.close();
    infile2.close();
    union_file.close();
}