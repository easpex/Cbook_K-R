#include <stdio.h>
#include <math.h>
#define ARRLEN 3

int strlen2(char *s);
void change(int arr[], int len);

int main() {
    int arr1[ARRLEN] = {'a', 'd', 'f'};
    int i;
    int *pa = 0;
    printf("sizeof(int) = %d\n", sizeof(arr1[0]));
    for(i = 0; i < ARRLEN; ++i) {
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }
    if(5) printf("if true x = %d\n", 'x');
    pa = arr1;
    /*  printf("*pa++ = %d\n", *++pa);  */
    change(arr1, ARRLEN);
    for(i = 0; i < ARRLEN; ++i) {
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }

    printf("pa address = %d | pa = %d | *(pa + 1) = %d | arr1 address = %d\n\n", pa, *pa, *(pa + 1), arr1);

    for(i = 0; i < ARRLEN; ++i) {
            printf("pa address = %d | *(pa + %d) = %d\n", pa + i, i, *(pa + i));
    }

    printf("*(arr1 + 1) = %d\n", *(arr1 +1));

    for(i = 0; i < ARRLEN; ++i) {
            printf("pa address = %d | *(a + %d) = %d\n", arr1 + i, i, *(arr1 + i));
    }

    printf("*(arr1 + 1) = %d\n", *(arr1 +1));

    for(i = 0; i < ARRLEN; ++i) {
            printf("pa address = %d | *(a + %d) = %d\n", pa + i, i, pa[i]);
    }
    printf("arr[-1] = %d\n", arr1[-1]);


    printf("strlen2(pa) = %d\n", strlen2(pa));
    return 0;
}

int strlen2(char *s) {
    int n;

    for(n = 0; *s != '\0'; s++) {
        printf("*s = %d | s = %d\n", *s, s);
        n++;
    }
    return n;
}

void change(int arr[], int len) {
    int i;
    for(i = 0; i < len; ++i) {
        arr[i] = i + 10000;
    }
    printf("changed\n");
}