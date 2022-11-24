#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include "string.h"
#include "shell.h"

/**
 * Check if an array of strings contains a string.
 * @param array The array of strings.
 * @param str The string to find.
 * @return -1 if the string is not found, the index of the string otherwise.
 */
int find(char** array, char* str) {
	if(array == NULL || str == NULL)
		return -1;
	for(int i = 0; array[i] != NULL; ++i)
		if(strcmp(array[i], str) == 0)
			return i;
	return -1;
}
char *get_pwd_adds(char** array) {
    int i;
    if (!array) {
        return NULL;
    }
    i = 0;
    while (array[i] && (strcmp(array[i], "-P") == 0 || strcmp(array[i], "-L") == 0))
        i++;
    if (i > 0)
        return (array[i - 1]);
    return ("");
}

char* concat__(const char* s, ...) {
	if(s == NULL) return NULL;
	va_list args;
	size_t len = strlen(s);
	char* tmp;

	// Compute the length of the string
	va_start(args, s);
	while((tmp = va_arg(args, char *)) != NULL)
		len += strlen(tmp);
	va_end(args);

	// Allocate the string
	char* result = calloc(len + 1, sizeof(char));
	if(result == NULL) return NULL;

	// Concatenate the strings
	va_start(args, s);
	if(memmove(result, s, strlen(s) + 1) == NULL) {
		free(result);
		return NULL;
	}

	size_t j = strlen(s), l;
	while((tmp = va_arg(args, char *)) != NULL && result != NULL) {
		l = strlen(tmp);
		if(memmove(result + j, tmp, l + 1) == NULL) {
			free(result);
			return NULL;
		}
		j += l;
	}
	va_end(args);
	result[len] = '\0';
	return result;
}

#define INT_MAX_LENGTH 12

char* int_to_string(int i) {
	char* res = calloc(INT_MAX_LENGTH + 1, sizeof(char));
	if(res == NULL) return NULL;
	for(int j = 0; j < INT_MAX_LENGTH; ++j) {
		res[j] = (char) (i % 10 + '0');
		i /= 10;
		if(i == 0) break;
	}
	return res;
}

char* substring(char* str, size_t start, size_t end) {
	if(str == NULL || start > end || end > strlen(str))
		return NULL;
	char* res = calloc(end - start, sizeof(char));
	if(memmove(res, str + start, end - start))
		free(res), res = NULL;
	return res;
}

char* truncate_string(char* str, size_t max, char* prefix) {
	if(!str) return NULL;

	size_t str_len = strlen(str);
	if(str_len < max) return strdup(str);

	char* res = calloc(max + 1, sizeof(char));
	if(!res) return NULL;

	size_t prefix_len = strlen(prefix);
	size_t len = max - prefix_len;
	if(!memmove(res + prefix_len, str + str_len - max + prefix_len, len + 1) ||
	   !memmove(res, prefix, prefix_len)) {
		free(res);
		return NULL;
	}

	return res;
}

// Gets length of a 2D array    
int     strlen_double(char **arr)    
{    
        int         i;    

        i = 0;    
        if (!arr || !arr[i])    
                return (0);    
        while (arr[i])    
                i++;    
        return (i);    
}    

// Checks if command is in format "cd [-P | -L | null] [ref | -]"    
char    *valid_command(char **args)    
{    
        int     i;    
        char    *option;    

        i = 0;    
        option = "";    
        if (!args)    
                return (option);
        while (args[i] && (!strcmp(args[i], "-P") || !strcmp(args[i], "-L")))    
        {    
                if (!strcmp(args[i], "-P"))    
                        option = "-P";    
                else    
                        option = "-L";    
                i++;    
        }    
        if (args[i] && args[i][0] == '-')    
        {    
                if (args[i][1] || strlen_double(&args[i + 1]) != 0)    
                        return (NULL);    
        }    
        if (args[i] && strlen_double(&args[i]) != 1)    
                return (NULL);
        if (args[i] && !strcmp(args[i], "-"))
                return (option);
        if (chdir(args[i]) < 0 && strlen_double(args) > 0)
                return (NULL);
        return (option);    
}  

void    strtrim_back(char c, char *cwd)
{
        int     i;

        i = strlen(cwd) - 1;
        while (cwd[i] && cwd[i] != c)
                i--;
        cwd[i] = 0;
}

void    strtrim_front(char c, char *dest)
{
        int     i;
        int     iter;

        i = 0;
        iter = 0;
        while (dest[i] && dest[i] != c)
                i++;
        if (dest[i])
                i++;
        while (dest[i])
                dest[iter++] = dest[i++];
        dest[iter] = 0;
}

char    *substr(char c, char *dest)
{
        size_t	len;
        char    *sub;

        len = 0;
        if (!(sub = malloc(sizeof(char) * PATH_MAX)));
        sub[0] = '/';
        while (dest[len] && dest[len] != c)
        {
                sub[len + 1] = dest[len];
                len++;
        }
        if (dest[len])
                sub[len + 1] = dest[len];
        sub[len + 1] = 0;
        return (sub);
}

int     is_double_points(char *str)
{
        if (!strncmp(str, "..", 2))
                return (1);
        return 0;
}
