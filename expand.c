#include <stdio.h>
#define MAX_LEN 100
#define ATOI_GAP 48  /* z char literal value is 74. z is the 26-th letter of the alphabet. 74 - 26 = 48
which is the number that indicates a char position in English alphabet */

void expand(char s1[], char s2[]);

int main() {
    int i;
    char s2[MAX_LEN]; /* initialize the target array */
    char s1[4]; /* initialize the source array */
    s1[0] = 'a';
    s1[1] = '-';
    s1[2] = 'z';
    s1[3] = '\0';
    
    for(i = 0; i < MAX_LEN; ++i) {  /* print s2 array */
        printf("%d ", s2[i]);
    }
    
    expand(s1, s2);

    for(i = 0; s2[i] != '\0'; ++i) {  /* print s2 array */
        printf("%c ", s2[i]);
    }
    
    return 0;
}

/* the function will take a string s1 in the format "letter-letter" 
and fill the consequent letters in between
instead of "-" in the string s2 */
void expand(char s1[], char s2[]) {
    int start = s2[0] = s1[0]; /* the first letter of the array s2 is the same as that of the array s1 */
    int stop = s1[2]; /* determine at which letter we need to stop */
    int j;
    printf("inside expand");
    
    for(j = 1; j < stop - '0' - ATOI_GAP; ++j) {
        s2[j] = ++start; /* fill in the gap */
    }
    s2[j] = '\0'; 
    printf("finished expand");
    
}

/*
 void printArr(char arr[]) {
	int i;
 printf("inside printArr");
 for(i = 0; arr[i] != '\0'; ++i) {
 printf("%c ", arr[i]);
 }
 printf("\n");
 }
 */
