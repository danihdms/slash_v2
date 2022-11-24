#include <stdio.h> // Needed for readline library
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include "shell.h"

int     main()
{
    char *line = NULL;
    char **args;
    rl_outstream = stderr;
    strcpy(owd, getenv("PWD"));
    strcpy(cwd, getenv("PWD"));
    update_prompt(prompt, cwd);

    while ((line = readline(prompt))) {
        // {"name", "arg1", "arg2", ..., NULL}
        args = split(line, ' ');
        if (args == NULL) {
            // TODO: Handle error
            status = 1;
            break;
        }

        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                if (args[1])
                    return (atoi(args[1]));
                else
                    return (status);
            } else if (strcmp(args[0], "cd") == 0) {
                status = cd(args, cwd, owd, dest);
                update_prompt(prompt, cwd);
            } else if (strcmp(args[0], "pwd") == 0) {
                status = pwd(get_pwd_adds(args + 1), cwd);
            } else {
                // TODO: Handle other commands
            }
        }

        free(line), line = NULL;
        args = bigfree(args);
    }

    free(line);
    bigfree(args);

    return (status);
}