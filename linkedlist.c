#include <stdio.h>
#include <stdlib.h>

typedef struct node * ptr;
typedef struct node {
	int data;
	ptr next;
} item;

void add2list(ptr *hptr, int n);
void freelist(ptr *hptr);
void printlist(ptr hptr);

int main() {
	ptr h = NULL;
	ptr t = NULL;
	int num;

	while(scanf("%d", &num) == 1) {
		add2list(&h, num);
	}

	printlist(h);

	freelist(&h);
	return 0;
}

void add2list(ptr *hptr, int n) {
	ptr p1, p2;
	ptr t;

	t = (ptr) malloc(sizeof(item));
	if(!t) {
		printf("\n cannot build list \n");
		exit(0);
	}

	t -> data = n;
	p1 = *hptr;

	while( (p1) && p1 -> data < n) {
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

void printlist(ptr h) {
	while(h) {
		printf("%d ->", h -> data);
		h = h -> next;
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
