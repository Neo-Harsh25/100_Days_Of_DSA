#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int isPossible(int arr[], int n, int m, int limit) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > limit)
            return 0;

        if (pages + arr[i] > limit) {
            students++;
            pages = arr[i];
            if (students > m)
                return 0;
        } else {
            pages += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[1000];
    int sum = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        mx = max(mx, arr[i]);
    }

    int left = mx, right = sum, ans = sum;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}