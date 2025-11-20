#include <iostream>
#include "staticStack.h"
#include "dynamicStack.h"
#include "queue.h"

using namespace std;

void run_static_stack()
{
    StaticStack s;
    int choice, value;
    do {
        cout << "\n----- Dynamic Stack Menu -----\n";
        cout << "1. Push\n2. Pop\n3. Peep\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.Push(value);
                break;
            case 2:
                cout << "Popped: " << s.Pop() << endl;
                break;
            case 3:
                cout << "Top element: " << s.Peep() << endl;
                break;
            case 4:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}

void run_queue() {
    int size;
    cout << "Please enter a size for the queue: ";
    cin >> size;
    Queue q(size);
    
    int choice, value;
    do {
        cout << "\n----- Queue Menu -----\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.Enqueue(value);
                break;
            case 2:
                cout << "Dequeued: " << q.Dequeue() << endl;
                break;
            case 3:
                cout << "Front element: " << q.Peek() << endl;
                break;
            case 4:
                q.Display();
                break;
            case 5:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

void run_dynamic_stack()
{
    int size;
    cout << "Please enter a size for the stack: ";
    cin >> size;
    DynamicStack ds(size);
    int choice, value;
    do {
        cout << "\n----- Dynamic Stack Menu -----\n";
        cout << "1. Push\n2. Pop\n3. Peep\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                ds.Push(value);
                break;
            case 2:
                cout << "Popped: " << ds.Pop() << endl;
                break;
            case 3:
                cout << "Top element: " << ds.Peep() << endl;
                break;
            case 4:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}

int main() {
    int choice;

    do {
        cout << "\n----- Main Menu -----\n";
        cout << "1. Static Stack\n";
        cout << "2. Dynamic Stack\n";
        cout << "3. Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                run_static_stack();
                break;
            }
            case 2: {
                run_dynamic_stack();
                break;
            }
            case 3: {
                run_queue();
            }
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}