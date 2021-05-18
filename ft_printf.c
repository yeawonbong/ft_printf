/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:21:52 by ybong             #+#    #+#             */
/*   Updated: 2021/05/18 14:26:43 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_write(const void *towrite, int length, t_checking *check)
{
	write(1, towrite, length);
	check->count += length;
}

int		ft_printf(const char *input, ...)
{
	va_list		ap;
	t_checking	*check;
	char		*toprint;
	int			res;

	check = malloc(sizeof(t_checking));
	check->count = 0;
	va_start(ap, input);
	while (*input)
	{
		if (*input != '%')
			ft_write(input++, 1, check);
		if (*input == '%')
		{
			ft_memset(check, 0, sizeof(t_checking) - sizeof(int));
			check->precision = -1;
			input++;
			input = ft_check(input, ap, check);
			if (check->type == 0)
				return (0);
			toprint = fill_toprint(ap, toprint, check);
			write_toprint(toprint, check);
			input++;
		}
	}
	res = check->count;
	free(check);
	return (res);
}

// int main()
//  {
// 	int *p=0;
// 	printf("%p\n",p);
//  	ft_printf("hi\n");
//  }
