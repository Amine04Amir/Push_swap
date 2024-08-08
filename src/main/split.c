/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:49:18 by mamir             #+#    #+#             */
/*   Updated: 2024/08/08 09:59:30 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_count(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

int	len_til_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	*ft_word(char *s, char c)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = len_til_c(s, c);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (len > i)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *str, char c)
{
	char	**s;
	int		i;
	int		j;
	int		wc;
	
	i = 0;
	j = 0;
	wc = ft_count(str, c);
	s = malloc(sizeof(char *) * (wc + 1));
	if (!s)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			s[j] = ft_word(&str[i], c);
			if (!s[j++])
			{
				free_split(s);
				return (NULL);
			}
		}
		while (str[i] != c && str[i])
			i++;
	}
	s[j] = NULL;
	return (s);
}
