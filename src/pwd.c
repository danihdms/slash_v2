#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

#define PATH_MAX 1024

int pwd(char *c, char *cwd) {
    if (c != NULL) {
        if (strcmp(c, "-P") == 0) {
            char resolved_path[PATH_MAX];
            if (realpath(cwd, resolved_path) == NULL)
                return 1;
            write(STDOUT_FILENO, resolved_path, strlen(resolved_path));
            write(STDOUT_FILENO, "\n", 1);
        } else {
            write(STDOUT_FILENO, cwd, strlen(cwd));
            write(STDOUT_FILENO, "\n", 1);
        }
    }
    return (0);;
}

