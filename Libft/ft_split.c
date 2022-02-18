
#include"libft.h"

size_t	ft_wordlen(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && s[r] != c)
		r++;
	return (r);
}

size_t	ft_wordcount(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			r++;
		s++;
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	len;
	size_t	index;

	if (!s)
		return (NULL);
	len = ft_wordcount(s, c);
	arr = (char **)malloc(sizeof(char *) * len + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*s == c && *s != '\0')
			s++;
		arr[i] = (char *)malloc(sizeof(char) * ft_wordlen(s, c) + 1);
		index = 0;
		while (*s != c && *s != '\0')
			arr[i][index++] = *s++;
		arr[i][index] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
