#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (top >= 0)
            top--;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0)
            printf(" ");
    }

    return 0;
}