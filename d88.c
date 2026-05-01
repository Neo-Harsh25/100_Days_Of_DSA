#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Check if we can place k cows with at least 'dist' minimum distance
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;              // place first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count == k)
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Binary search on answer
    while (left <= right) {
        int mid = (left + right) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;
            left = mid + 1;  // try for bigger distance
        } else {
            right = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}