#include <unistd.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

/*int	main(void)
{
	const char	*source;
	char	*substr;

	source = "Hello World !";
	substr = ft_substr(source, 2, 5);
	printf("%s\n", substr);
	free (substr);
	return (0);
}*/