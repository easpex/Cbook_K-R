#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define max(A, B) ((A) > (B) ? (A) : (B))
#define ARRLEN 5
int main() {
 
    char a[10];
    int num = 5;
    itoa(num, a, 10);
    printf("itoa(5) = %s", a);
    return 0;
}
