#include "ft_printf.h"

int ft_printf(const char *input, ...) 
{
	struct checking check;
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
			while (*input == '')
			if (*input == )
			while ()
		}
	return 0;

}
