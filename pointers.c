#include <stdio.h>
#include <math.h>
#define max(A, B) ((A) > (B) ? (A) : (B))
#define ARRLEN 3

int main() {
    int i = 123;
    int ind;
    int c;
    int *p = 0;
    int *p2 = 0;
    int norm1 = 77;
    int norm2 = 2;
    char **argv[3] = {"abc","def","ghi"};
    int *q;
    int qq;
    q=&norm1;
    q=534;
    qq = q;
    printf("q = %d norm1 = %d qq = %d\n", q, norm1, qq);
    p = &i;
    p2 = &norm1;
    printf("p address is: %d | p2 address = %d\n", p, p2);
    
    printf("p = %d | i = %d | p2 = %d\n", *p, i, *p2);
    
    *p = 22;
    
    printf("p = %d | i = %d | p2 = %d\n", *p, i, *p2);
    
    printf("norm1 = %d | norm2 = %d\n", norm1,  norm2);
    
    p = &norm1;

    printf("p address is: %d | p2 address = %d\n", p, p2);

    printf("p = %d | i = %d | p2 = %d\n", *p, i, *p2);
    
    printf("norm1 = %d | norm2 = %d\n", norm1,  norm2);

    (*p)++;

    printf("p = %d | i = %d | p2 = %d\n", *p, i, *p2);
    printf("norm1 = %d | norm2 = %d\n", norm1,  norm2);

    printf("-----argv----\n");

    //*++argv;
    printf("%c\n", (*++argv)[0]);
    
    return 0;
}
