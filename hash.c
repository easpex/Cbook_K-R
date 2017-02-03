#include <stdio.h>
#define HASHSIZE 101
unsigned int hashy(char *s);

int main() {
	char * s = "hello";
	printf("%d\n", hashy(s));
}

unsigned int hashy(char *s) {
	unsigned int hashval;

	for(hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
		printf("printf 2  sc = %c | sd = %d | hashval = %d\n", *s, *s, hashval);
	}
	return hashval % HASHSIZE;
}
