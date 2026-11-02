#include <iostream>
#include <vector>
#include <cmath>

bool digits_in_base(int num, int base, std::vector<int> &digits) {
    if (base < 2 || base > 16) {
        return false;
    }
    
    std::vector<int> temp;
    int q=num, r=0;
    while (q != 0) {
        r = q % base;
        q /= base;
        digits.push_back(r);
    }

    /* int i = temp.size()-1;
    for (; i>=0; --i) {
        digits.push_back(temp[i]);
    } */
    return true;
}

void print_digits_as_number(std::vector<int> digits) {
    int n = digits.size()-1;
    for (int i = n; i>=0; --i) {
        if (digits[i] <= 9) {
            std::cout << digits[i];
        }
        else {
            switch (digits[i]) {
                case 10:
                    std::cout << "A";
                    break;
                case 11:
                    std::cout << "B";
                    break;
                case 12:
                    std::cout << "C";
                    break;
                case 13:
                    std::cout << "D";
                    break;
                case 14:
                    std::cout << "E";
                    break;
                case 15:
                    std::cout << "F";
                    break;
                default:
                    break;
            }
        }
    }
    std::cout << std::endl;
}

int digits_to_decimal(const std::vector<int> &digits, int base) {
    // digits arranged from LSB to MSB
    int sum = 0;
    for (int i = 0; i<digits.size(); ++i) {
        sum += digits[i]*((int)(std::pow(base, i)));
    }
    return sum;
}

bool convert_base(const std::vector<int> &digits1, int base1, int base2, std::vector<int> &digits2) {
    int n = digits_to_decimal(digits1, base1);
    return digits_in_base(n, base2, digits2);
}

int main() {
    int num = 1;
    std::vector<int> octal_digits;
    std::vector<int> hex_digits;

    digits_in_base(num, 8, octal_digits);

    std::cout << "Octal: ";
    print_digits_as_number(octal_digits);

    if (convert_base(octal_digits, 8, 16, hex_digits)) {
        std::cout << "Hexadecimal: ";
        print_digits_as_number(hex_digits);
    } else {
        std::cout << "Invalid base" << std::endl;
    }

    return 0;
}