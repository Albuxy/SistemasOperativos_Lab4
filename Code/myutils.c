#include "myutils.h"

struct timeval start, end;
long mtime, seconds, useconds;    

void startTimer() {
    gettimeofday(&start, NULL);
}

long endTimer() {
    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    return mtime;
}


void printCountry(country c) {
    printf("----------------------\n");
    printf("Country: %s\n",c.name);
    printf("  populat: %ld\n",c.population);
    printf("     area: %d\n",c.area);
    printf("    coast: %d\n",c.coastline);
}


int fileLockReg(int fd, int start, off_t len)
{
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = start;
    fl.l_len = len;
    return fcntl(fd, F_SETLK, &fl);
}

int fileUnLockReg(int fd, int start, off_t len)
{
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = start;
    fl.l_len = len;
    return fcntl(fd, F_SETLK, &fl);
}


