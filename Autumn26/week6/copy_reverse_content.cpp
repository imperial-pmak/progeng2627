#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main() {
    std::string infile_name = "word_input.txt";
    std::string outfile_name = "word_output.txt";
    
    std::ifstream infile;
    std::ofstream outfile;

    infile.open(infile_name);
    outfile.open(outfile_name);

    if (!infile.is_open()) {
        std::cout << "Error opening input file" << std::endl;
        return EXIT_FAILURE;
    }
    else if (!outfile.is_open()) {
        std::cout << "Error opening output file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> s;

    std::string t;
    while (infile >> t) {
        s.push_back(t);
    }
    for (int i = s.size()-1; i>=0; --i) {
        outfile << s[i] << std::endl;
    }

    infile.close();
    outfile.close();
}