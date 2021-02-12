#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "myutils.c"

int total_pop(char* file){
	
	int fd;
    	country c;
	int num = 1;
	int size = 0;
	long population = 0;
	fd = open(file,O_RDWR);
	lseek(fd, num*sizeof(country), SEEK_SET);
	
	while(read(fd,&c,sizeof(country))>0){ 
		num++;
		lseek(fd, num*sizeof(country), SEEK_SET);
		population += c.population;
		
	}	
	printf("Sum at the end: %ld\n",population);
	return population;
}

int main(int argc, char *argv[]){
	total_pop(argv[1]);		
}


