#include<stdlib.h>
#include "string.h"

char	**bigfree(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	len_w(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

static int	nbr_w(char *str, char charset)
{
	int	count;
	int	i;

	count = 0;
	while (*str)
	{
		while (*str && *str == charset)
			str++;
		i = len_w(str, charset);
		str += i;
		if (i)
			count++;
	}
	return (count);
}

static char	*copy(char *src, int n)
{
	char	*res;

	res = malloc((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[n] = '\0';
	while (n--)
		res[n] = src[n];
	return (res);
}

char	**split(char *str, char charset)
{
	int		size;
	int		i;
	int		n;
	char	**tab;

	if (!str)
		return (NULL);
	size = nbr_w(str, charset);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*str && *str == charset)
			str++;
		n = len_w(str, charset);
		tab[i] = copy(str, n);
		if (!tab[i])
			return (bigfree(tab));
		str += n;
	}
	tab[size] = NULL;
	return (tab);
}