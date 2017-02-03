#include <stdio.h>
#define max(a, b, c) ( (a) > (b) ) ? {( (a) > (c) ) ? (a) : (c)} : {( (b) > (c) )? (b) : (c)} 
#define absolute(a) ( (a) < 0) ? ( a * (-1) ) : (a)
#define round(a) ( ((a) - 0.4) <= 0 ? (int) (a) :  (int) ( (a) + 1))

int main() {
	int a = 1;
	int b = 4;
	int c = 9;
	printf("%f\n", 9.0 % 1.0);
}