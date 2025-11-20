#include <iostream>
#include <string>
using namespace std;

//simple function
bool isPrime(int number) {
    for (int i = 2; i < number; i++){
        if (number %i == 0){
            return false;
        }
    }
    return true;
}

//function call to another function

void allPrimeNum(int range){
    for (int i = 2; i < range; i++){
        if (isPrime(i)){
            cout << i << ", ";
        }
    }
}

int main() {

    int num;
    cout << "Please enter a number: ";
    cin >> num;
    cout << isPrime(num) << endl;
    cout << "1 means it is a prime number, 0 means it is not a prime number" << endl;
    
    int r;
    cout << "Plese enter a range: ";
    cin >> r;
    allPrimeNum(r);
    cout << "are all prime numbers!" << endl;

    return 0;
}