#include <iostream>
#include <fstream>
#include <vector>

void extract_text(std::ifstream &infile, std::vector<std::string> &v) {
    std::string t;
    while (infile >> t) {
        v.push_back(t);
    }
}

void replace_words(const std::vector<std::string> &original_ad, std::vector<std::string> &new_ad) {
    for (int i=0; i<original_ad.size(); ++i) {
        if (original_ad[i] == "exclusive") {
            new_ad.push_back("expensive");
        }
        else if (original_ad[i] == "cosy") {
            new_ad.push_back("small");
        }
        else if (original_ad[i] == "bedsit") {
            new_ad.push_back("room");
        }
        else if (original_ad[i] == "quiet") {
            new_ad.push_back("remote");
        }
        else {
            new_ad.push_back(original_ad[i]);
        }
    }
}

int main() {
    std::string infile_name = "ad.txt";
    std::ifstream infile;
    infile.open(infile_name);

    if (!infile.is_open()) {
        std::cout << "Error opening input file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> original_ad;
    std::vector<std::string> new_ad;
    extract_text(infile, original_ad);

    replace_words(original_ad, new_ad);

    std::string outfile_name;
    std::cout << "Please enter name of output file: " << std::endl;
    std::cin >> outfile_name;
    std::ofstream outfile;
    outfile.open(outfile_name);

    for (int i = 0; i < new_ad.size(); ++i) {
        outfile << new_ad[i] << " ";
    }
    outfile << std::endl;

    infile.close();
    outfile.close();
}