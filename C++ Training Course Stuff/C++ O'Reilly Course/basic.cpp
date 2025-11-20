#include <iostream>
#include <string>
using namespace std;

//KEY THING TO NOTE: use g++ (filename.cpp) to compile the code in the terminal
//then run ./a.out to run the code!

int main() {
    
    //basic c++ outputting of the code
    cout << "Hello World!" << endl; 
    
    //variable assigned (same as C)
    int age = 15; 
    cout << age << endl;

    //user inputs a value and it is stored into a variable
    int age2;
    cout << "Please enter your age: ";
    cin >> age2;
    cout << age2 << endl;

    //Take input Username and age
    //Say Hello (username), Age (age)
    string username; //creates a string
    int age3;
    cout << "Please enter your username and age: ";
    cin >> username >> age3; //takes in two values, separated by a space
    cout << "Hello " << username << "\nAge " << age3 << endl; //prints all of this out in one line order

    //getline function
    string text;
    cout << "What is your name? ";
    cin.ignore(); //if not for this, the previous cin() entries of above would cause getline() to be skipped
    getline(cin, text);
    cout << "Hello, " << text << endl;
    
    return (0);
}