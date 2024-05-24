#include "../includes/push_swap.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*sub;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return ((char *)sub);
}

char	**ft_free(char **s, int n)
{
	while (n > 0)
	{
		free(s[n--]);
	}
	free(s);
	return (0);
}

static char	**ft_help(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != '\0' && s[i] != c && j++ >= 0)
			i++;
		tab[n++] = ft_substr(s, i - j, j);
		if (!tab[n - 1])
			return (ft_free(tab, n));
	}
	tab[n] = NULL;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_help(tab, s, c));
}