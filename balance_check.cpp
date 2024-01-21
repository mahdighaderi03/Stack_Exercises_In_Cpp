#include <iostream>
#include <stack>

using namespace std;

class Stack {
private:
    char* arr;
    int top;
    unsigned capacity;

public:
    Stack(unsigned size) : capacity(size), top(-1) {
        arr = new char[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char op) {
        arr[++top] = op;
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '$';
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '$';
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isBalanced(const string& expression) {
    Stack charStack(expression.size());

    for (char ch : expression) {
        if (ch == '(' || ch == '[') {
            charStack.push(ch);
        } else if (ch == ')' || ch == ']') {
            if (charStack.isEmpty() ||
                (ch == ')' && charStack.peek() != '(') ||
                (ch == ']' && charStack.peek() != '[')) {
                return false;
            }
            charStack.pop();
        }
    }

    return charStack.isEmpty();
}

string balanceExpression(const string& expression) {
    Stack charStack(expression.size());
    string balancedExpression = expression;

    for (size_t i = 0; i < expression.size(); ++i) {
        if (expression[i] == '(' || expression[i] == '[') {
            charStack.push(expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']') {
            if (charStack.isEmpty()) {
                balancedExpression.insert(i, 1, expression[i] == ')' ? '(' : '[');
            } else {
                charStack.pop();
            }
        }
    }

    while (!charStack.isEmpty()) {
        balancedExpression += (charStack.pop() == '(') ? ')' : ']';
    }

    return balancedExpression;
}

int main() {
    string input;
    cout << "Enter an expression: ";
    getline(cin, input);

    if (isBalanced(input)) {
        cout << "The parentheses and brackets are balanced." << endl;
    } else {
        cout << "The parentheses and brackets are not balanced." << endl;

        string balancedExpression = balanceExpression(input);
        cout << "Balanced expression: " << balancedExpression << endl;
    }

    return 0;
}
