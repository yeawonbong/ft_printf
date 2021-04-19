#include "ft_printf.h"

const char *fill_pricision(const char *input, va_list ap, struct checking check)
{
	check.dot = 1;
	input++;
	if (*input == '*')
	{
		check.precision = va_arg(ap, int);
		if (check.precision < 0)
			check.precision = 0;
	}
	else if ('0' <= *input && *input <= '9')
	{
		check.precision = ft_atoi(++input);	
		input = lastNum(input);
	}
	else	//'.'뒤에 아무것도 없는 경우
		input--;
	return (0);
}

const char *ft_check(char const *input, va_list ap, struct checking check)
{
	if (*input == '-')
		check.dash = 1;
	if (*input == ' ')
		check.space = 1;
	if (*input == '0')
		check.zero = 1;
	if ('0' <= *input && *input <= '9' || *input == '*') //width
	{
		if (*input == '*')
			check.width = va_arg(ap, int);
		else
		{
			check.width = ft_atoi(input);
			input = lastNum(input);
		}
	}
	if (*input == '.') //precision
		fill_pricision(input, ap, check);
	return (input);
}