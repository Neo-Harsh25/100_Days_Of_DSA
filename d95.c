#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node* next;
} Node;

Node* insertSorted(Node* head, float val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL || head->val >= val) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->val < val)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    Node* buckets[1000] = {NULL};

    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->val;
            curr = curr->next;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);

    return 0;
}