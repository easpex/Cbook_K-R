#include <stdio.h>
#define ARR_LEN 5

void printArr(int arr[], int len);

int main() {
    int y[ARR_LEN] = {0};
    int x = 1;
    
    if(1 == x++) {
        printf("1 == x++\n");
    }
    
    y[++x] = 100;
    printArr(y, ARR_LEN);
    printf("x = %d\n", x);
    
    //y = ++x;
    //printf("y = %d\n", x);
    return 0;
}

void printArr(int arr[], int len) {
    int i;
    
    for(i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
