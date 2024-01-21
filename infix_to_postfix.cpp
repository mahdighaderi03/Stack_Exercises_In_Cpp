#include <iostream>
#include <cctype>
#include <stack>

using namespace std;

bool isOperator(char ch) {
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

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix.push_back(ch);
        }
        else if (ch == '(') {
            operators.push(ch);
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        }
        else if (isOperator(ch)) {
            while (!operators.empty() && getPrecedence(ch) <= getPrecedence(operators.top())) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
