#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int randNum;

    int guess = 0;

    srand(time(NULL));

    randNum = (rand() % 100) + 1;

    int count = 0;

    while (guess != randNum) {
        cout << "Enter your guess: ";

        if( !(cin >> guess)) {

            cout << "This input is invalid mate" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (guess == randNum) {
            count++;
            cout << "YOU WIN" << endl;
        }
        else if (guess > randNum) {
            count++;
            cout << "your number is too high" << endl;
        } 
        else if (guess < randNum) {
            count++;
            cout << "your number is too low" << endl;
        } 
    }
    cout << count << endl;
}