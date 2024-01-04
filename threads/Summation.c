#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *worker(void *args)
{
  int *sum=malloc(sizeof(int));
  int n=*(int*)args;
  *sum=0;
  for(int i=1;i<=n;i++)
    {
      *sum+=i;
    }
  pthread_exit(sum);
}
int main()
{
int *sum;
  int N=5;
  pthread_t t;
  pthread_create(&t,NULL,worker,&N);
  pthread_join(t,(void**)&sum);
  printf("The sum %d ",*sum);
}