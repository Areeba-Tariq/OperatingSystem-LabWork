#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc , char*argv[]) {
if(argc!=2){
perror("Exit_Failure");
}
char* filename= argv[1];
int fd = open(filename,O_RDONLY);
int fd2= dup2(fd,0);
char data[500];
int status=read(0,data,sizeof(data));
char ndata[status];
for(int i=0;i<status;i++){
ndata[i]=data[i];
}
int fd3= open("output.txt",O_WRONLY);
int fd33=dup2(fd3,1);
write(1,ndata,sizeof(ndata));
return 0;
}