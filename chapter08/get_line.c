#include <stdio.h>

#include "get_line.h"

void get_line(char *buffer, int size)
{
    if ( fgets(buffer, size, stdin) == NULL ) {
        buffer[0] = '\0';
        return;
    }

    for (int i = 0; i < size; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            return;
        }
    }
}
