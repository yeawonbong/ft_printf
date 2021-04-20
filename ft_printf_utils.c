#include "ft_printf.h"

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		ft_strchr(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char)str[i]);
		i++;
	}
	return (0);
}

int			ft_atoi(const char *str)
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
static int	ft_count_reslen(long long n)
{
	int			count;
	int			minus;
	int			reslen;

	minus = 0;
	if (n < 0)
		minus = 1;
	count = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	reslen = count + minus;
	return (reslen);
}

char		*ft_itoa(int n)
{
	long long	tempn;
	char		*res;
	int			reslen;

	tempn = (long long)n;
	reslen = ft_count_reslen(tempn);
	if (!(res = (char*)malloc(reslen + 1)))
		return (0);
	if (tempn < 0)
	{
		res[0] = '-';
		tempn *= -1;
	}
	res[reslen--] = '\0';
	while (tempn / 10 != 0)
	{
		res[reslen] = (tempn % 10) + '0';
		tempn = tempn / 10;
		reslen--;
	}
	res[reslen] = tempn + '0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char*)malloc(ft_strlen(str) + 1)))
		return (0);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

const char *lastNum(const char *input)
{
	while ('0' <= *input && *input <= '9')
		input++;
	return (input - 1);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*tempptr;

	i = 0;
	tempptr = (unsigned char *)ptr;
	while (i < num)
		tempptr[i++] = (unsigned char)value;
	return (ptr);
}
