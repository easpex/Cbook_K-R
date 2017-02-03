#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Node Node;
struct Node {
    int data;
    Node *next;
};

void add2list(Node **proot, int value);
void printList(Node head);

int main() {
	Node head = NULL;
	add2list(&head, 1);
    add2list(&head, 2);
    add2list(&head, 5);
    add2list(&head, 3);
    add2list(&head, 0);
    add2list(&head, 4);
    add2list(&head, -2);

	printList(h);

	return 0;
}


void add2list(Node **proot, int value) {
    Node **pcur;
    Node *new;

    if (!(new = malloc(sizeof *new))) {
        fprintf(stderr, "malloc(%zu): %s\n", sizeof *new, strerror(errno));
        exit(EXIT_FAILURE);
    }
    new->data = value;

    if (!*proot) {
        // case 1: insert into empty list
        new->next = new;
        *proot = new;
        return;
    }

    if ((*proot)->data >= value) {
        // case 2: insert at beginning of list
        pcur = &(*proot)->next;
        while (*pcur != *proot) {
            pcur = &(*pcur)->next;
        }
        new->next = *proot;
        *proot = *pcur = new;
        return;
    }

    // case 3: insert elsewhere
    pcur = &(*proot)->next;
    while (*pcur != *proot && (*pcur)->data < value) {
        pcur = &(*pcur)->next;
    }
    new->next = *pcur;
    *pcur = new;
}

void printList(Node head) {
    Node tmp;
    printf("inside print\n");
    
    tmp = head;
    while(tmp -> next != head) {
        printf("%d ->\n", tmp -> data);
        tmp = tmp -> next;
    }
    printf("%d ->\n", tmp -> data);
}
