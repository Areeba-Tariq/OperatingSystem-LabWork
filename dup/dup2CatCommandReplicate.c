#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h> 

int main(int argc,char*argv[])
{
      
  int ofd=open("a.txt",O_RDONLY);
  char fileRead[500];
  int status=read(ofd,fileRead,sizeof(fileRead));
  char data[status];
  fileRead[status]='\0';
  for(int i=0;i<status;i++)
    {
      data[i]=fileRead[i];
    }
  int newfd=open("output.txt",O_WRONLY);
  dup2(newfd,1);
 
  write(1,data,sizeof(data));
  
}