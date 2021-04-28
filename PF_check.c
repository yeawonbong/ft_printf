#include "ft_printf.h"

const char *fill_pricision(const char *input, va_list ap, struct checking *check)
{
	input++;
	if (*input == '*')
	{
		check->precision = va_arg(ap, int);
		if (check->precision < 0)
			check->precision = -1;
	}
	else if ('0' <= *input && *input <= '9')
	{
		check->precision = ft_atoi(input);	
		input = lastNum(input);
	}
	else	//'.'뒤에 아무것도 없는 경우
	{
		check->precision = 0;
		input--;
	}
	return (input);
}

const char *ft_check(char const *input, va_list ap, struct checking *check)
{
	// while (*input) // while 안돌고 한방에 할수도? 고쳐보자 0420 고쳐봤더 0426
	// {
		if (*input == '-')
		{
			check->dash = 1;
			input++;
		}
		if (*input == ' ')
		{
			check->space = 1;
			input++;
		}
		if (*input == '0')
		{
			check->zero = 1;
			input++;
			if (*input == '-')
			{
				check->dash = 1; //여기 ignored 고친건데 모르겠다... 오류 더 늘어남^_^
				input++;
			}
		}
		if (('0' <= *input && *input <= '9') || *input == '*') //width
		{
			if (*input == '*')
			{
				check->width = va_arg(ap, int);
				if (check->width < 0)
				{
					check->dash = 1;
					check->width *= -1;
				}
			}
			else
			{
				check->width = ft_atoi(input);
				input = lastNum(input);
			}
			input++; //10 ???
		}
		if (*input == '.') //precision
		{
			input = fill_pricision(input, ap, check);
			input++;
		}
	// 	if (ft_strchr("scpdiuxxX%", *input)) == 1)
	// }
	check->type = *input;
	return (input++);
}


// && (ft_strchr("scpdiuxxX%", *input)) == 0