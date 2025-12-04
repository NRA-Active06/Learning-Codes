#include <iostream>
#include <string>

int main() {
    int position = 50; //starting position of the dial
    int target = 0; //the amount of times it hits 0
    std::string line; //stores the lines read from each line of text input

    while (std::getline(std::cin, line)) { //reads as long as there is input
        if (line.empty()) { 
            continue; //skips empty lines and just jumps up the loop
        }
    
        char dir = line[0]; //'dir' is shorthand for Direction of the dials turning
        int cycle = std::stoi(line.substr(1)); //string to integer, removes first letter and then turns rest into an integer
        cycle %= 100; //makes it a range of 0-99 by using the modulus operator

        if (dir == 'R') {
            position = (position + cycle) % 100; //adds the aforementioned cycle value to the position (the users input)
        }
        else if (dir == 'L') {
            position = (position - cycle + 100) % 100; //modulus to keep it in the 100 range, +100 as negatives give headaches
        }
        else {
            std::cerr << "Invalid input: \n"; //in case an incorrect input has been given, error message is displayed
            return 1;
        }

        if (position == 0) {
            target++; //if it lands EXACTLY on the zero, just increment the 'target'
        }
    }
    std::cout << "dial zeroes is: " << target << std::endl; //displays the answer to the user
    return 0;
}

//to run it, in the terminal enter 'your output file name' < day1.txt
