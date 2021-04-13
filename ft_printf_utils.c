char	*ft_strchr(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char*)&str[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long long i;
	long long res;

	i = 0;
	res = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)res);
}