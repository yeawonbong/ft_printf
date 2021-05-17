/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:35:43 by ybong             #+#    #+#             */
/*   Updated: 2021/05/17 19:49:27 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char		ft_strchr(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char)str[i]);
		i++;
	}
	return (0);
}

char		*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char*)malloc(ft_strlen(str) + 1)) || !str)
		return (0);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_substr(char const *s, int start, size_t len)
{
	char	*dst;
	char	*src;

	if (!s || !(dst = (char *)malloc(len + 1)))
		return (0);
	if (start < ft_strlen(s))
	{
		src = (char*)&s[start];
		dst[len] = '\0';
		while (len--)
			dst[len] = src[len];
	}
	else
		*dst = '\0';
	return (dst);
}

void		*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*tempptr;

	i = 0;
	tempptr = (unsigned char *)ptr;
	while (i < num)
		tempptr[i++] = (unsigned char)value;
	return (ptr);
}
