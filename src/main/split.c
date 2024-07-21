#include "../../includes/push_swap.h"

int word_count(char *str, char c)
{
    int count;
    bool word;

    count = 0;
    while(*str)
    {
        word = false;
        while (*str == c)
            str++;
        while (*str && *str != c)
        {
            if(!word)
            {
                count++;
                word = true;
            }
            str++;
        }
        
    }
    return (count);
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

}