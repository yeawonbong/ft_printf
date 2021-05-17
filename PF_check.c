/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:33:31 by ybong             #+#    #+#             */
/*   Updated: 2021/05/17 19:13:52 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*fill_pricision(const char *input, va_list ap, t_checking *check)
{
	input++;
	if (*input == '*')
	{
		check->precision = va_arg(ap, int);
		if (check->precision < 0)
			check->precision = -1;
	}
	else if ('0' <= *input && *input <= '9')
	{
		check->precision = ft_atoi(input);
		input = lastnum(input);
	}
	else
	{
		check->precision = 0;
		input--;
	}
	return (input);
}

const char	*ft_check(char const *input, va_list ap, t_checking *check)
{
	while (!ft_strchr("cspdiuxX%", *input) && *input)
	{
		if (*input == '-')
			check->dash = 1;
		else if (*input == ' ')
			check->space = 1;
		else if (*input == '0')
			check->zero = 1;
		if (('0' <= *input && *input <= '9') || *input == '*')
		{
			if (*input == '*')
			{
				check->width = va_arg(ap, int);
				if (check->width < 0)
				{
					check->dash = 1;
					check->width *= -1;
				}
			}
			else
			{
				check->width = ft_atoi(input);
				input = lastnum(input);
			}
		}
		if (*input == '.')
			input = fill_pricision(input, ap, check);
		input++;
	}
	if (!*input)
		return (0);
	check->type = *input;
	return (input++);
}
