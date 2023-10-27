#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char arr[] = "HI there";
    int Size = sizeof(arr);
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);
        char arr1[Size];
        ssize_t readBytes = read(fd[0], arr1, Size);
        for (ssize_t i = 0; i < readBytes; i++) {
            if (isupper(arr1[i])) {
                arr1[i] = tolower(arr1[i]);
            } else {
                arr1[i] = toupper(arr1[i]);
            }
        }
        printf("\n hi there");
        printf("The result is %s\n", arr1);
    } else {
        close(fd[0]);
        write(fd[1], &arr, sizeof(arr));
    }

    return 0;
}
