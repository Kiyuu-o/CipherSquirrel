#include <stdio.h>
#include "../src/file_handling.h"

int main() {

#ifndef FILE_HANDLING_H
    puts("file_handling.h is not included");
    return 0;
#endif

    unsigned char buffer[CHUNK_SIZE+1];

    FILE *file = fopen("./tests/in.txt", "rb");
    FILE *dest = fopen("./tests/out.txt", "wb");
    if (file == NULL) {
        perror("The following error occurred");
    }
    if (dest == NULL) {
        perror("The following error occurred");
    }

    size_t bytes_read = read_chunk(buffer, file);
    // buffer[bytes_read] = '\0';
    // printf("%s\n", buffer);
    write_chunk(buffer, bytes_read, dest);
    fclose(file);
    return 0;
}