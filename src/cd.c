#include "../include/shell.h"
#include "../include/string.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int cd_no_options(char **args, char *cwd, char *pwd, char *dest)
{
        int ret;
        int len;

        len = strlen_double(args);
        switch (len)
        {
        case 0:
                if ((ret = chdir(getenv("HOME")) < 0))
                {
                        write(1, "Change of directory failed.\n", 28);
                        return (ret);
                }
                else
                {
                        strcpy(owd, cwd);
                        strcpy(cwd, getenv("HOME"));
                        return (ret);
                }
        case 1:
                if ((ret = chdir(args[0])) < 0)
                {
                        write(1, "Change of directory failed.\n", 28);
                        return (ret);
                }
                else
                {
                        strcpy(owd, cwd);
                        strcpy(cwd, args[0]);
                        return (ret);
                }
        default:
                write(1, "You must type cd with 0 or 1 argument.\n", 39);
                return (1);
        }
}

int cd_l_option(char **args, char *cwd, char *pwd, char *dest, char *option)
{
        int len;
        int ret;
        char *sub;

        len = strlen_double(args);
        strcpy(owd, cwd);
        if (!strcmp(option, "") && len == 1)
        {
                if ((ret = chdir(getenv("HOME")) < 0))
                {
                        write(1, "Change of directory failed.\n", 28);
                        return (ret);
                }
                else
                {
                        strcpy(owd, cwd);
                        strcpy(cwd, getenv("HOME"));
                        return (ret);
                }
        }
        strcpy(dest, args[len - 1]);
        while (strlen(dest))
        {
                if (is_double_points(dest))
                {
                        strtrim_back('/', cwd);
                        strtrim_front('/', dest);
                }
                else
                {
                        sub = substr('/', dest);
                        strcat(cwd, sub);
                        free(sub);
                        strtrim_front('/', dest);
                }
        }
        if (!(ret = chdir(cwd)))
                return (1);
        return (0);
}

int cd(char **args, char *cwd, char *pwd, char *dest)
{
        char *option;
        int ret;

        if (!(option = valid_command(&args[1])))
        {
                write(2, "Invalid input.\nCorrect format: 'cd [-P | -L] [ref | -]'\nDoes the directory exist ?\n", 84);
                return (1);
        }
        if (!strcmp(option, "-P"))
        {
                if (!(ret = chdir(dest)))
                {
                        write(1, "Change of directory failed.\n", 28);
                        return (ret);
                }
                else
                {
                        strcpy(owd, cwd);
                        getcwd(cwd, PATH_MAX);
                        return (ret);
                }
        }
        return (cd_l_option(args, cwd, pwd, dest, option));
}
