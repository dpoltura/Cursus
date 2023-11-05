#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    **ft_split(const char *s, char c)
{
    int i;
    int count_word;
    char    **split;
    
    i = 0;
    count_word = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            count_word++;
        i++;
    }
    i = 0;
    split = (char **)malloc(sizeof(strlen(s)) * count_word + 1);
    //while (count_word >= 0)
    //{
        while (s[i] != c)
        {
            i++;
            if (s[i] == c)
            {
                split[count_word] = (char *)malloc(sizeof(strlen(s)) * (i + 2));
                i++;
            }
        }
        i = 0;
        while (s[i] != c)
        {
            *split[i] = s[i];
            i++;
        }
        *split[i] = '\0';
        //count_word--;
    //}
    return (split);
}

int main(void)
{
    char    **split;

    split = ft_split("Hello|World|!", '|');
    printf("%s\n", split[0]);
    free(split);
    return (0);
}