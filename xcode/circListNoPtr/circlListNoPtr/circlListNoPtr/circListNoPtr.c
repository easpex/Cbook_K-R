#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ( (a) < (b) ) ? (a) : (b)

typedef struct Node {
    int data;
    struct Node *next;
} Node;


void add2list(Node **head, int num);
void printList(Node *p);
void printSingleList(Node *h);
Node * breakCircList(Node *h);
Node * mergeList(Node **h1, Node **h2);

int main() {
    Node *h1 = NULL;
    Node *h2 = NULL;
    Node *m = NULL;
    Node *test = NULL;
    
    add2list(&test, 1);
    add2list(&test, 1);
    add2list(&test, 1);
    test = breakCircList(test);
    printSingleList(test);
    
    
    add2list(&h1, 1);
    add2list(&h1, 2);
    add2list(&h1, 3);
    add2list(&h1, 7);
    add2list(&h2, 4);
    add2list(&h2, 5);
    add2list(&h2, 7);
    add2list(&h2, 9);
    
    
    m = mergeList(&h1, &h2);
    printf("result\n");
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
    
    if(!p1) { /* case 1 - if the list is empty */
        *head = t;
        t -> next = *head;
    } else if(p1 -> data < t -> data) {
        /* if we need to add a node to the end of the list */
        /* printf("case 2|p1 -> data < t -> data = %d\n", t -> data); */
        p1 -> next = t;
        t -> next = *head;
    } else if(p1 == *head) {
        
        /* if we need to add a node to the beginning of the list */
        /* printf("case 3|p1 -> data >= t -> data = %d\n", t -> data); */
        while(p1 -> next != *head) {
            p1 = p1 -> next;
        }
        p1 -> next = t;
        t -> next = *head;
        *head = t;
    } else {
        /* need to add a node in the middle */
        /* printf("case 4|p1 -> data >= t -> data = %d\n", t -> data); */
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
    Node *curr1, *curr2, *tmp, *resHead, *resTail;
    
    curr1 = *h1;
    curr2 = *h2;
    
    /* if one of the lists is NULL */
    if(*h1 == NULL) {
        return *h2;
    }
    if(*h2 == NULL) {
        return *h1;
    }
    
    /* transform the circlists into regular lists */
    curr1 = breakCircList(*h1);
    
    curr2 = breakCircList(*h2);
    
    resHead = resTail = NULL;
    
    while(curr1 != NULL && curr2 != NULL) {
        /* determine the smaller node */
        if(curr1 -> data < curr2 -> data) {
            tmp = curr1;
            curr1 = curr1 -> next;
        } else {
            tmp = curr2;
            curr2 = curr2 -> next;
        }
        /* resHead always points to the smallest node. resTail increments and points to the next node which is being merged */
        if(!resHead) {
            resHead = resTail = tmp; /* if the resHead is NULL */
        } else {
            resTail -> next = tmp; /* first point to the tmp which itself points to many nodes */
            resTail = resTail -> next; /* increment resTail to the next node so that the last in saved in the merged list */
        }
        resTail -> next = NULL; /* because tmp pointed to a lot of nodes, let resTail point to NULL node now */
    } /* end of while */
    
    /* if now one of original lists is NULL then simply merge it to another one */
    if(curr1 == NULL) {
        resTail -> next = curr2;
    } else {
        resTail -> next = curr1;
    }
    
    /* now transform the regular linked list into circ list again */
    tmp = resHead;
    while(tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = resHead;
    
    return resHead;
    
}

void printSingleList(Node *h) {
    printf("from printSingleList\n");
    while(h) {
        printf("%d ->", h -> data);
        h = h -> next;
    }
    printf("\n");
}

Node * breakCircList(Node *h) {
    Node * curr1 = h;
    while(curr1 -> next != h) { /* transform circ list into regular linked list */
        curr1 = curr1 -> next;
    } /* end of while */
    curr1 -> next = NULL;
    printSingleList(h);
    printf("h -> data = %d\n", h -> data);
    return h;
}
