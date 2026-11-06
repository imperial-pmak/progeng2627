#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

int main() {
    std::string filename = "word_input.txt";

    std::ifstream infile;
    infile.open(filename);

    if (infile.is_open()) {
        std::vector<std::string> s;

        std::string t;
        while (infile >> t) {
            s.push_back(t);
        }
        for (int i = s.size()-1; i>=0; --i) {
            std::cout << s[i] << std::endl;
        }

        infile.close();
    }
    else {
        std::cout << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }
}