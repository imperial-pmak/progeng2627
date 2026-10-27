#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));
    int y1 = std::rand() % 6 + 2;
    int x1 = std::rand() % 6 + 2;
    
    int x = x1, y = y1, x_temp, y_temp;
    int delx, dely;
    int move_counter = 0;

    std::cout << "Initial position (row, col): " << x1 << ", " << y1 << std::endl;

    bool corner = (x==1 && y==1) || (x==1 && y==8) || (x==8 && y==1) || (x==8 && y==8);
    bool valid = true;

    while (!corner) {
        std::cout << "Enter the coordinates <row col> of next position: " << std::endl;
        std::cin >> y_temp >> x_temp;
        
        
        valid = true;
        
        delx = std::abs(x-x_temp);
        dely = std::abs(y-y_temp);

        if (x_temp < 1 || x_temp > 8 || y_temp < 1 || y_temp > 8) {
            valid = false;
        }
        if (! ((delx==2 && dely==1) || (delx==1 && dely==2))) {
            valid = false;
        }

        if (!valid) {
            std::cout << "Invalid move!" << std::endl;
        }
        else {
            ++move_counter;
            x = x_temp; 
            y = y_temp;
            std::cout << "New coordinates (row, col): " << y << ", " << x << std::endl;
        }

        corner = (x==1 && y==1) || (x==1 && y==8) || (x==8 && y==1) || (x==8 && y==8);
    }

    std::cout << "Corner square reached. Number of valid moves used: " << move_counter << std::endl;
}