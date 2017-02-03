#include <stdio.h>
int func();
int sum(int a, int (* f)());

int main() {
	int arr[] = {0,2,4};
	int *p = arr;
	int x;
	x = sum(3, func);
	printf("x = %d\n", x);
	printf("%d\n", *p++);



}

int func() {
	return 5;
}

int sum(int a, int (* f)()) {
	return a+f();
}