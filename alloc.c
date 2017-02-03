#include <stdio.h>
#define ALLOCSIZE 100

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n);
void afree(char *p);

int main() {
	int i;
	for(i = 0; i < ALLOCSIZE; ++i) {
		allocbuf[i] = i;
	}
	alloc(5);
	//printf("alloc(5) = %d\n", alloc(5));
	printf("\nnext alloc\n\n");

	printf("alloc(10) = %d\n", *alloc(10));
	
	afree(alloc(5));
	alloc(5);
	return 0;
}

char *alloc(int n) {
	printf("allocbuf = %d ALLOCSIZE = %d allocp = %d n = %d\n", allocbuf, ALLOCSIZE, allocp, n);
	printf("allocbuf + ALLOCSIZE - allocp = %d\n", allocbuf + ALLOCSIZE - allocp);
	if(allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		printf("allocp = %d | allocp - n = %d\n", allocp, allocp - n);
		printf("---end of alloc---");
		return allocp - n;
	} else {
		return 0;
	}
}

void afree(char *p) {
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
		printf("---end of afree---\n");
	}
}