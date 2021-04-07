#include "ft_printf.h"

int ft_printf(const char *input, ...) 
{
	va_list	ap; //가변인자 포인터 선언
	struct checking check;
	int i;

	i = 0;
	va_start(ap, input); //가변인자 목록 포인터 설정

	while (input++)
	{
		write(1, input[i], 1);
		i++;
	}
	return 0;

}
