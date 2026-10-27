#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2, delx, dely;
    std::string type;
    bool valid = true;

    std::cout << "Please enter type of piece (knight, bishop, rook, king, queen) " << std::endl;
    std::cin >> type;

    std::cout << "Please enter initial position of piece, first horizontal then vertical coordinate " << std::endl;
    std::cin >> x1 >> y1;

    std::cout << "Please enter final position of piece, first horizontal then vertical coordinate " << std::endl;
    std::cin >> x2 >> y2;

    delx = std::abs(x1-x2);
    dely = std::abs(y1-y2);

    if (x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        valid = false;
    }

    if (type == "knight") {
        if (! ((delx==2 && dely==1) || (delx==1 && dely==2))) {
            valid = false;
        }
    }
    else if (type == "bishop") {
        if (delx != dely) {
            valid = false;
        }
    }
    else if (type == "rook") {
        if (delx==0 || dely==0) {
        }
        else {
            valid = false;
        }
    }
    else if (type == "king") {
        if (delx > 1 || dely > 1) {
            valid = false;
        }
    }
    else if (type == "queen") {
        if (delx != 0 || dely != 0) {
            if (delx != dely) {
                valid = false;
            }
        }
    }
    else {
        std::cout << "Invalid piece type entered. " << std::endl;
    }

    if (valid) {
        std::cout << "Move is valid" << std::endl;
    }
    else {
        std::cout << "Move is invalid. " << std::endl;
    }

}