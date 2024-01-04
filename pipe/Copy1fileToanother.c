#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char*argv[])
{
  int fd[2];
  pipe(fd);
  pid_t cid=fork();
  if(cid>0)
  {
    //parent
    close(fd[0]);
    char buffer[50];
    int fd1=open(argv[1],O_RDONLY);
    int readBytes=read(fd1,buffer,sizeof(buffer));
    buffer[readBytes]='\0';
    printf("%s",buffer);
    write(fd[1],buffer,readBytes);
    // for(int i=0;i<readBytes;i++)
    //   {
    //     printf("%c",buffer[i]);
    //   }
    wait(NULL);
  }
  else
  {
    close(fd[1]);
    char buffer[500];
    int readBytes=read(fd[0],buffer,sizeof(buffer));
    buffer[readBytes]='\0';
    printf("\nIn child %s",buffer);
    int fd2=open(argv[2],O_WRONLY);
    char buffer1[readBytes];
    for(int i=0;i<readBytes;i++)
      {
        buffer1[i]=buffer[i];
      }
    write(fd2,buffer1,sizeof(buffer1));
  }
}