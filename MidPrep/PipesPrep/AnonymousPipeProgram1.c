#include <stdio.h>
#include<unistd.h>

int main(void) {

  int arr[]={1,2,3};
  int Size=sizeof(arr);
  int fd[2];
  int fd1[2];
  pipe(fd);
  pipe(fd1);
  if(fork()==0)
  {
    int buffer[Size];
    int sum=0;
    close(fd[1]);
    close(fd1[0]);
    read(fd[0],&buffer,Size);
    for(int i=0;i<Size/sizeof(int);i++)
      {
        sum+=buffer[i];
      }
    write(fd1[1],&sum,sizeof(int));
  }
  else{
    int sum1=0;
    close(fd[0]);
    close(fd1[1]);
    write(fd[1],&arr,sizeof(arr));
    read(fd1[0],&sum1,sizeof(int));
    printf("In parent the sum from child is %d",sum1);
  }
  
}