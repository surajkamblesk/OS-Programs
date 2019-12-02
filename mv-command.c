#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc , char* argv[])
{
  int fd1,fd2,n;
  char buf[n];
  if(( fd1 = open(argv[1],O_RDONLY)) == -1){
    perror("file opening error");
    exit(0);
  }

  if(( fd2 = open(argv[2],O_RDWR,666)) == -1){
   fd2 = open(argv[2],O_CREAT);

 }

while(( n = read(fd1,buf,20)) != 0)
write(fd2,buf,n);
if(unlink(argv[1]) != 0){
  printf("unlink error");
}else{
  printf("move successful\n");
}
close(fd1);
close(fd2);
  return 0;
}
