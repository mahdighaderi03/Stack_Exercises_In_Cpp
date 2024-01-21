#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>
using namespace std;

bool isoperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int getPrecedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

float postfix_evaluation(string postfix) {
    stack<float> operandstack;

    float operand1, operand2;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            // Convert char to float
            operandstack.push(ch - '0');
        }
        else if (isoperator(ch)) {
            operand2 = operandstack.top();
            operandstack.pop();
            operand1 = operandstack.top();
            operandstack.pop();
        }

        switch (ch) {
            case '+':
                operandstack.push(operand1 + operand2);
                break;
            case '-':
                operandstack.push(operand1 - operand2);
                break;
            case '*':
                operandstack.push(operand1 * operand2);
                break;
            case '/':
                operandstack.push(operand1 / operand2);  // Fix: Use division here
                break;
            case '^':
                operandstack.push(pow(operand1, operand2));
                break;
        }
    }

    return operandstack.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);

    float result = postfix_evaluation(postfix);

    cout << "Result: " << result << endl;

    return 0;
}
