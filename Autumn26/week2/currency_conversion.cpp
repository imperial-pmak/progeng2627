#include <iostream>

int main() {
    double exchange_rate, gbp, eur;
    // 1€ = £0.84633

    std::cout << "Please enter the amount of money in GBP " << std::endl;
    std::cin >> gbp;

    std::cout << "Please enter the current exchange rate to Euros i.e. how many EUR in 1 GBP " << std::endl;
    std::cin >> exchange_rate;

    eur = exchange_rate * gbp;
    std::cout << "Amount in EUR = " << eur << std::endl;
}