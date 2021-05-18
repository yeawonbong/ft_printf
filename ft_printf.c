/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:33:44 by ybong             #+#    #+#             */
/*   Updated: 2021/05/18 17:32:33 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write(const void *towrite, int length, t_checking *check)
{
	write(1, towrite, length);
	check->count += length;
}

const char	*if_percent(const char *input, va_list ap, \
t_checking *check, char *toprint)
{
	ft_memset(check, 0, sizeof(t_checking) - sizeof(int));
	check->precision = -1;
	input = ft_check(++input, ap, check);
	if (check->type == 0)
	{
		free(check);
		free(toprint);
		return (0);
	}
	toprint = fill_toprint(ap, toprint, check);
	write_toprint(toprint, check);
	return (input);
}

int			ft_printf(const char *input, ...)
{
	va_list		ap;
	t_checking	*check;
	char		*toprint;
	int			res;

	toprint = NULL;
	check = malloc(sizeof(t_checking));
	check->count = 0;
	va_start(ap, input);
	while (*input)
	{
		if (*input != '%')
			ft_write(input++, 1, check);
		if (*input == '%')
		{
			if (!(input = if_percent(input, ap, check, toprint)))
				return (0);
		}
	}
	res = check->count;
	free(check);
	return (res);
}
