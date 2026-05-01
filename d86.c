#include <stdio.h>

int integerSqrt(int n) {
    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        // To avoid overflow, use mid <= n / mid instead of mid*mid <= n
        if (mid <= n / mid) {
            ans = mid;        // possible answer
            left = mid + 1;   // try to find bigger
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));

    return 0;
}