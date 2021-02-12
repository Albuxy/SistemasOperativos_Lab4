#ifndef MYUTILS
#define MYUTILS

#include <sys/time.h>
#include <unistd.h>     // unix-like system calls read and write
#include <fcntl.h>      // unix-like file handling : open
#include <stdio.h>      // standard C lib input output basic functions compatible with Windows
#include <string.h>     // also from standard C lib : basic string functions like strlen
#include <fcntl.h>

typedef struct country_struct {
	char name[30];
	long population;
	int area;	
	int coastline;
} country;

void startTimer();   // start timer
long endTimer();     // returns millis since startTimer

void printCountry(country c);

int fileLockReg(int fd, int start, off_t len);
int fileUnLockReg(int fd, int start, off_t len);


#endif