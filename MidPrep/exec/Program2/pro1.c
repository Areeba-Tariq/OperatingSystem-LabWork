#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

pid_t pid = getpid();
printf("Process ID before calling the execv system call execv: %d\n", pid);

char *Path = "./c2";

char *args[] = {Path, NULL};
if (execv(Path, args) == -1) {
perror("execv");
exit(EXIT_FAILURE);
}

return 0;
}