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
	int				i;
	int				num;
	int				toalpha;

	toalpha = alpha == 'x' ? 55 : 87;
	temp = va_arg(ap, unsigned int);
	toPrint = (char*)malloc(9);
	toPrint[8] = '\0';
	i = 7;
	while (1 < i)
	{
		if ((num = temp % 16) < 10)
			toPrint[i--] = num + '0';
		else
			toPrint[i--] = num + toalpha;
		temp /= 16;
	}
	return (0);
}

char	*DItoStr(va_list ap, char *toPrint, struct checking *check)
{
	int	temp;

	temp = va_arg(ap, int);
	if (temp < 0)
	{
		check->minus = 1;
		temp *= -1;
	}
	toPrint = ft_itoa(temp);
	return (toPrint);
}

char	*PtoStr(va_list ap, char *toPrint)
{
	long long	temp;
	int 		i;
	int			num;

	temp = va_arg(ap, long long);
	if (!temp)
		return (ft_strdup("0x0"));
	toPrint = (char*)malloc(12);
	toPrint[11] = '\0';
	toPrint[0] = '0';
	toPrint[1] = 'x';
	i = 10;
	while (1 < i)
	{
		if ((num = temp % 16) < 10)
			toPrint[i--] = num + 48;
		else
			toPrint[i--] = num + 87; //소문자
		temp /= 16;
	}
	return (toPrint);
}

char * fill_toPrint(va_list ap, char *toPrint, struct checking *check) 
{
	if (check->type == '%')
		toPrint = ft_strdup("%");
	else if (check->type == 'c')
		toPrint = CtoStr(ap, toPrint);
	else if (check->type == 's')
		toPrint = va_arg(ap, char*);
	else if (check->type == 'p')
		toPrint = PtoStr(ap, toPrint);
	else if (check->type == 'd' || check->type == 'i')
		toPrint = DItoStr(ap, toPrint, check);
	else if (check->type == 'u')
		toPrint = ft_itoa(va_arg(ap, unsigned int));
	else if (check->type == 'x' || check->type == 'X')
		toPrint = XtoStr(ap, toPrint, check->type);
	if (!toPrint)
		toPrint = ft_strdup("(null)");
	return (toPrint);
	//toPrint 출력 시작
}

//printf("2PRINTF: %s\n", toPrint);
	