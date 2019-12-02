#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
int rc=0;
sem_t rd, wt;
void *reader(void *par)
{
  //sleep(1);
  int i = (int)par;
  printf("Reader %d wants to read.\n", i);
  sem_wait(&rd);
  rc++;

  if(rc==1)
  {  sem_wait(&wt);
  }
  //sem_post(&rd);
  printf("Reader %d is reading.\n", i);
  //sem_wait(&rd);

  rc--;

  printf("Reader %d left.\n",i);
  if(rc==0)
  {
    sem_post(&wt);
  }

  sem_post(&rd);
}


void *writer(void *par)
{
  int i = (int)par;
  printf("Writer %d wants to write.\n", i);
  sem_wait(&wt);
  printf("Writer %d is writing.\n", i);
  printf("Writer %d is done.\n", i);
  sem_post(&wt);
}
int main()
{
  int i,j;
  sem_init(&rd,0,1);
  sem_init(&wt,0,1);
  pthread_t r[100], w[100];
  int nr = 5, nw = 5;
  for(i=0;i<5;i++)
  {
    pthread_create(&r[i], NULL, reader,(void *)i);
  }
  for(i=0;i<5;i++)
  {
    pthread_create(&w[i], NULL, writer,(void *)i);
  }
  for(i=0;i<5;i++)
  {
    pthread_join(r[i], NULL);
  }
  for(i=0;i<5;i++)
  {
    pthread_join(w[i], NULL);
  }
  return 0;
}
