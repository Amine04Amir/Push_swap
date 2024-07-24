/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:49:18 by mamir             #+#    #+#             */
/*   Updated: 2024/07/22 04:45:25 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int word_count(char *str, char c)
{
    int count;
    bool inside_word;

    count = 0;
    while(*str)
    {
        inside_word = false;
        while (*str == c)
            str++;
        while (*str && *str != c)
        {
            if(!inside_word)
            {
                count++;
                inside_word = true;
            }
            str++;
        }
    }
    return (count);
}

char *get_next_word(char *str, char c)
{
    
}

char **split(char *str, char c)
{
    int     words;
    int     i;
    char    **result;

    i = 0;
    words = word_count(str, c);
    if (!words)
        exit(1);
    result = malloc(sizeof(char *) * (size_t)(words + 2));
    if (!result)
        return (NULL);
    while (words-- >= 0)
    {
        if (i == 0)
        {
            result[i] = malloc(sizeof(char));
            if (!result[i])    
                return NULL;
            result[i++][0] = '\0';
            continue ;
        }
        result[i++] = get_next_word(str, c);
    }
    result[i] = NULL;
    return (result);
}