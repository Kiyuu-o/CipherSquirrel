#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <stdio.h>

#define CHUNK_SIZE 4096

size_t read_chunk(void *ptr, FILE *stream);
size_t write_chunk(const void *ptr, size_t size, FILE *stream);

#endif