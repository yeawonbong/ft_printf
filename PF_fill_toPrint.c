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
			toPrint[i--] = num + 48;
		else
			toPrint[i--] = num + toalpha;
		temp /= 16;
	}
	return (0);
}

char	*PtoStr(va_list ap, char *toPrint)
{
	long long	temp;
	int 		i;
	int			num;

	temp = va_arg(ap, long long);
	toPrint = (char*)malloc(15);
	toPrint[14] = '\0';
	toPrint[0] = '0';
	toPrint[1] = 'x';
	i = 13;
	while (1 < i)
	{
		if ((num = temp % 16) < 10)
			toPrint[i--] = num + 48;
		else
			toPrint[i--] = num + 55; //소문자
		temp /= 16;
	}
	return (toPrint);
}

/*
void	checkingStr(char *toPrint) //출력때로 옮기기
{
	int		extra;

	if (check.width < check.precision)
		check.width = check.precision;
	if (0 < (extra = check.width - ft_strlen(toPrint)))
	{
		if (check.zero || check.space)
		{
			if (check.dash)
			{
				while (extra--)
					write(1, " ", 1);
				write(1, toPrint, ft_strlen(toPrint));
				return (0);
			}
			write(1, toPrint, ft_strlen(toPrint));

		}
	}
	else  //그냥  뽑아
}
*/
char * fill_toPrint(va_list ap, char *toPrint, struct checking check) 
{
	if (check.type == '%')
		toPrint = ft_strdup("%");
	if (check.type == 'c')
		toPrint = CtoStr(ap, toPrint);
	if (check.type == 's')
		toPrint = va_arg(ap, char*);
	if (check.type == 'p')
		toPrint = PtoStr(ap, toPrint);
	if (check.type == 'd' || check.type == 'i')
		toPrint = ft_itoa(va_arg(ap, int));
	if (check.type == 'u')
		toPrint = ft_itoa(va_arg(ap, unsigned int));
	if (check.type == 'x' || check.type == 'X')
		toPrint = XtoStr(ap, toPrint, check.type);
	return (toPrint);
	//toPrint 출력 시작
}