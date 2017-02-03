#include <stdio.h>
#define ARRLEN 5

void strcopy2(char *s, char *t);
void printArr(char *p);
void swap(char *a, char *b);
void change(char arr[]);

int main() {
	
	char s[ARRLEN];
	char t[ARRLEN] = {'a', 'b', 'c', 'd', '\0'};
	char x = 150;
	char y = 'b';
	printf("xd = %d | xc = %u\n", x, x);
	printf("s address = %d | t address = %d\n\n", s, t);

	strcopy2(s, t);
	printf("t = %s | s = %s\n", t, s);
	printf("s address = %d | t address = %d\n\n", s, t);
	printArr(s);
	printf("strlen = %d\n", strlen(s));

	printf("\nswap\n");
	swap(&s[0], &s[1]);
	printArr(s);

	change(s);
	printArr(s);

	return 0;
}

void strcopy2(char *s, char *t) {
	while( (*s++ = *t++) != '\0') {
		printf("*s = %d | *t = %d | s address = %d | t address = %d\n", *(s-1), *(t-1), s - 1, t - 1);
	}
}

void printArr(char *p) {
	while(*p != '\0') {
		printf("%c ", *p++);
	}
	printf("\n\n");
}

void swap(char *a, char *b) {
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void change(char arr[]) {
	arr[0] = 'z';
}

void test() {
	printf("I'm test()\n");
}