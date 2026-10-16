#include <iostream>

int main() {
    std::string unit_in, unit_out;
    double temp_in, temp_out;
    bool unit_valid = true;

    std::cin >> temp_in >> unit_in;

    if (unit_in == "C" || unit_in == "c") {
        temp_out = temp_in*1.8 + 32;
        unit_out = "F";
    }
    else if (unit_in == "F" || unit_in == "f") {
        temp_out = (temp_in-32)/1.8;
        unit_out = "C";
    }
    else {
        unit_valid = false;
    }

    if (unit_valid) {
        std::cout << temp_out << " " << unit_out << std::endl;
    }
    else {
        std::cout << "error, unit not recognised" << std::endl;
    }
}