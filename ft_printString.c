#include "ft_printf.h"

char	*CtoStr(va_list ap, char *toPrint)
{
	toPrint = (char*)malloc(sizeof(temp) + 1);
	toPrint[0] = va_arg(ap, int);
	toPrint[1] = '\0';
	return (toPrint);
}

char	*PtoStr(va_list ap, char *toPrint)
{
	long long	temp;
	int 		i;
	int			num;

	toPrint = (char*)malloc(15);
	temp = va_arg(ap, long long);
	toPrint[14] = '\0';
	toPrint[0] = '0';
	toPrint[1] = 'x';
	i = 13;
	while (1 < i)
	{
		if ((num = temp % 16) < 10;
			toPrint[i--] = num + 48;
		else
			toPrint[i--] = num + 87;
		temp /= 16;
	}
	return (toPrint);
}

char	*fill_toPrint(va_list ap, char *toPrint)
{
	if (check.type == 'c')
		toPrint = CtoStr(ap, toPrint);
	if (check.type == 's')
		toPrint = va_arg(ap, char*);
	if (check.type == 'p')
		toPrint = PtoStr(ap, toPrint);
	return (toPrint);
}
void	checkingNum

void	checkingStr(char *toPrint)
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
	else  그냥  뽑아
}


void	printOthers(va_list ap) //header 넣기
{
	char	*toPrint;

	if (check.type == '%')
	{
		while (check.width-- - 1)
		{	
			if (check.zero)
				write(1, "0", 1);
			else
				write()
		}
		write(1,"%",1);
		return (0);
	}
	else
		toPrint = fill_toPrint(ap, toPrint)
	//toPrint 출력 시작
	

}