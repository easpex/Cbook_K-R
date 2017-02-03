#include <stdio.h>
#include <stdlib.h>

typedef struct node * ptr;
typedef struct node {
	int data;
	ptr next;
} item;

typedef struct tnode {
	int data;
	struct tnode * next;
} titem;

void printList(ptr p);
void printTlist(struct tnode * p);
void add2list(ptr *hptr, int num);
void freelist(ptr *hptr);

int main() {
	item h1, h2, h3;
	ptr h = NULL;
	titem t1, t2;
	h1.data = 11;
	h2.data = 12;
	h3.data = 13;
	h1.next = &h2;
	h2.next = &h3;
	printList(&h1);

	/*
	t1.data = 21;
	t2.data = 22;
	t1.next = &t2;
	t2.next = NULL;
	*/
	add2list(&h, 1);
	add2list(&h, 10);
	add2list(&h, 5);
	printList(h);
	freelist(&h);
	printList(h);

}

void printList(ptr p) {
	printf("%s\n", (!p) ? "list is NULL" : "");
	while(p) {
		printf("%d -> \n", p -> data);
		p = p -> next;
	}
}

void printTlist(struct tnode * p) {
	while(p) {
		printf("%d -> \n", p -> data);
		p = p -> next;
	}
}

void add2list(ptr *hptr, int num) {
	ptr p1, p2, t;

	t = (ptr) malloc(sizeof(item));

	if(!t) {
		printf("not enough memory\n");
		exit(0);
	}

	t -> data = num;
	p1 = *hptr;

	if( p1 && p1 -> data < num) {
		p2 = p1;
		p1 = p1 -> next;
	}

	if(p1 == *hptr) {
		*hptr = t;
		t -> next = p1;
	} else {
		p2 -> next = t;
		t -> next = p1;
	}
}

void freelist(ptr *hptr) {
	ptr p;

	while(*hptr) {
		p = *hptr;
		*hptr = (*hptr) -> next;
		free(p);
	}
}
