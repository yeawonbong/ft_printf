#include "ft_printf.h"

char *passNum(const char *input)
{
	while ('0' <= *input && *input <= '9')
		input++;
	return (input - 1);
}
char	findType(char *c)
{
	int		i;
	char	*type;

	type = "scpdiuxxX%";
	i = 0;
	while (type[i])
	{
		if (type[i] == *c)
			return (type[i]); //type 반환
		i++;
	}
	return (0);
}

//struct checking ft_check(struct checking check, char const *input)

int ft_printf(const char *input, ...) 
{
	static struct checking check; //static 가능? ???????????????
	va_list	ap; //가변인자 포인터 선언
	char *toPrint;
//	int i;

//	i = 0;
	va_start(ap, input); //가변인자 목록 포인터 설정

	while (input)
		if (*input != '%')
			write(1, input++, 1); //바로 출력
		else // (input == %)
		{
			input++;
			while ((check.type = findType(input)) == 0)
			{
				if (*input == '-')
					check.dash = 1;
				if (*input == '0')
					check.zero = 1;
				if ('0' <= *input && *input <= '9') //width
				{
					check.width = ft_atoi(*input);
					input = passNum(input);
				}
				if (*input == '.') //precision
				{
					check.dot = 1;
					check.precision = ft_atoi(++input);
					input = passNum(input);
				}
				input++;
			} //type 들어가면 끝남.
			if ()
			while ()
			}
		}
	return 0;
}
