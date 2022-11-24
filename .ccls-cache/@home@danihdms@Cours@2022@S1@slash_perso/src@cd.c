#include "../include/shell.h"
#include "../include/string.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int cd_l_option(char **args, char *cwd, char *pwd, char *dest, char *option)
{
        int len;
        int ret;
        char *sub;
        char tmp[PATH_MAX];

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
        if (dest[0] == '-')
        {
                strcpy(tmp, cwd);
                strcpy(cwd, owd);
                strcpy(owd, tmp);
                if (!(ret = chdir(cwd)))
                        return (1);
                else
                        return (0);
        }

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
