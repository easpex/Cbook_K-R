#include <stdio.h>
#define MAXLINE 1000

int getlineCo(char s[], int lim);
void copy(char to[], char from[]);

int main() {
	printf("in main\n");
	int len;
	int max;
	int i;
	char line[MAXLINE];
	char longest[MAXLINE];
	printf("before while\n");
	//printf("%d", getlineCo(line, MAXLINE));
		max = 0;
	while( (len = getlineCo(line, MAXLINE)) > 0) {
		printf("inside while");
			copy(longest, line);
			for(i = 0; i < len; ++i) {
				printf("%c", longest[len - i - 1]);
			}
			printf("\n");

	}
	return 0;
}



int getlineCo(char s[], int lim) {
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
	
}

void copy(char to[], char from[]) {
	int i;

	i = 0;
	while( (to[i] = from[i]) != '\0')
		++i;
}
