/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

// create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list
    struct Node* adj[n + 1];

    // initialize
    for(int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    // input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // add v to u
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // add u to v (undirected)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // print adjacency list
    for(int i = 1; i <= n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];

        while(temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}