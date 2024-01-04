#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
  char*msg="hITHERE";
  int size=strlen(msg);
  int fd[2];
  pipe(fd);
  pid_t cid=fork();
  if(cid>0)
  {
    close(fd[0]);
    write(fd[1],msg,size);
    
  }
  else
  {
    close(fd[1]);
    char msg1[size];
    read(fd[0],msg1,size);
    for(int i=0;i<size;i++)
      {
        if(msg1[i]>=97 && msg[i]<=122)
        {
          msg1[i]=msg1[i]-32;
        }
        else
          msg1[i]+=32;
      }
    for(int i=0;i<size;i++)
      {
        printf("%c",msg1[i]);
      }
  }
}
