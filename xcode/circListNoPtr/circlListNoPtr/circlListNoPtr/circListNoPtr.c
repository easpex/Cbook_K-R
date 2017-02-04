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
    Node *h1 = NULL;
    Node *h2 = NULL;
    Node *m = NULL;
    
    add2list(&h1, 1);
    add2list(&h1, 2);
    add2list(&h1, 3);
    add2list(&h2, 4);
    add2list(&h2, 5);

    printList(h1);
    printList(h2);
    
    m = mergeList(&h1, &h2);
    printList(m);
    
    return 0;
}


void add2list(Node **head, int num) {
    Node *p1, *p2, *t;
    
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
        //printf("case 2|p1 -> data < t -> data = %d\n", t -> data);
        p1 -> next = t;
        t -> next = *head;
    }else if(p1 == *head) {
        
        //if we need to add a node to the beginning of the list
        //printf("case 3|p1 -> data >= t -> data = %d\n", t -> data);
        while(p1 -> next != *head) {
            p1 = p1 -> next;
        }
        p1 -> next = t;
        t -> next = *head;
        *head = t;
    } else {
        //need to add a node in the middle
        //printf("case 4|p1 -> data >= t -> data = %d\n", t -> data);
        p2 -> next = t;
        t -> next = p1;
    }
}

void printList(Node *head) {
    Node *tmp;
    
    tmp = head;
    while(tmp -> next != head) {
        printf("%d -> ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("%d\n", tmp -> data);
}

Node * mergeList(Node **h1, Node **h2) {
    Node *prev1, *prev2, *curr1, *curr2;
    prev1 = *h1;
    curr1 = *h1;
    
    prev2 = *h2;
    curr2 = *h2;
    
    //if one of the lists is NULL
    if(*h1 == NULL) {
        return *h2;
    }
    if(*h2 == NULL) {
        return *h1;
    }
    
    while( (curr1 -> next != *h1) && (curr2 -> next != *h2) ) {
        while( (curr1 -> next != *h1) && (curr2 -> next != *h2) && (curr1 -> data < curr2 -> data) ) {
            prev1 = curr1;
            curr1 = curr1 -> next;
        }
        
        if(prev1 == curr1) {
            //means that curr1 > curr2 so the loop didn't occur; means that we need to insert a node before curr1
            while(curr1 -> next != *h1) {
                curr1 = curr1 -> next;
            }
            curr1 -> next = curr2;
            curr2 -> next = *h1;
            *h1 = curr2;
        } else if(curr1 -> next == *h1 && curr1 -> data < curr2 -> data){
            //if all of the nodes of *h1 are less than *h2
            curr1 -> next = curr2;
            
            while(curr2 -> next != *h2) {
                curr2 = curr2 -> next;
            }
            curr2 -> next = *h1;
        } else if(curr1 -> next == *h1 && curr1 -> data > curr2 -> data) {
            //empty
        }
        //else: prev1 -> next = curr2;
        //      curr2 -> next = curr1 -> next;
        
        
    } //end of while

    return *h1;
}
