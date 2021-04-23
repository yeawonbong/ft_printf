#include "ft_printf.h"

char	*apply_precision(va_list ap, char *toPrint, struct checking *check)
{
	char	*temp;
	int		gap;
	int		i;
	int		j;

	gap = 0;
	i = 0;
	j = 0;
	check->zero = 0; //precision 있으면 0이 무시된다.
	if (check->type == 's' && ft_strlen(toPrint) > check->precision)
	{
		temp = ft_substr(toPrint, 0, check->precision);
		free(toPrint);
		toPrint = temp;
	}
	else if (ft_strchr("di", check->type) && 0 < (gap = check->precision - ft_strlen(toPrint)))
	{
		temp = (char*)malloc(check->precision + 1);
		while (gap--)
			temp[i++] = '0';
		while (toPrint[j])
			temp[i++] = toPrint[j++];
		temp[i] = '\0';
	}
	return (temp);
}
void write_toPrint(va_list ap, char *toPrint, struct checking *check)
{
	int		gap;
	char	gapChar;

	if (0 <= check->precision) //precision 있을 떄 
		toPrint = apply_precision(ap, toPrint, check);
//	printf("TEST: %s\n",toPrint);
	if (ft_strchr("cdp", check->type) || check->dash) //0 무시되는 것 처리(error)
		check->zero = 0;
	gapChar = check->zero ? '0' : ' ';
	if ((gap = check->width - ft_strlen(toPrint)) < 0)
		gap = 0;
	if (gap && check->minus)
		gap--;
	if (check->dash == 0 && gap)
	{
		while (gap--)
			write(1, &gapChar, 1);
	}
	if (check->minus)
		write(1, "-", 1);
	write(1, toPrint, ft_strlen(toPrint));
	if (check->dash == 1 && gap)
	{
		while (gap--)
			write(1, &gapChar, 1);
	}

//	printf("|@TOPRINT AFTER WRITE IS : %s\n", toPrint);


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
}*/