#include <iostream>
#include <string>
using namespace std;

int main(){

    //simple while loop
    int steps = 1;
    
    while( steps <= 5){
        cout << "Steps " << steps << endl;
        steps += 1;
    }
    
    //simple for loop
    for(int walks = 1; walks <= 5; walks++){
        cout << "Walks " << walks << endl;
    }

    //nested loop
    for (int row = 1; row <= 5; row++){
        for (int col = 1; col <= row; col++){
            cout << col << " ";
        }
        cout << endl;
    }

    // do-while loop
    int x = -5;
    do {
        cout << "Youre a cool dude!" << endl; //runs at least once, even if condition isn't met
        x--;
    }
    while (x > 0);

    return 0;
}