#include <stdio.h>
void main() {
	int c;
	
	while( (c = getchar() ) != EOF) {
		if(c == '\t') {
			putchar('\t');
		} else if(c == '\\') {
			putchar('\\\\');
		} else {
			putchar(c);
		}
	}
}


