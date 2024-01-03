#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

void *Sum(void * N)
{
  int sum=0;
  long No=(long)N;
  for(int i=0;i<=No;i++)
    {
      sum+=i;
    }
  printf("\nThe sum is %d",sum);
  return NULL;
}
int main()
{
  pthread_t tid;
  long N=5;
  int rc=pthread_create(&tid,NULL,Sum,(void*)N);
  pthread_join(tid,NULL);
}