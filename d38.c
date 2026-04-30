/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int dq[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = MAX/2;
        dq[front] = x;
    } else {
        dq[--front] = x;
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = MAX/2;
        dq[rear] = x;
    } else {
        dq[++rear] = x;
    }
}

void pop_front() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else front++;
}

void pop_back() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else rear--;
}

int get_front() {
    if (isEmpty()) return -1;
    return dq[front];
}

int get_back() {
    if (isEmpty()) return -1;
    return dq[rear];
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x;
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            int x;
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        }
        else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
    }

    return 0;
}