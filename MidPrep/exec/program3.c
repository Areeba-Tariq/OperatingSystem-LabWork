#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
pid_t pid1, pid2, pid3, pid4;
int status;

pid1 = fork();
if (pid1 == 0) {
execlp("mkdir", "mkdir", "demo_folder",

NULL);

perror("Error executing mkdir");
_exit(1);

} else {
wait(NULL);
}
pid2 = fork();
if (pid2 == 0) {
char* args[] = {"touch",

"demo_folder/file1.txt", "demo_folder/file2.txt",
NULL};

execvp("touch", args);
perror("Error executing touch");
_exit(1);
} else {
wait(NULL);
}
pid3 = fork();
if (pid3 == 0) {
char* args[] = {"ls", "demo_folder", NULL};
execvp("ls", args);
perror("Error executing ls");
_exit(1);
} else {
wait(NULL);
}
pid4 = fork();
if (pid4 == 0) {
char* args[] = {"rm", "-rf", "demo_folder",

NULL};

execvp("rm", args);
perror("Error executing rm");

_exit(1);
} else {
wait(NULL);
}

return 0;
}