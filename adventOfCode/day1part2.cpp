#include <iostream>
#include <string>

int main() {
    int position = 50; // starting position of the dial
    int target = 0; // total times it hits 0 (use long long just in case)
    std::string line; // stores the lines read from each line of text input

    while (std::getline(std::cin, line)) { // reads as long as there is input
        if (line.empty()) {
            continue; // skip empty lines
        }

        char dir = line[0]; //'dir' is shorthand for Direction of the dial's turning
        int cycle = std::stoll(line.substr(1)); 
        // we do NOT do cycle %= 100 anymore because we need the full rotations now!

        if (cycle < 0) {
            std::cerr << "Invalid input (negative steps)\n";
            return 1;
        }

        int zeroCounter = 0; // Count how many times we hit 0 during this rotation

        if (dir == 'R') {
            int pos_mod = position % 100;
            int k0 = (100 - pos_mod) % 100; // first step where we’d hit 0
            if (k0 == 0) k0 = 100;          // if starting at 0, next hit is 100 steps away

            if (cycle >= k0) {
                zeroCounter = 1 + (cycle - k0) / 100;
            }

            // Update final position (only need the net movement modulo 100)
            position = (position + (cycle % 100) + 100) % 100;
        }
        else if (dir == 'L') {
            // Moving L: positions visited are (position - 1), ..., (position - cycle) mod 100
            int pos_mod = position % 100;
            int k0 = pos_mod % 100; // first step where we’d hit 0
            if (k0 == 0) k0 = 100;  // if starting at 0, next hit is 100 steps away

            if (cycle >= k0) {
                zeroCounter = 1 + (cycle - k0) / 100;
            }

            // Update final position
            position = (position - (cycle % 100) + 100) % 100;
        }
        else {
            std::cerr << "Invalid input: unknown direction\n";
            return 1;
        }

        // Add all hits from this move
        target += zeroCounter;
    }

    std::cout << "The number of times the cycle passes Zero is: " << target << std::endl;
    return 0;
}