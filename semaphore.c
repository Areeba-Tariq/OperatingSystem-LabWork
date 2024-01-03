#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdlib.h>

int X1,Y1,Z1;
sem_t mutex1;
sem_t mutex2;

void* worker1(void* arg);
void* worker2(void* arg);

int main(int argc,char**argv) {
  
  sem_init(&mutex1,0,0);
  sem_init(&mutex1,0,0);
  
  int X,Y,Z,W;

  int arr[4];
  
  printf("\nEnter value of W,X,Y,Z\n");
  scanf("%d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3]);
  
  pthread_t t1,t2;
  
  pthread_create(&t1,NULL,worker1,(void*)arr);
  pthread_create(&t2,NULL,worker2,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  
    return 0;
}
void *worker1(void *args)
{
  int S1=0;
  int *arr=(int*)args;
  X1=arr[3]+2;
  sem_post(&mutex1);
  sem_wait(&mutex2);
  Y1=Z1*5;
  S1=Y1+X1;
  printf("\nWorker1%d",S1);
  sem_post(&mutex1);
}
void *worker2(void*args)
{
  int W1=0,S2=0;
  sem_wait(&mutex1);
  Z1=X1*2;
  sem_post(&mutex2);
  sem_wait(&mutex1);
  W1=Y1+5;
  S2=Z1+W1;
  printf("\nWorker 2 %d",S2);
}