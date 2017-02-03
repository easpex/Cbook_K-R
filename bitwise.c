#include <stdio.h>

/*
01000000000000100000000000000011

{0, 1, 17, 30}
*/

void print_binary(int number);
void printSet(int n);

int main() {
	unsigned int set1 = 0;
	unsigned int set2 = 0;
	unsigned int set3 = 0;

	int x = 1;
	int position = 1;
	print_binary(set1);
	printf("\n");
	set1 ^= (-x ^ set1) & (1 << position);

	position = 3;
	set1 ^= (-x ^ set1) & (1 << position);
	set1 ^= (-x ^ set1) & (1 << position);
	print_binary(set1);
	printf("\n");


	position = 1;
	set2 ^= (-x ^ set2) & (1 << position);
	print_binary(set2);
	printf("\n");

	set3 = set1 & ~set2;
	print_binary(set3);
	printf("\n");

	printSet(set1);
	printf("\nsizeof int = %d\n", sizeof(int));
}

void print_binary(int number)
{
    if (number) {
        print_binary(number >> 1);
        putchar((number & 1) ? '1' : '0');
    }
}

void printSet(int n) {
	int pos;

	for(pos = 0; pos <= 8; pos++) {
		if( (n & (1 << pos)) != 0)
		printf("%d ", pos);
	}
	
}
