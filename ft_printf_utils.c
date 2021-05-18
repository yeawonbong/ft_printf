/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:12:10 by ybong             #+#    #+#             */
/*   Updated: 2021/05/18 15:34:39 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char		*ft_utoa(unsigned int n)
{
	unsigned int	tempn;
	char			*res;
	int				reslen;

	tempn = n;
	reslen = ft_count_reslen(tempn);
	if (!(res = (char*)malloc(reslen + 1)))
		return (0);
	if (tempn < 0)
	{
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

char		*ft_xtoa(char *str, long long temp, int i, int toalpha)
{
	long long	num;

	while (0 <= i)
	{
		if ((num = temp % 16) < 10)
			str[i--] = num + '0';
		else
			str[i--] = num + toalpha;
		temp /= 16;
	}
	return (str);
}
