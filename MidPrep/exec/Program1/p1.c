#include "stdio.h"
#include<unistd.h>
#include<stdlib.h>
int main() {
char*path="./p2";
char*argv[]={path,NULL};
  if (execv(path, argv) == -1) {
  perror("execv");
    printf("Hello im here");
  exit(EXIT_FAILURE);
  
  return 0;
}
}
