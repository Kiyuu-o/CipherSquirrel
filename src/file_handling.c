#include "file_handling.h"

size_t read_chunk(void *ptr, FILE *stream) {
    size_t bytes_read = fread(ptr, 1, CHUNK_SIZE, stream);
    if (bytes_read < CHUNK_SIZE) {
        if (feof(stream)) {
            puts("End-of-File reached.");
            printf ("Total number of bytes read: %lu\n", bytes_read);
        }
        else perror("The following error occurred");
    }
    return bytes_read;
}

size_t write_chunk(const void *ptr, size_t size, FILE *stream) {
    size_t bytes_written = fwrite(ptr, 1, size, stream);
    if (bytes_written < size) {
        perror("The following error occurred");
    }
    return bytes_written;
}