#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>   
#include <sys/types.h>
#include <sys/stat.h>
#define SIZE 10
void main(int argc,char*argv[])
{
  char buf[SIZE];
  printf("1 to copy, 2 to move, 3 to remove\n" );
  int ch;
  int r;
  scanf("%d",&ch );
  switch (ch) {
    case 1:{
      int fd1=open(argv[1],O_RDONLY,0777);
      int fd2=open(argv[2],O_CREAT|O_WRONLY,0777);
      while((r=read(fd1,buf,SIZE))>0)
      {
        write(fd2,buf,r);
      }
      close(fd1);
      close(fd2);
    }break;
    case 2:{
      link(argv[1],argv[2]);
      unlink(argv[1]);
    }break;
    case 3: unlink(argv[1]);
  }

}
