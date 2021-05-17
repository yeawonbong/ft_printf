/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_toprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:35:26 by ybong             #+#    #+#             */
/*   Updated: 2021/05/17 17:53:36 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_tostr(va_list ap, char *toprint)
{
	toprint = ft_strdup("0");
	toprint[0] = va_arg(ap, int);
	return (toprint);
}

char	*x_tostr(va_list ap, char *toprint, char alpha)
{
	unsigned int	temp;
	unsigned int	num;
	int				i;
	int				toalpha;
	char			*res;

	toalpha = alpha == 'x' ? 87 : 55;
	if (!(temp = va_arg(ap, unsigned int)))
		return (ft_strdup("0"));
	toprint = (char*)malloc(15);
	ft_memset(toprint, '0', 15);
	toprint[14] = '\0';
	i = 13;
	while (0 <= i)
	{
		if ((num = temp % 16) < 10)
			toprint[i--] = num + '0';
		else
			toprint[i--] = num + toalpha;
		temp /= 16;
	}
	i = 0;
	while (toprint[i] == '0')
		i++;
	res = ft_strdup(&toprint[i]);
	free(toprint);
	return (res);
}

char	*diu_tostr(va_list ap, t_checking *check)
{
	long long	temp;

	if (!(temp = check->type == 'u' ? \
	va_arg(ap, unsigned int) : va_arg(ap, int)))
		return (ft_strdup("0"));
	if ((int)temp < 0 && ft_strchr("di", check->type))
	{
		check->minus = 1;
		temp *= -1;
	}
	if (check->type == 'u')
		return (ft_utoa(temp));
	return (ft_itoa(temp));
}

char	*s_str(va_list ap, char *toprint)
{
	toprint = ft_strdup(va_arg(ap, char*));
	if (!toprint)
		toprint = ft_strdup("(null)");
	return (toprint);
}

char	*p_tostr(va_list ap, t_checking *check, char *toprint)
{
	long long	temp;
	int			i;
	int			j;
	int			num;
	char		tempstr[13];

	if ((temp = va_arg(ap, long long)) == 0)
	{
		if (check->precision == 0)
			return (ft_strdup("0x"));
		return (ft_strdup("0x0"));
	}
	ft_memset(tempstr, '0', 12);
	tempstr[12] = '\0';
	i = 11;
	while (0 <= i)
	{
		if ((num = temp % 16) < 10)
			tempstr[i--] = num + 48;
		else
			tempstr[i--] = num + 87;
		temp /= 16;
	}
	i = 0;
	while (tempstr[i] == '0')
		i++;
	toprint = (char*)malloc(ft_strlen(&(tempstr[i])) + 3);
	toprint[0] = '0';
	toprint[1] = 'x';
	j = 2;
	if (!*tempstr)
		toprint[j++] = '0';
	while (tempstr[i])
		toprint[j++] = tempstr[i++];
	toprint[j] = '\0';
	return (toprint);
}

char	*fill_toprint(va_list ap, char *toprint, t_checking *check)
{
	if (check->type == '%')
		toprint = ft_strdup("%");
	else if (check->type == 'c')
		toprint = c_tostr(ap, toprint);
	else if (check->type == 's')
		toprint = s_str(ap, toprint);
	else if (check->type == 'p')
		toprint = p_tostr(ap, check, toprint);
	else if (check->type == 'd' || check->type == 'i' || check->type == 'u')
		toprint = diu_tostr(ap, check);
	else if (check->type == 'x' || check->type == 'X')
		toprint = x_tostr(ap, toprint, check->type);
	if (ft_strchr("diuxX", check->type) && !check->precision && *toprint == '0')
	{
		free(toprint);
		return (ft_strdup(""));
	}
	return (toprint);
}
