#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int isPossible(int arr[], int n, int k, int limit) {
    int painters = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > limit)
            return 0;

        if (sum + arr[i] > limit) {
            painters++;
            sum = arr[i];
            if (painters > k)
                return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

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

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}