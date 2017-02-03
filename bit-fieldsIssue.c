#include <stdio.h>
#define LEN 16
#define BIT_IN_CHAR 8

typedef struct Set {
	unsigned int init : 1;
	char arr[LEN];
} Set;

Set A;

void printBitSet(Set *p);

int main() {
	Set *setp;
	setp = &A;

	setp -> init = 1;

	printBitSet(setp);
}

void printBitSet(Set *p) {
	int pos;
	int i;

	for(i = 0; i < LEN; i++) {
		printf("BYTE = %d :  ", i);
		for(pos = 0; pos < BIT_IN_CHAR; pos++) {
			if( ( (p -> arr[i]) & (1 << pos)) != 0)
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}
