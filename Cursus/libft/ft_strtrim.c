#include <stdlib.h>
#include "libft.h"

int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (c != set[i] && set[i] != '\0')
		i++;
	if (set[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char		*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (is_in_set(s1[i], set) == 0)
		i++;
	while (j > i && is_in_set(s1[j - 1], set) == 0)
		j--;
	str = malloc(sizeof(*s1) * (j - i + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
