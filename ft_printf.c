/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:21:52 by ybong             #+#    #+#             */
/*   Updated: 2021/05/17 20:07:11 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_write(char *towrite, int length, t_checking check)
// {
// 	write(1, towrite, length);
// 	check->count++;
// }

int	ft_printf(const char *input, ...)
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
		{
			write(1, input++, 1);
			check->count++;
		}
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
// {
// 	ft_printf("hi");
// }