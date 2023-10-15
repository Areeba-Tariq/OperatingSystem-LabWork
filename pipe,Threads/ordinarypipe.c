#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char*argv[]) {

  int fd[2];
  int fd1[2];
  pipe(fd);
  pipe(fd1);
  int N=atoi(argv[1]);
  if(N==0)
  {
    printf("\nPerfect No cant be zero");
    exit(1);
  }
  else if(N<0)
  {
    printf("\nPerfect Number cant be Negative");
    exit(1);
  }
  pid_t pid1,pid2;
  if((pid1=fork())==0)
  {
    //child 1
    close(fd[0]);
    int sum=0;
      for(int i=1;i<=N/4;i++)
        {
          if(N%i==0)
          {
            sum+=i;
          }
        }
    write(fd[1],&sum,sizeof(sum));
    close(fd[1]);
  }
  else
  {
    //parent
    //close(fd1[0]);
    if((pid2=fork())==0){
      close(fd1[0]);
      //child2
    int sum=0;
    for(int i=N/4+1;i<=N/2;i++)
      {
        if(N%i==0)
        {
          sum+=i;
        }
      }
      write(fd1[1],&sum,sizeof(sum));
      close(fd1[1]);
  }
    else{
      int sum1,sum2=0,status;
      //parent 
      waitpid(pid1, &status, 0);
      waitpid(pid2, &status, 0);
      
      read(fd[0],&sum1,sizeof(int));
      close(fd[0]);
      read(fd1[0],&sum2,sizeof(int));
      close(fd1[0]);
      // printf("The res of sum1 %d",sum1);
      // printf("The res of sum2 %d",sum2);
      // printf("Sum is %d",sum1+sum2);
      if(N==(sum1+sum2))
        printf("\nTrue---Its a perfect Number");
      else
        printf("\nFalse---Its not a perfect Number");
    }
    
  } 
}