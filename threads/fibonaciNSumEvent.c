#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<fcntl.h>
#include<unistd.h>

void *fiboGenerator(void *args) {
    int a1 = 0, a3 = 0, a2 = 1;
    int n = *(int *)args;
    int *arr = malloc(50 * sizeof(int)); 
    arr[0] = 0, arr[1] = 1;

    for (int i = 2; a2 < n; i++) {
        a3 = a1 + a2;
        a1 = a2;
        a2 = a3;
        arr[i] = a3;
    }
 
    pthread_exit(arr); 
}
void *countEven(void *args){
  int* series=(int*)args;
  int *even=malloc(sizeof(int));
  *even=0;
  for(int i=0;series[i]!=-1;i++)
    {
      if(series[i]%2==0)
      {
        // printf("%d",series[i]);
        (*even)++;
      }
    }
  pthread_exit(even);
}
int main(int argc, char *argv[]) {
  int count=0;
    int n = atoi(argv[1]);
    int *fibo;

    pthread_t t;
    pthread_create(&t, NULL, fiboGenerator, &n);
    pthread_join(t, (void **)&fibo);
  printf("Thread ID %lu \n",pthread_self());
  int arr[50];
  int i=0;
    for ( i = 0; fibo[i] < n; i++) {
      count++;
      arr[i]=fibo[i];
        printf(" %d, ", fibo[i]);
    }
  arr[i]=-1;
  pthread_t t1;
  int *evenCount=0;
  pthread_create(&t1,NULL,countEven,(void*)arr);
  pthread_join(t1,(void**)&evenCount);
  printf("\nThe thread ID for even %d",pthread_self());
  printf("\nThe Even Count is %d",*evenCount);
    return 0;
  int fd=open("sum.txt",O_WRONLY);
  int sum=5;
  
}
