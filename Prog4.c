#include <pthread.h>
#include<stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#define SIZE 3
int count=1,a[10],k=0;;
sem_t full, empty;
pthread_mutex_t mutex;
pthread_t tidP[10],tidC[10];
void initialise()
{
  pthread_mutex_init(&mutex,NULL);
  sem_init(&full,1,0);//shared between processes not threads, 0 means thread
  sem_init(&empty,1,SIZE);
  count=1;
}
void writer(int item)
{
  a[k++]=item;
}
void *producer(void *param)
{
  int item=count++;
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);
  writer(item);
  pthread_mutex_unlock(&mutex);
  printf("Item %d added\n",item );

  sem_post(&full);
  pthread_exit(0);
}
int reader()
{
  return a[k--];
}
void *consumer(void *param)
{
  int item;
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  item=reader();
  printf("Item %d removed\n",item );
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
  pthread_exit(0);
}
void main()
{
  int n1,n2,i;
  initialise();
  printf("Enter number of producers \n");
scanf("%d",&n1);
printf("Enter number of consumers \n");

scanf("%d",&n2);


for(i=0;i<n1;i++)
{
pthread_create(&tidP[i],NULL,producer,NULL);
//printf(" \n\nCreated.Producer..\n\n\n");

}
for(i=0;i<n2;i++)
{
pthread_create(&tidC[i],NULL,consumer,NULL);
//printf(" \n\nCreated.Consumers..\n\n\n");
}
for(i=0;i<n1;i++)
{
pthread_join(tidP[i],NULL);
}
for(i=0;i<n2;i++)
{
pthread_join(tidC[i],NULL);

}
exit(0);
}
