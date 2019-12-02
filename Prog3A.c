#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include<unistd.h>

void main(int argc,char* argv[])
{
  pid_t pid;
  if(argc==2)
  pid=atoi(argv[1]);
  else
  pid=getpid();
  printf("Process iD=%d\n",pid );
  int c;

  for(int i=-20;i<20;i+=2){
  int a=getpriority(PRIO_PROCESS,pid);
  int b=setpriority(PRIO_PROCESS,pid,i);
  if(b==0)
  c=getpriority(PRIO_PROCESS,pid);

  printf("%d\t%d\t%d\n",a,i,c );

  }
}
