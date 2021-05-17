/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_toprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:35:26 by ybong             #+#    #+#             */
/*   Updated: 2021/05/17 22:03:03 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cs_tostr(va_list ap, char *toprint, t_checking *check)
{
	if (check->type == 'c')
	{
		toprint = ft_strdup("0");
		toprint[0] = va_arg(ap, int);
		return (toprint);
	}
	else if (check->type == 's')
	{
		toprint = ft_strdup(va_arg(ap, char*));
		if (!toprint)
			toprint = ft_strdup("(null)");
		return (toprint);
	}
	return (0);
}

char	*p_tostr(va_list ap, t_checking *check, char *toprint, int i)
{
	long long	temp;
	int			j;
	char		*tempstr;

	if ((temp = va_arg(ap, long long)) == 0)
		return (if_nullp(check));
	tempstr = (char*)malloc(13);
	ft_memset(tempstr, '0', 13);
	tempstr[12] = '\0';
	i = 11;
	tempstr = ft_xtoa(tempstr, temp, i, 87);
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
	free(tempstr);
	return (toprint);
}

char	*x_tostr(va_list ap, char *toprint, char alpha)
{
	long long		temp;
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
	toprint = ft_xtoa(toprint, temp, i, toalpha);
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

char	*fill_toprint(va_list ap, char *toprint, t_checking *check)
{
	int			i;

	i = 0;
	if (check->type == '%')
		toprint = ft_strdup("%");
	else if (check->type == 'c')
		toprint = cs_tostr(ap, toprint, check);
	else if (check->type == 's')
		toprint = cs_tostr(ap, toprint, check);
	else if (check->type == 'p')
		toprint = p_tostr(ap, check, toprint, i);
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
