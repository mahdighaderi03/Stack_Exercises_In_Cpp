#include <iostream>
using namespace std;

class stack{
    public:
        int array[10];
        int mytop;
        stack();
        int top();
        void push(int value);
        void pop();
        bool isempty();
        bool isfull();
};

int main() {
    stack object1;
    int choice;
    int value;

    do{
        cout << "1. Push " << endl;
        cout << "2. Pop " << endl;
        cout << "3. Top " << endl;
        cout << "4. Check if empty " << endl;
        cout << "5. Check if full " << endl;
        cout << "0. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            object1.push(value);
            break;
        case 2:
            object1.pop();
            break;
        case 3:
            cout << "Top of the stack: " << object1.top() << endl;
            break;
        case 4:
            cout << (object1.isempty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 5:
            cout << (object1.isfull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}

stack::stack(){
    mytop = -1;
}

int stack::top() {
    if (!isempty()){
        return array[mytop];
    }
    else{
        cout << "Stack is empty." << endl;
        return -1;
    }
}

void stack::push(int value){
    mytop++;
    array[mytop] = value;
}

void stack::pop(){
    if (!isempty())
        mytop--;
    else
        cout << "Stack is empty. Cannot pop." << endl;
}

bool stack::isempty(){
    if (mytop == -1)
        return true;
    else
        return false;
}

bool stack::isfull(){
    if(mytop == 9)
        return true;
    else
        return false;
}
