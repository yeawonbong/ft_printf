#include "ft_printf.h"

const char *passNum(const char *input)
{
	while ('0' <= *input && *input <= '9')
		input++;
	return (input - 1);
}

const char *ft_check(struct checking check, char const *input)
{
	if (*input == '-')
		check.dash = 1;
	if (*input == '0')
		check.zero = 1;
	if ('0' <= *input && *input <= '9') //width
	{
		check.width = ft_atoi(input);
		input = passNum(input);
	}
	if (*input == '.') //precision
	{
		check.dot = 1;
		check.precision = ft_atoi(++input);
		input = passNum(input);
	}
	return (input);
}

int ft_printf(const char *input, ...) 
{
	static struct checking check; //static 가능? ???????????????ㅇㅇ
	va_list	ap; //가변인자 포인터 선언
//	char *toPrint;

	check.width = -1;
	check.precision = -1;
	va_start(ap, input); //가변인자 목록 포인터 설정
	while (input)
		if (*input != '%')
			write(1, input++, 1); //바로 출력
		else // (input == %)
		{
			input++;
			while ((check.type = *(ft_strchr("scpdiuxxX%", *input))) == 0)
			{
				ft_check(check, input);
				input++;
			} //type 들어가면 끝남.
			if (ft_strchr("diuxX", check.type)) //숫자면
			{
				printNum();
			}
			else
				printOthers(ap);
		}
	return 0;
}

void	printOthers(va_list ap)
{
	char	*toPrint;

	if (check.type == '%')
		write(1,"%",1);
	if (check.type == 'c')
		toPrint = fillChar(ap, toPrint);
	if (check.type == 's')
		toPrint = va_arg(ap, char*);
	if (check.type == 'p')
		toPrint = va_arg(ap, long long);
}
