#include <stdio.h>
#include <stdlib.h>

typedef struct node * ptr;
typedef struct node {
    int data;
    ptr next;
}item;

void add2list(ptr *head, int num);
void printList(ptr p);

int main() {
    printf("before add\n");
    ptr h = NULL;
    add2list(&h, 2);
    add2list(&h, 5);
    add2list(&h, 3);
    add2list(&h, 1);
    printf("%d ->\n", h  -> data);
    printList(h);
    
    return 0;
}


void add2list(ptr *head, int num) {
    printf("inside add\n");
    ptr p1, p2, t, temp;
    
    t = (ptr) malloc(sizeof(item));
    
    if(!t) {
        printf("not enough memory\n");
        exit(0);
    }
    
    t -> data = num;
    p1 = *head;
    
    if(p1) {
        printf("p1 -> next != *head = %d\n", (p1 -> next != *head) ? 1 : 0);
        printf("(p1 -> data > num) %d\n", (p1 -> data < num) ? 1 : 0);

    }
    while( (p1 != NULL && p1 -> next != *head) && (p1 -> data < num) ) {
        p2 = p1;
        p1 = p1 -> next;
    }
    
    if(*head == p1) {
        if(!(*head)) {  //null
            *head = t;
            t -> next = t;
        } else {
            (*head) -> next = t; //second
            t -> next = p1;
            
            
        }
    } else {
        p2 -> next = t;
        t -> next = p1;
    }
}

void printList(ptr p) {
    printf("inside print\n");
    
    ptr t;
    t = p;

    if(!p) {
        printf("The list is empty\n");
    }
    while(t -> next != p) {
        printf("%d ->\n", t -> data);
        t = t -> next;
    }
    printf("%d ->\n", t -> data);
}
