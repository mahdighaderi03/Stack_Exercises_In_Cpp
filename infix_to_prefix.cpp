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

string infixToPrefix(const string& infix) {
    stack<char> operators;
    string prefix;

    for (int i = infix.size() - 1; i >= 0; --i) {
        char ch = infix[i];

        if (isalnum(ch)) {
            prefix += ch;
        }
        else if (ch == ')') {
            operators.push(ch);
        }
        else if (ch == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else if (isOperator(ch)) {
            while (!operators.empty() && getPrecedence(ch) < getPrecedence(operators.top())) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
