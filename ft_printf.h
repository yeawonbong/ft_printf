/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:29:58 by ybong             #+#    #+#             */
/*   Updated: 2021/04/13 18:26:53 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

struct	checking
{
	int dash = 0;
	int zero = 0;
	int width = -1;
	int dot = 0;
	int precision = -1;
	char type = 0;
};

char	*ft_strchr(const char *str, int c);
int	ft_atoi(const char *str);
