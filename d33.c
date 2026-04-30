/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>

char stack[1000];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    char infix[1000];
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            printf("%c", c);
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                printf("%c", pop());
            pop();
        } 
        else {
            while (top != -1 && precedence(peek()) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
    }

    while (top != -1)
        printf("%c", pop());

    return 0;
}