#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ( (a) < (b) ) ? (a) : (b)

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void add2list(Node **head, int num);
void printList(Node *p);
Node * mergeList(Node **h1, Node **h2);

int main() {
    Node *head = NULL;
    
    add2list(&head, 1);
    add2list(&head, 2);
    add2list(&head, 5);
    add2list(&head, 3);
    add2list(&head, 0);
    add2list(&head, 4);
    add2list(&head, -2);
    
    //xcode neww
    
    
    printf("head = %d\n", head -> data);
    printList(head);
    
    return 0;
}


void add2list(Node **head, int num) {
    Node *p1, *p2, *t;
    printf("inside add\n");
    
    t = (Node *) malloc(sizeof(Node));
    
    if(!t) {
        printf("not enough memory\n");
        exit(0);
    }
    
    t -> data = num;
    p1 = *head;
    
    while(p1 != NULL && p1 -> next != *head && p1 -> data < num) {
        p2 = p1;
        p1 = p1 -> next;
    }
    
    if(!p1) { //case 1 - if the list is empty
        *head = t;
        t -> next = *head;
    } else if(p1 -> data < t -> data) {
        //if we need to add a node to the end of the list
        printf("case 2|p1 -> data < t -> data = %d\n", t -> data);
        p1 -> next = t;
        t -> next = *head;
    }else if(p1 == *head) {
        
        //if we need to add a node to the beginning of the list
        printf("case 3|p1 -> data >= t -> data = %d\n", t -> data);
        while(p1 -> next != *head) {
            p1 = p1 -> next;
        }
        p1 -> next = t;
        t -> next = *head;
        *head = t;
    } else {
        //need to add a node in the middle
        printf("case 4|p1 -> data >= t -> data = %d\n", t -> data);
        p2 -> next = t;
        t -> next = p1;
    }
}

void printList(Node *head) {
    Node *tmp;
    printf("inside print new\n");
    
    tmp = head;
    while(tmp -> next != head) {
        printf("%d -> ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("%d\n", tmp -> data);
}

Node * mergeList(Node **h1, Node **h2) {
    Node *p1, *p2;
    p1 = *h1;
    p2 = *h2;
    
    if(p1 == NULL) {
        return p2;
    }
    if(p2 == NULL) {
        return p1;
    }
    //p1 != NULL && p1 -> next != *head && p1 -> data < nu
    while( (p1 != NULL && p1 -> next != *head) || (p2 != NULL && p2 -> next != *head) ) {
        if(p1 -> data < p2 -> data) {
            while( (p1 = p1 -> next -> data < p2 -> data)
                ;
            
            
                if() {
                    p1 = p1 -> next;
                } else {
                    p1 -> next = p2;
                    
                }
        
    } //end of while

    
}
