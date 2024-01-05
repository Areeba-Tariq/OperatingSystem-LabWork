#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int lap_count = 0;

void child_handler(int signum) {
    // Print lap number
    printf("Lap %d\n", lap_count++);
    alarm(5); // Set another alarm for the next lap
}

void death_handler(int signum) {
    // Print total time upon child termination
    printf("\nTotal time: %d seconds\n", lap_count * 5);
    exit(0);
}

int main() {
    pid_t pid;

    // Set up signal handlers
    signal(SIGALRM, child_handler);
    signal(SIGCHLD, death_handler);

    // Get number of laps from user
    printf("Enter the number of laps: ");
    scanf("%d", &lap_count);

    // Fork a child process
    pid = fork();

    if (pid == 0) {
        // Child process
        alarm(5); // Set an initial alarm for the first lap
        while (1) {
            pause(); // Wait for signals
        }
    } else if (pid > 0) {
        // Parent process
        wait(NULL); // Wait for the child to terminate
    } else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}
