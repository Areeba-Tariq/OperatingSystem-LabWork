#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h> 

int main() 
{ 
    int file_desc = open("a.txt",O_WRONLY | O_APPEND); 

    // here the newfd is the file descriptor of stdout (i.e. 1) 
    dup2(file_desc, 1) ;  

  //dup2 system call duplicates one file descriptor to another---This line says, "Make the file descriptor file_desc a copy of file descriptor 1 (which is stdout)."
  
    // All the printf statements will be written in the file 
    // "tricky.txt" 
    printf("Operating System\n"); 

return 0; 
} 