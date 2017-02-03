#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/file.h>
#include <sys/syscall.h>

int main() {
	int fd;
	fd = open("/Users/yos/code/C/Cbook/testFileInput.txt", O_RDWR, 0755);

	printf("fd = %d\n", fd);
	putchar('\n');

	putchar('\n');
	close(fd);
	
}
