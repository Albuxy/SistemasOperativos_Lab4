#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "myutils.c"
#include <time.h>

int CalcNumCountry(char* file){
	
	FILE* fd;
    	country c;
	int num = 1;
	fd = fopen(file,"r+");
	lseek(fileno(fd), num*sizeof(country), SEEK_SET);

	while(read(fileno(fd),&c,sizeof(country))>0){ 
		num++;
		lseek(fileno(fd), num*sizeof(country), SEEK_SET);
		
	}	
	num = num - 1;
	fclose(fd);
	return num;
}

long sum_pop(int num_c,char* file,int num_countries){
	FILE* fd;
	int rand_country;
	long population = 0;
	country c;
	fd = fopen(file,"r+");		
	srand(time(NULL));
	read(fileno(fd),&c,sizeof(country));
	read(fileno(fd),&c,sizeof(country));
	for(int i = 0; i < num_c; i++){

		rand_country = (rand()%num_countries)+1;
		fileLockReg(fileno(fd),rand_country*sizeof(country),sizeof(country));
		lseek(fileno(fd), rand_country*sizeof(country), SEEK_SET);
		read(fileno(fd),&c,sizeof(country));		
		population += c.population;
		fileUnLockReg(fileno(fd),rand_country*sizeof(country),sizeof(country));
	
	}	
	fclose(fd);
	return population;
}

int main(int argc, char *argv[]){
	long population = sum_pop(atoi(argv[1]),argv[2],CalcNumCountry(argv[2]));
	printf("Final population after sum_pop: %ld\n",population);	
}
