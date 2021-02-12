#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "myutils.c"

int main(int argc, char *argv[]){
	
	int fd;
        country c;
	int n = atoi(argv[1]);
	int num2 = 0;
	fd = open(argv[2],O_RDWR);

	lseek(fd, n*sizeof(country), SEEK_SET);
	read(fd,&c,sizeof(country));
	printCountry(c);
}
