void * consumer(void *arg)
{
  sem_wait(&full);
  pthread_mutext_lock(&mutex);
  item=a[k--];
  print item
  pthread_mutex_unlock(&mutex);
  sem_wait(&empty);
}

void *producer(void *arg)
{
  sem_wait(&empty);
  pthread_mutext_lock(&mutex);
  a[k++]=item
  print item
  pthread_mutex_unlock(&mutex);
  sem_wait(&full);
  
}
