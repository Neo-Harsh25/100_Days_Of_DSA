/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *q = (int*)malloc(n * sizeof(int));
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % n;
        q[rear] = x;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        front = (front + 1) % n;
    }

    int count = n;
    int idx = front;

    for (int i = 0; i < count; i++) {
        printf("%d", q[idx]);
        if (i < count - 1) printf(" ");
        idx = (idx + 1) % n;
    }

    free(q);
    return 0;
}