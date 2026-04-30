/*roblem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** top,int val){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=val;
    n->next=*top;
    *top=n;
}

int pop(struct Node** top){
    struct Node* t=*top;
    int v=t->data;
    *top=t->next;
    free(t);
    return v;
}

int main(){
    char token[100];
    struct Node* top=NULL;

    while(scanf("%s",token)!=EOF){
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))){
            push(&top,atoi(token));
        }else{
            int b=pop(&top);
            int a=pop(&top);
            int r=0;

            if(token[0]=='+') r=a+b;
            else if(token[0]=='-') r=a-b;
            else if(token[0]=='*') r=a*b;
            else if(token[0]=='/') r=a/b;

            push(&top,r);
        }
    }

    printf("%d",pop(&top));
    return 0;
}