#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[1000][2];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);

    qsort(intervals, n, sizeof(intervals[0]), compare);

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= end) {
            if (intervals[i][1] > end)
                end = intervals[i][1];
        } else {
            printf("%d %d\n", start, end);
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    printf("%d %d\n", start, end);

    return 0;
}