#include <stdio.h>

int strindex(char s[], char t[]);

int main() {

	char s1[] = "abccce";
	char s2[] = "ce";
	int result;

	result = strindex(s1, s2);

	printf("the result = %d\n", result);

	return 0;
}

int strindex(char s[], char t[]) {
	int i, j, k;

	for(i = 0; s[i] != '\0'; ++i) {
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
			printf("i = %d | j = %d | k = %d\n", i, j, k);
		}

		if(k > 0 && t[k] == '\0') {
			return i;
		}
	}
	return -1;
}
