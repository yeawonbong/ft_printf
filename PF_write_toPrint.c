/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_write_toprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:55:27 by ybong             #+#    #+#             */
/*   Updated: 2021/05/17 22:17:12 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*apply_precision(char *toprint, t_checking *check, int gap)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	check->zero = 0;
	if (check->type == 's')
	{
		if (ft_strlen(toprint) > check->precision)
		{
			temp = ft_substr(toprint, 0, check->precision);
			toprint = temp;
		}
		else
			return (toprint);
	}
	else if (ft_strchr("diuxX", check->type)\
	&& 0 < (gap = check->precision - ft_strlen(toprint)))
	{
		temp = (char*)malloc(check->precision + 1);
		while (gap--)
			temp[i++] = '0';
		while (toprint[j])
			temp[i++] = toprint[j++];
		temp[i] = '\0';
		toprint = temp;
	}
	return (toprint);
}

int			write_gap(int gap, int gapchar, t_checking *check)
{
	while (gap--)
		ft_write(&gapchar, 1, check);
	return (gap);
}

int			write_minus(int gap, t_checking *check, char gapchar)
{
	ft_write("-", 1, check);
	if (check->zero)
		gap = write_gap(gap, gapchar, check);
	return (gap);
}

int			preorocess(int gap, t_checking *check, char *toprint)
{
	if (ft_strchr("cp", check->type) || check->dash)
		check->zero = 0;
	if ((gap = check->width - ft_strlen(toprint)) < 0)
		gap = 0;
	if (gap && (check->minus))
		gap--;
	if (gap && check->type == 'c' && *toprint == '\0')
		gap--;
	return (gap);
}

void		write_toprint(char *toprint, t_checking *check)
{
	int		gap;
	char	gapchar;

	gap = 0;
	if (0 <= check->precision && check->type != '%')
		toprint = apply_precision(toprint, check, gap);
	gap = preorocess(gap, check, toprint);
	gapchar = check->zero ? '0' : ' ';
	if (gap && !check->dash && !(check->minus && check->zero))
		write_gap(gap, gapchar, check);
	if (check->minus && ft_strchr("di", check->type) && *toprint != '-')
		gap = write_minus(gap, check, gapchar);
	if (*toprint)
	{
		ft_write(toprint, ft_strlen(toprint), check);
		free(toprint);
	}
	if (check->type == 'c' && *toprint == '\0')
		ft_write("\0", 1, check);
	if (gap && check->dash)
		write_gap(gap, gapchar, check);
	return ;
}
