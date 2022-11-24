#ifndef UTILS_H
#define UTILS_H

# include <string.h>
#include <unistd.h>

/**
 * Split a string into an NULL-terminated array of strings.
 * @param str The string to split.
 * @param delim The delimiter.
 * @return The array of strings (NULL-terminated).
 */
char	**split(char *str, char charset);
char	**bigfree(char **tab);

int find(char** array, char* str);

char* concat__(const char* s, ...);
#define concat(...) concat__(__VA_ARGS__, NULL)

char* int_to_string(int i);

char* substring(char* str, size_t start, size_t end);

char *get_pwd_adds(char** array);

char* truncate_string(char* str, size_t max, char* prefix);

int     strlen_double(char **arr); 

char    *valid_command(char **args);

void    strtrim_back(char c, char *cwd);

void    strtrim_front(char c, char *dest);

char	*substr(char c, char *dest);

int     is_double_points(char *str);

#endif //UTILS_H
