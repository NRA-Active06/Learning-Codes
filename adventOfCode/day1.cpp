#include <iostream>
#include <string>
#include <fstream>

int main() {
    int position = 50;
    int target = 0;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }
    
        char dir = line[0];
        int cycle = std::stoi(line.substr(1));
        cycle %= 100;

        if (dir == 'R') {
            position = (position + cycle) % 100;
        }
        else if (dir == 'L') {
            position = (position - cycle + 100) % 100;
        }
        else {
            std::cerr << "Invalid input: \n";
            return 1;
        }

        if (position == 0) {
            target++;
        }
    }
    std::cout << "dial zeroes is: " << target << std::endl;
    return 0;
}
