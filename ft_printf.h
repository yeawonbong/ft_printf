/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:29:58 by ybong             #+#    #+#             */
/*   Updated: 2021/04/13 22:28:39 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

struct	checking
{
	int dash;
	int zero;
	int width;
	int dot;
	int precision;
	char type;
};

char	*ft_strchr(const char *str, int c);
int	ft_atoi(const char *str);
