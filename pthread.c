#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int sum = 0;
void *add(void* arg);
int main(int argc , char *argv[])
{
  pthread_t t1;
  pthread_create(&t1,NULL,add,argv[1]);
  pthread_join(t1,NULL);
  printf("sum = %d ", sum);
  pthread_exit(0);
}

void *add(void* arg)
{
  int i;
  int n;
  n = atoi(arg);
  for(i=1;i<n;i++)
  sum+=i;
  pthread_exit(0);
}
