/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/

#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int value;
            scanf("%d", &value);
            if (top < MAX - 1) {
                stack[++top] = value;
            }
        } 
        else if (op == 2) {
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top--]);
            }
        } 
        else if (op == 3) {
            if (top == -1) {
                printf("\n");
            } else {
                for (int i = top; i >= 0; i--) {
                    printf("%d", stack[i]);
                    if (i > 0)
                        printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;
}