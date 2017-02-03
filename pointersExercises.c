#include <stdio.h>
#define ARR_LEN 5
int main() {
	int arr[ARR_LEN];
	int i;
	int *p = arr;

	for(i = 0; i < ARR_LEN; ++i)
		scanf("%d", arr + i);

	for(i = 0; i < ARR_LEN; ++i)
		printf("%d ", *p + i);
	printf("void = %d\n", sizeof(void *));
	printf("p[1] = %d\n", p[1]);

}