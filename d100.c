#include <stdio.h>

typedef struct {
    int val;
    int idx;
} Node;

void merge(Node arr[], int left, int mid, int right, int count[]) {
    int i = left, j = mid + 1, k = 0;
    Node temp[1000];

    while (i <= mid && j <= right) {
        if (arr[i].val <= arr[j].val) {
            count[arr[i].idx] += (j - (mid + 1));
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += (j - (mid + 1));
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(Node arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node arr[1000];
    int count[1000] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}