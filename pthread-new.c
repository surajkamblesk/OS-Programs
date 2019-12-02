#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int sum = 0;
void* add(void* arg);

int main(int argc , char* argv[])
{
  pthread_t t1;
  pthread_create(&t1,NULL,add,argv[1]);
  pthread_join(t1,NULL);
  printf("sum = %d\n",sum);
  pthread_exit(0);
}
void *add(void* arg)
{
  int i, n = atoi(arg);
  for(i=0;i<n;i++)
  {
    sum = sum + i;
  }
  pthread_exit(0);
}
