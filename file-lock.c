#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc , char* argv[])
{
	char *file = argv[1];
	int fd;
	struct flock lock;
	printf("opening file\n");
	fd = open(argv[1],O_WRONLY);
	fd = open("a.txt",O_RDWR | O_EXCL);
	printf("locking the file");
	memset(&lock,0,sizeof(lock));
	lock.l_type = F_WRLCK;
	fcntl(fd,F_SETLKW,&lock);
	printf("file has been locked , press enter to unlock\n");
	getchar();
	printf("releasing lock\n");
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLKW,&lock);
	close(fd);
}