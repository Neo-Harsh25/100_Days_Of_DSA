/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

in c*/

#include <stdio.h>
#include <stdlib.h>

// Simple hash map using arrays (since constraints usually small for lab problems)
#define MAX 1000

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int prefix_sum = 0;
    int max_len = 0;

    // hashmap: sum -> first index
    int hash[2 * MAX];
    for (int i = 0; i < 2 * MAX; i++) {
        hash[i] = -2;  // -2 means not visited
    }

    int offset = MAX;  // to handle negative sums

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Case 1: sum = 0 → from start
        if (prefix_sum == 0) {
            max_len = i + 1;
        }

        // If seen before
        if (hash[prefix_sum + offset] != -2) {
            int prev_index = hash[prefix_sum + offset];
            int len = i - prev_index;
            if (len > max_len) {
                max_len = len;
            }
        } else {
            // store first occurrence
            hash[prefix_sum + offset] = i;
        }
    }

    printf("%d\n", max_len);
    return 0;
}

