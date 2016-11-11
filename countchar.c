#include <stdio.h>

main() {

double nc;

//this version will count \n as char as well
for(nc = 0; getchar() != EOF; ++nc)
	;
printf("%.0f\n", nc);

//this version will not count \n char
/*
while( (nc = getchar()) != EOF) {
	if(nc != '\n') {
		++nc;
	}
}
*/

}