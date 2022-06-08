
int	ft_strncmp(char* str, char* str2, int len)
{
	int	i;

	i = 0;
	while ((str[i] || str2[i]) && len)
	{
		if (str[i] != str2[i])
			return str[i] - str2[i];
		i++;
		len--;
	}
	return (0);
}