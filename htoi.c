#include <stdio.h>
#define LEN 50
#define TRUE 1
#define FALSE 0
#define SIXTEEN 16
#define BAD_NUM -1

int htoi(char s[]);
int intLookup(char c);
void printArr(int arr[], int length);
int power(int base, int n);

int main() {
	char test[4];
	test[0] = '7';
	test[1] = 'f';
	test[2] = 'e';
	test[3] = '5';


	htoi(test);
}

int htoi(char s[]) {
	int i, j, k, length, sum = 0;
	int hex[LEN];

	/* check if the hex number starts with '0x' or '0X' */
	if(s[0] == 0 && (s[1] == 'x' || s[1] == 'X') ) {
		i = 2;
	} else {
		i = 0;
	}
	
	for(i = i, j = 0; (hex[j] = intLookup(s[i]) ) != BAD_NUM ; ++i, ++j)
		;//hex[j] = intLookup(s[i]); /* look up the decimal value of hex input */
		/*  printf("i = %d | j = %d\n", i, j); */
	
	
	//(s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F')

	length = j; 

	for(i = 0; i < length; ++i) {
		sum = sum + (hex[length - i - 1] * power(SIXTEEN, i) ); /* convert */
	}

	printf("sum = %d\n", sum);
	return sum;
}

int intLookup(char c) {
	int result;
	if(c >= 'a' && c <= 'f') {
		result = c - 87;
	} else if(c >= 'A' && c <= 'F') {
		result = c - 55;
	} else if(c >= '0' && c <= '9'){
		result = c - '0';
	} else {
		printf("illegal number");
		return BAD_NUM;
	}
	printf("result = %d\n", result);
	return result;
}

void printArr(int arr[], int length) {
	int i;
	for(i = 0; i < length; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int power(int base, int n) {
	if(n == 1) {
		return base;
	}
	if(n == 0) {
		return 1;
	}
	return(base * power(base, n - 1));
}
