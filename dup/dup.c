#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open a file for reading
    int original_fd = open("example.txt", O_RDONLY);

    if (original_fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    int duplicated_fd = dup(original_fd);

    if (duplicated_fd == -1) {
        perror("Error duplicating file descriptor");
        close(original_fd);  
        return 1;
    }

    char buffer_original[100];
    ssize_t bytes_read_original = read(original_fd, buffer_original, sizeof(buffer_original));

    // Set the file offset for the duplicated file descriptor
    lseek(duplicated_fd, 0, SEEK_SET);

    char buffer_duplicated[100];
    ssize_t bytes_read_duplicated = read(duplicated_fd, buffer_duplicated, sizeof(buffer_duplicated));

   printf("Original Content: ");
    for (ssize_t i = 0; i < bytes_read_original; i++) {
        printf("%c", buffer_original[i]);
    }
    printf("\n");

    printf("Duplicated Content: ");
    for (ssize_t i = 0; i < bytes_read_duplicated; i++) {
        printf("%c", buffer_duplicated[i]);
    }
    printf("\n");
    close(original_fd);
    close(duplicated_fd);

    return 0;
}
