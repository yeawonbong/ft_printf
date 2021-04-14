/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:29:58 by ybong             #+#    #+#             */
/*   Updated: 2021/04/14 18:14:43 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

struct	checking
{
	int dash;
	int space;
	int zero;
	int width;
	int dot;
	int precision;
	char type;
};

char		*ft_strchr(const char *str, int c);
int			ft_atoi(const char *str);
const char	*passNum(const char *input);
char		*CtoStr(va_list ap, char *toPrint);
char		*PtoStr(va_list ap, char *toPrint);
char		*fill_toPrint(va_list ap, char *toPrint);
