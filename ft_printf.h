/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:29:58 by ybong             #+#    #+#             */
/*   Updated: 2021/05/18 19:45:15 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_checking
{
	int		dash;
	int		zero;
	int		width;
	int		precision;
	char	type;
	int		minus;
	int		count;
}				t_checking;

/*
**----------------
**	utilities
*/
int				ft_strlen(const char *str);
char			ft_strchr(const char *str, char c);
char			*ft_strdup(const char *str);
char			*ft_substr(char const *s, int start, size_t len);
void			*ft_memset(void *ptr, int value, size_t num);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
char			*ft_xtoa(char *str, long long temp, int i, int toalpha);

/*
**---------------------
**	ft_printf.c
*/
void			ft_write(const void *towrite, int length, t_checking *check);
const char		*if_percent(const char *input, va_list ap, t_checking *check\
, char *toprint);
int				ft_printf(const char *input, ...);

/*
**---------------------
**	pf_check.c
*/
char			*if_nullp(t_checking *check);
const char		*lastnum(const char *input);
const char		*if_pricision(const char *input, va_list ap\
, t_checking *check);
const char		*if_num(const char *input, va_list ap, t_checking *check);
const char		*ft_check(char const *input, va_list ap, t_checking *check);

/*
**---------------------
**	pf_fill_toprint.c
*/
char			*cs_tostr(va_list ap, char *toprint, t_checking *check);
char			*p_tostr(va_list ap, t_checking *check, char *toprint, int i);
char			*x_tostr(va_list ap, char *toprint, char alpha);
char			*diu_tostr(va_list ap, t_checking *check);
char			*fill_toprint(va_list ap, char *toprint, t_checking *check);

/*
**---------------------
**	pf_write_toprint.c
*/
char			*apply_precision(char *toprint, t_checking *check, int gap\
, int i);
int				preorocess(int gap, t_checking *check, char *toprint);
int				write_gap(int gap, int gapchar, t_checking *check);
int				write_minus(int gap, char gapchar, t_checking *check);
void			write_toprint(char *toprint, t_checking *check);

#endif
