#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fd;
	int ch;
	fpos_t p1;
	long d1;
	char buf[100];
	char path[100] = "/Users/yos/code/C/Cbook/";
	char fileName[100] = "testFileInput.txt";
	char pathToFile[200];
	char *p;
	int val;

	p = strcpy(pathToFile, path);
	p = strcat(pathToFile, fileName);

	printf("pathToFile = %s\n", pathToFile);
	
	if(!(fd = fopen(pathToFile, "r+"))) {
		printf("cannot open file: %s\n", pathToFile);
		fprintf(stderr, "cannot open file: %s\n", pathToFile);
		exit(0);
	}

	printf("\nfile opened successfully\n");

	/* read file char by char */
	while(!feof(fd)) {
		ch = fgetc(fd);
		printf("%c", ch);
	}

	rewind(fd);
	puts("\n--------------");

	while( (ch = fgetc(fd)) != '\n')
		;
	fgetpos(fd, &p1); /* get the current position of a file */

	do {
		ch = fgetc(fd);
		putchar(ch);
	} while(ch != '\n' && ch != EOF);
	puts("\n--------------");

	fsetpos(fd, &p1); /* set fd to p1 position */

	do {
		ch = fgetc(fd);
		putchar(ch);
	} while(ch != '\n' && ch != EOF);
	puts("\n--------------");

	d1 = ftell(fd); /* the distance in bytes from the begnning of the file to the currect position */
	printf("d1 = %ld\n", d1);

	rewind(fd);

	val = fseek(fd, d1, SEEK_SET);

	while(!feof(fd)) {
		ch = fgetc(fd);
		printf("%c", ch);
	}

	printf("val = %d\n", val);
	puts("\n--------------");
	rewind(fd);

	fgets(buf, 100, fd);
	puts(buf);
	printf("strlen(buf) = %ld\n", strlen(buf));

	fseek(fd, 0, SEEK_END); /* jump to end of file */
	fputs(buf, fd);
	rewind(fd);
	puts("\n--------------");
	while(!feof(fd)) {
		ch = fgetc(fd);
		printf("%c", ch);
	}
	puts("\n--------------");



	
	return 0;
}
