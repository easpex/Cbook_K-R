#include <stdio.h>

int power(int base, int n) {
	if(n == 1) {
		return base;
	}
	return(base * power(base, n - 1));
}

void main() {
	printf("power = %d", power(2,5));
}