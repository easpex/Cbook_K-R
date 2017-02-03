#include <stdio.h>
#include <stdlib.h> /* need this for malloc */

int main(int argc, char* argv[]) 
{      
    char arr[][3] = {"abc", "def", "ghi"};
    char* bogus_argv[] = {"abc", "def", "ghi"};

    int **p;
    int k, j, l = 0;
    char **q = bogus_argv;

    p = (int **)malloc(3 * sizeof(int *));
    for(k = 0; k < 3; ++k) {
        p[k] = (int *)malloc(4 * sizeof(int));
    }

    for(k = 0; k < 3; ++k) {
        for(j = 0; j < 4; ++j) {
            p[k][j] = l*2;
            printf("%d ", p[k][j]);
            l++;
        }
        printf("\n");
    }


    printf("argv:     %d\n", argv);
    printf("&argv[0]: %d\n", &argv[0]);
    printf("&argv:    %d\n\n", &argv);

    
    printf("bogus_argv:     %d\n", bogus_argv);
    printf("&bogus_argv[0]: %d\n", &bogus_argv[0]);
    printf("&bogus_argv:    %d\n\n", &bogus_argv);

    printf("%c\n", (*++argv)[1]);  // prints 'b'
    printf("%c\n\n", *++argv[1]);    // prints 'e'

    printf("q = %c\n\n", *(*(q + 1) + 1));

    printf("%d\n", *(*(p+1) + 2));
    free(p);
    return 0;
}