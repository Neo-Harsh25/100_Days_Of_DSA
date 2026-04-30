/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n;
    scanf("%d",&n);

    struct Node *front=NULL,*rear=NULL;

    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);

        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=val;
        newNode->next=NULL;

        if(front==NULL){
            front=newNode;
            rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
    }

    struct Node* temp=front;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL) printf(" ");
        temp=temp->next;
    }

    return 0;
}