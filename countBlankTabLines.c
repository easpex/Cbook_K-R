
#include <stdio.h>

double c;
double nc = 0;

void main() {
	while( (c = getchar()) != EOF) {
		if(c == '\t') {
			++nc;
		} else if(c == '\n') {
			++nc;
		} else if(c == '\0') {
			++nc;
		} else {
			printf("char\n");
		}
	} //end of while
	printf("%.0f\n", nc);
}