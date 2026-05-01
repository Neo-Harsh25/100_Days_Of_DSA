#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0];
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l] < heap[smallest])
        smallest = l;
    if (r < n && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void push(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[1000][2];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);

    qsort(intervals, n, sizeof(intervals[0]), compare);

    int heap[1000], size = 0;

    push(heap, &size, intervals[0][1]);

    for (int i = 1; i < n; i++) {
        if (heap[0] <= intervals[i][0])
            pop(heap, &size);

        push(heap, &size, intervals[i][1]);
    }

    printf("%d\n", size);

    return 0;
}