#include "ft_printf.h"

const char *fill_pricision(const char *input, va_list ap, struct checking *check)
{
	input++;
	if (*input == '*')
	{
		check->precision = va_arg(ap, int);
		if (check->precision < 0)
			check->precision = 0;
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
	while (*input && (ft_strchr("scpdiuxxX%", *input)) == 0) // while 안돌고 한방에 할수도? 고쳐보자 0420
	{
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
		}
		if ('0' <= *input && *input <= '9' || *input == '*') //width
		{
			if (*input == '*')
				check->width = va_arg(ap, int);
			else
			{
				check->width = ft_atoi(input);//여기 문제있다
				input = lastNum(input);
			}
			input++; //10 
		}
		if (*input == '.') //precision
			input = fill_pricision(input, ap, check);
		input++;
	}
	check->type = *input;
	return (input);
}