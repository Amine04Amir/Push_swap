#include "../includes/push_swap.h"

int ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

long	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	long	r;

	i = 0;
	sign = 1;
	r = 0;
	while (s[i] >= '\t' && s[i] <= '\r' && s[i] != ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - '0');
		i++;
	}
	return (r * sign);
}

int	count_words(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}