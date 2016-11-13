#include <stdio.h>
#define LEN 5

void test(int arr[], int a);
void printArr(int arr[], int len);

int main() {
    int arr[LEN];
    int i;

    
    for(i = 0; i < LEN; ++i) {
        arr[i] = i;
    }
    
    printArr(arr, LEN);
    
    test(arr, 555);

    printArr(arr, LEN);

    return 0;
}

void test(int arr[], int a) {
    arr[0] = a;
}

void printArr(int arr[], int len) {
    printf("\nprintArr below\n");
    int i;
    for(i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("end of printArr\n");
    
}