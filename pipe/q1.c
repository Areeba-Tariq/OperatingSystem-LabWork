#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include<stdlib.h>
#include<ctype.h>

int main(void) {
  int fd[2];
  const char *msg="Hi There";
  int SIZE=strlen(msg);
  char rece[SIZE];
  pipe(fd);

  if(fork()==0)
    {
      close(fd[1]);
      ssize_t buff_size=read(fd[0],rece,SIZE);

      rece[buff_size]='\0';
      for(ssize_t i=0;i<buff_size;i++)
        {
          if(isupper(rece[i]))
          {
            rece[i]=tolower(rece[i]);
          }
          else if(islower(rece[i]))
          {
            rece[i]=toupper(rece[i]);
          }
        }
      printf("Here is %s",rece);
      //rece.append('\0');
      close(fd[0]);
    }
    else
  {
    close(fd[0]);
    ssize_t buff_size=write(fd[1],msg,SIZE);
    close(fd[1]);
    wait(NULL);
  }
}