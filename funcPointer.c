#include <stdio.h>

int max(int a, int b);

int main() {
	int (*p) (int a, int b);
	p = max;

	printf("p = %d\n", p(222,34));
}

int max(int a, int b) {
	return (a < b) ? b : a;
}
