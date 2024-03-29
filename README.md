# Stack_Exercises_In_Cpp
Welcome to this repository, where you'll find a well-designed implementation of a stack data structure in C++. Alongside the stack implementation, I have included a set of exercises that explore various applications of stacks in the computer world.


## stack_with_array:
This C++ program demonstrates a basic implementation of a stack using an array. The stack class includes methods for pushing, popping, checking the top element, and determining whether the stack is empty or full.

### Class: stack

#### Member Variables
- `int array[10]`: An array to store the stack elements.
- `int mytop`: An integer representing the top index of the stack.

#### Member Functions
1. **Constructor (`stack()`):** Initializes the stack with an initial top index of -1.

2. **`int top()`:** Returns the top element of the stack. If the stack is empty, it prints an error message and returns -1.

3. **`void push(int value)`:** Adds an element to the top of the stack.

4. **`void pop()`:** Removes the element from the top of the stack. If the stack is empty, it prints an error message.

5. **`bool isempty()`:** Returns true if the stack is empty; otherwise, returns false.

6. **`bool isfull()`:** Returns true if the stack is full; otherwise, returns false.

### Main Function
The `main()` function creates an instance of the `stack` class and provides a simple menu-driven interface to interact with the stack.

#### Menu Options
1. **Push:** Add an element to the stack.
2. **Pop:** Remove the top element from the stack.
3. **Top:** Display the top element of the stack.
4. **Check if empty:** Display whether the stack is empty.
5. **Check if full:** Display whether the stack is full.
0. **Exit:** Terminate the program.


## infix_to_postfix:
This C++ program converts an infix expression to its equivalent postfix form using a stack-based approach.

### Functionality
The program provides the following features:

1. **isOperator(char ch):** Determines if a character is an operator (`+`, `-`, `*`, `/`, `^`).

2. **getPrecedence(char op):** Returns the precedence level of an operator.

3. **infixToPostfix(const string& infix):** Converts an infix expression to postfix using a stack to handle operators and parentheses.

### Main Function
The `main()` function allows the user to input an infix expression. It then utilizes the `infixToPostfix` function to convert the infix expression to postfix notation and displays the result.

### Example
```
Enter an infix expression: (A+B)*C-D/E^F
Postfix expression: AB+C*DEF^/-
```


## infix_to_prefix:
This C++ program converts an infix expression to its equivalent prefix form using a stack-based approach.

### Functionality
The program provides the following features:

1. **isOperator(char ch):** Determines if a character is an operator (`+`, `-`, `*`, `/`, `^`).

2. **getPrecedence(char op):** Returns the precedence level of an operator.

3. **infixToPrefix(const string& infix):** Converts an infix expression to prefix using a stack to handle operators and parentheses. The algorithm processes the infix expression in reverse order.

### Main Function
The `main()` function allows the user to input an infix expression. It then utilizes the `infixToPrefix` function to convert the infix expression to prefix notation and displays the result.

### Example
```
Enter an infix expression: (A+B)*C-D/E^F
Prefix expression: *+ABC/-DEF^
```


## postfix_evaluation:
This C++ program evaluates a given postfix expression and outputs the result.

### Functionality
The program provides the following features:

1. **isoperator(char ch):** Determines if a character is an operator (`+`, `-`, `*`, `/`, `^`).

2. **getPrecedence(char op):** Returns the precedence level of an operator.

3. **postfix_evaluation(string postfix):** Evaluates a postfix expression using a stack to handle operands and operators.

### Main Function
The `main()` function allows the user to input a postfix expression. It then utilizes the `postfix_evaluation` function to evaluate the expression and displays the result.

### Example
```
Enter a postfix expression: 52+3*4-
Result: 14
```
