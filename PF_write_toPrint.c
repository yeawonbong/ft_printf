#include "ft_printf.h"

void write_toPrint(va_list ap, char *toPrint, struct checking *check)
{
	if (0 <= check->precision)
	{
		if (check->type == 's' && ft_strlen(toPrint) > check->precision)
		{
			toPrint = ft_substr(toPrint, 0, check->precision);
			printf("|CUT_TOPRINT: %s\n", toPrint);
		}
	}
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