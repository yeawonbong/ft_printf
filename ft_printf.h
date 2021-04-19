/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:29:58 by ybong             #+#    #+#             */
/*   Updated: 2021/04/19 22:18:38 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

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

int			ft_strlen(const char *str);
char		*ft_strchr(const char *str, char c);
int			ft_atoi(const char *str);
static int	ft_count_reslen(long long n);
char		*ft_itoa(int n);
char		*ft_strdup(const char *str);
const char	*lastNum(const char *input);

int			ft_printf(const char *input, ...);

const char	*fill_pricision(const char *input, va_list ap, struct checking check);
const char	*ft_check(char const *input, va_list ap, struct checking check);
char		*CtoStr(va_list ap, char *toPrint);
char		*XtoStr(va_list ap, char *toPrint, char alpha);
char		*PtoStr(va_list ap, char *toPrint);
char		*fill_toPrint(va_list ap, char *toPrint, struct checking check);
