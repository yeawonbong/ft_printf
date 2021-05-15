#include "ft_printf.h"

char	*CtoStr(va_list ap, char *toPrint)
{
	toPrint = ft_strdup("0");
	toPrint[0] = va_arg(ap, int);
	return (toPrint);
}

char	*XtoStr(va_list ap, char *toPrint, char alpha)
{
	unsigned int	temp;
	unsigned int	num;
	int				i;
	int				toalpha;

	toalpha = alpha == 'x' ? 87 : 55;
	if (!(temp = va_arg(ap, unsigned int)))
		return (ft_strdup("0"));
	toPrint = (char*)malloc(15);
	ft_memset(toPrint, '0', 15);
	toPrint[14] = '\0';
	i = 13;
	while (0 <= i)
	{
		if ((num = temp % 16) < 10)
			toPrint[i--] = num + '0';
		else
			toPrint[i--] = num + toalpha;
		temp /= 16;
	}
	while (*toPrint == '0')
		toPrint++;
	return (toPrint);
}

char	*DIUtoStr(va_list ap, t_checking *check)
{
	long long	temp;

	if (!(temp = check->type == 'u' ? va_arg(ap,unsigned int) : va_arg(ap, int)))
		return (ft_strdup("0"));
	if ((int)temp < 0 && ft_strchr("di", check->type))
	{
		check->minus = 1;
		temp *= -1;
	}
	if (check->type == 'u')
		return (ft_utoa(temp));
	return (ft_itoa(temp));
}

char	*StoStr(va_list ap, char *toPrint)
{
	toPrint = va_arg(ap, char*);
	if (!toPrint)
		toPrint = ft_strdup("(null)");
	return (toPrint);
}

char	*PtoStr(va_list ap, t_checking *check, char *toPrint)
{
	long long	temp;
	int 		i;
	int			j;
	int			num;
	char		tempStr[13];
	if ((temp = va_arg(ap, long long)) == 0)
	{
		if (check->precision == 0)
			return (ft_strdup("0x"));
		return (ft_strdup("0x0"));
	}
	ft_memset(tempStr, '0', 12);
	tempStr[12] = '\0';	
	i = 11;
	while (0 <= i)
	{
		if ((num = temp % 16) < 10)
			tempStr[i--] = num + 48;
		else
			tempStr[i--] = num + 87; //소문자
		temp /= 16;
	}
	i = 0;
	while (tempStr[i] == '0')
		i++;
	toPrint = (char*)malloc(ft_strlen(&(tempStr[i])) + 3);
	toPrint[0] = '0';
	toPrint[1] = 'x';
	j = 2;
	if (!*tempStr)
		toPrint[j++] = '0';
	while (tempStr[i])
		toPrint[j++] = tempStr[i++];
	toPrint[j] = '\0';
	return (toPrint);
}

char * fill_toPrint(va_list ap, char *toPrint, t_checking *check) 
{
	if (check->type == '%')
		toPrint = ft_strdup("%");
	else if (check->type == 'c')
		toPrint = CtoStr(ap, toPrint);
	else if (check->type == 's')
		toPrint = StoStr(ap, toPrint);
	else if (check->type == 'p')
		toPrint = PtoStr(ap, check, toPrint);
	else if (check->type == 'd' || check->type == 'i' || check->type == 'u')
		toPrint = DIUtoStr(ap, check);
	else if (check->type == 'x' || check->type == 'X')
		toPrint = XtoStr(ap, toPrint, check->type);
	if (ft_strchr("diuxX", check->type) && check->precision == 0 && *toPrint == '0')
	{	
		free (toPrint);
		return (ft_strdup(""));
	}
	return (toPrint);
}
	