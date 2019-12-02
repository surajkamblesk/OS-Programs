#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(int argc, char *argv[])
{
    printf("Inside main\n");
    int res=1;
    pid_t pid=fork();
//parent and child start execution from the next instruction
    if(pid<0)
    {
        printf("Error generated\n");
    }
    if(pid==0)
    {
        printf("Inside child proces,PID=%d\n",getpid());
        execl("./encrypt","encry",argv[1],argv[2],NULL);//second arg is just a reference name
    }
    else{
        printf("Inside parent process ID =%d\n",getpid());
        wait(&res);
        if(WIFEXITED(res)==1)
        {
            printf("Terminates normally\n");
        }
        else{
        printf("AbNormal termination");
        exit(0);
        }

    }
}
