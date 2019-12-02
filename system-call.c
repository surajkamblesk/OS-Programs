#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc ,char* argv[])
{
  int pid,a,b,c;
  printf("enter a and b\n");
  scanf("%d%d",&a,&b);
  printf("sum : %d\n",a+b);
 pid = fork();
 printf("%d\n",pid);
 if(pid<0)
 {
   printf("error\n");
 }
   else if(pid == 0){
     
     // execlp("ls", "ls" ,"-al", NULL);
     execl("./p1.c", "p1", NULL);
     printf("parent id = %d\t child id= %d\n",getppid(),getpid());
   }else{     

     wait(NULL);
     printf("\nchild is complete\n");
   }
 }
