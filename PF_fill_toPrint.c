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
	// printf("TEMPIS : %d\n", temp);
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
	}//printf("TTTTTTTTTTT: %s\n", toPrint);
	while (*toPrint == '0')
		toPrint++;
	return (toPrint);
}

char	*DIUtoStr(va_list ap, char *toPrint, struct checking *check)
{
	long long	temp;

	if (!(temp = check->type == 'u' ? va_arg(ap, int) : va_arg(ap, unsigned int)))
	{
		// if (check->precision == 0)
		// 	return (ft_strdup(""));
		return (ft_strdup("0"));
	}
	// printf("TEMP IS : %d\n", (int)temp);
	if ((int)temp < 0)
	{
		check->minus = 1;
		temp *= -1;
	}
	toPrint = ft_itoa(temp);

	return (toPrint);
}

char	*StoStr(va_list ap, char *toPrint)
{
	toPrint = va_arg(ap, char*);
	if (!toPrint)
		toPrint = ft_strdup("(null)");
	return (toPrint);
}

char	*PtoStr(va_list ap, char *toPrint)
{
	long long	temp;
	int 		i;
	int			j;
	int			num;
	char		tempStr[13];

	if (!(temp = va_arg(ap, long long)))
		return (ft_strdup("0x0"));
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
	while (tempStr[i])
		toPrint[j++] = tempStr[i++];
	return (toPrint);
}

char * fill_toPrint(va_list ap, char *toPrint, struct checking *check) 
{
	if (check->type == '%')
		toPrint = ft_strdup("%");
	else if (check->type == 'c')
		toPrint = CtoStr(ap, toPrint);
	else if (check->type == 's')
		toPrint = StoStr(ap, toPrint);
	else if (check->type == 'p')
	// {
	// 	temp = XtoStr(ap, toPrint, 'x');
	// 	toPrint = (char*)malloc(sizeof(temp) + 3);
	// 	ft_strlcat("0x", temp , sizeof(temp) + 3);
	// }
		toPrint = PtoStr(ap, toPrint);
	else if (check->type == 'd' || check->type == 'i' || check->type == 'u')
		toPrint = DIUtoStr(ap, toPrint, check);
	// else if (check->type == 'u')
	// 	toPrint = ft_itoa(va_arg(ap, unsigned int));
	else if (check->type == 'x' || check->type == 'X')
		toPrint = XtoStr(ap, toPrint, check->type);
	if (ft_strchr("diuxX", check->type) && check->precision == 0)
	{	
		free (toPrint);
		return (ft_strdup(""));
	}
	return (toPrint);
	//toPrint 출력 시작
}

//printf("2PRINTF: %s\n", toPrint);
	