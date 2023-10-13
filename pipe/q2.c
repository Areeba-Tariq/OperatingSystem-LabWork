#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include<stdlib.h>
#include<ctype.h>

int main(void) {
  int fd[2];
  int fd1[2];
  int intarr[4]={1,2,3,4};
  //int SIZE = sizeof(int)*4;
  int rece[4];
  int sum1;
  pipe(fd);
  pipe(fd1);

  if(fork()==0)
    {
      close(fd[1]);
      close(fd1[0]);
      ssize_t buff_size=read(fd[0],rece,sizeof(rece));
      int sum=0;
      for(ssize_t i=0;i<buff_size/sizeof(int);i++)
        {
          sum+=rece[i];
        }
      buff_size=write(fd1[1],&sum,sizeof(sum));
      close(fd[0]);
      close(fd1[1]);
    }
    else
  {
    close(fd[0]);
    close(fd1[1]);
    ssize_t buff_size=write(fd[1],intarr,sizeof(intarr));
    close(fd[1]);
    wait(NULL);
    read(fd1[0],&sum1,sizeof(sum1));
    printf("hello %d",sum1);
    close(fd1[0]);
  }
}