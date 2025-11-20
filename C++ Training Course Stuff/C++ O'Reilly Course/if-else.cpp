#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //simple if loop
    int age;
    cin >> age;

    if (age>18){
        cout << "Youre an adult!" << endl;
    }
    else{
        cout << "Youre a minor!" << endl;
    }

    //if else-if else-if ... else loop

    int score;
    cout << "Please intput your score out of 100: ";
    cin >> score;
    
    if(score >= 90){
        cout << "Grade A*" << endl;
    }
    else if (score >=70){
        cout << "Grade A" << endl;
    }
    else if (score >= 50){
        cout << "Grade B" << endl;
    }
    else if (score < 50){
        cout << "You failed" << endl;
    }
    else {
        cout << "Incorrect number inputted" << endl;
    }

    return(0);
}