#include "ft_printf.h"

char	*apply_precision(char *toPrint, struct checking *check)
{
	char	*temp;
	int		gap;
	int		i;
	int		j;

	temp = 0;
	gap = 0;
	i = 0;
	j = 0;
	check->zero = 0; //precision 있으면 0이 무시된다.
	if (check->type == 's')
	{
		if (ft_strlen(toPrint) > check->precision)
		{
			temp = ft_substr(toPrint, 0, check->precision);
			//free(toPrint);
			toPrint = temp;
		}
		else
			return (toPrint);
	}
	else if (ft_strchr("diuxX", check->type) && 0 < (gap = check->precision - ft_strlen(toPrint)))
	{
//		printf("\n!!!IN\n");
		temp = (char*)malloc(check->precision + 1);
		while (gap--)
			temp[i++] = '0';
		while (toPrint[j])
			temp[i++] = toPrint[j++];
		temp[i] = '\0';
		toPrint = temp;
	}
//	printf("TOPRINT IN PREC: %s\n",toPrint);
	return (toPrint);
}

//char	apply_width_DI()
int		write_gap(int gap, int gapChar, struct checking *check)
{
	while (gap--)
	{
		write(1, &gapChar, 1);
		check->count++;
	}
	return (gap);
}

int		preorocess(int gap, /*char gapChar,*/ struct checking *check, char *toPrint)
{
	if (ft_strchr("csp", check->type) || check->dash) //0 무시되는 것 처리(error)
		check->zero = 0;
	if ((gap = check->width - ft_strlen(toPrint)) < 0)
		gap = 0;
	if (gap && (check->minus))
		gap--;
	if (gap && check->type == 'c' && *toPrint == '\0')
	 	gap--;
	// if (gap && check->dash == 0)
	// 	gap = write_gap(gap, gapChar);


	return (gap);
}



void		write_toPrint(char *toPrint, struct checking *check)
{
	int		gap;
	char	gapChar;

	gap = 0;
	if (0 <= check->precision) //precision 있을 떄 
		toPrint = apply_precision(toPrint, check);
	gap = preorocess(gap, /*gapChar,*/ check, toPrint);
	gapChar = check->zero ? '0' : ' ';
	if (gap && !check->dash && !(check->minus && check->zero))
		write_gap(gap, gapChar, check);
	if (check->minus && ft_strchr("di", check->type) && *toPrint != '-')
	{
		write(1, "-", 1);
		check->count++;
		if (check->zero)
			gap = write_gap(gap, gapChar, check);
	}
	if (*toPrint)
	{
		write(1, toPrint, ft_strlen(toPrint));
		check->count += ft_strlen(toPrint);
	}
	if (check->type == 'c' && *toPrint == '\0')
		{
			write(1, "\0", 1);
			//count++; //\0도 카운트 하나 ? !!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	if (gap && check->dash)
		write_gap(gap, gapChar, check);
	return ;
//	printf("|@TOPRINT AFTER WRITE IS : %s\n", toPrint);


}