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