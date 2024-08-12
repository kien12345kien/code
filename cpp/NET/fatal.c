// fatal.c
#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

void fatal(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}
