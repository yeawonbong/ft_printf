/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:29:58 by ybong             #+#    #+#             */
/*   Updated: 2021/05/16 22:28:10 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_checking
{
	int 	dash;
	int 	space;
	int 	zero;
	int 	width;
	int		precision;
	char 	type;
	int		minus;
	int		count;
}			t_checking;

int			ft_strlen(const char *str);
char		ft_strchr(const char *str, char c);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);

char		*ft_strdup(const char *str);
const char	*lastNum(const char *input);
void		*ft_memset(void *ptr, int value, size_t num);
char		*ft_substr(char const *s, int start, size_t len);


int			ft_printf(const char *input, ...);

const char	*fill_pricision(const char *input, va_list ap, t_checking *check);
const char	*ft_check(char const *input, va_list ap, t_checking *check);
char		*CtoStr(va_list ap, char *toPrint);
char		*XtoStr(va_list ap, char *toPrint, char alpha);
char		*DIUtoStr(va_list ap, t_checking *check);
char		*PtoStr(va_list ap, t_checking *check, char *toPrint);
char		*fill_toPrint(va_list ap, char *toPrint, t_checking *check);
char		*apply_precision(char *toPrint, t_checking *check);
void 		write_toPrint(char *toPrint, t_checking *check);

#endif