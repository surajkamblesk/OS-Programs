#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc , char* argv[])
{
  int fd1;
  if((fd1 = open(argv[1],O_RDONLY)) == -1){
    printf("error opening file\n");
    exit(0);
  }
  if(unlink(argv[1]) !=0){
    printf("unable to delete\n");

  }else{
    printf("file deletion successful");
  }
}
