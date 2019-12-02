#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc , char* argv[])
{
  int fd1,fd2,n;
  char buf[n];
  if((fd1 = open(argv[1],O_RDONLY))==-1){
    printf("error opening the file\n");
    exit(0);

  }

  if((fd2 = open(argv[2],O_WRONLY,666)) == -1)
  {
    printf("error opening destination file");
    exit(0);
  }

  while((n = read(fd1,buf,20)) != 0)
  write(fd2,buf,n);
  close(fd1);
  close(fd2);
  return 0;
}
