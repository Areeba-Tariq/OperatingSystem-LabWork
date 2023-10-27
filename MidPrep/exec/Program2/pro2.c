#include <stdio.h>
#include <unistd.h>

int main() {

pid_t pid = getpid();
printf("Process ID after execv system call in my_info.c: %d\n", pid);

printf("Name: Areeba\n");
printf("Roll Number: \n");
printf("Semester:semester\n");

return 0;
}