#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *worker(void *args)
{
  printf("\nI am thread %lu and my ProcessID %d [thread %d]",pthread_self(),getpid(),*(int*)args);
  pthread_exit(0);
}
int main()
{
  pthread_t t[5];
  for(int i=0;i<5;i++)
    {
      
      pthread_create(&t[i],NULL,worker,&i);
    }
  for(int i=0;i<5;i++)
  {
    pthread_join(t[i],NULL);
  }
  
}