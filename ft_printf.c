#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *input, ...) 
{
	static struct checking check;
	va_list	ap; //가변인자 포인터 선언
	char *toPrint;
//struct check 초기화해주는 함수 짜기 

	va_start(ap, input); //가변인자 목록 포인터 설정
	while (input)
	{
		if (*input != '%')
			write(1, input++, 1); //바로 출력
		else // (input == %)
		{
			input++;
			while ((check.type = *(ft_strchr("scpdiuxxX%", *input))) == 0)
			{
				ft_check(input, ap, check);
				input++;
			} //type 들어가면 끝남.
			input++; //type 다음 가리키기
			toPrint = fill_toPrint(ap, toPrint, check);
			// write_toPrint(ap, toPrint)
		}
	}
	//free (toPrint);
	return 0;
}

int main()
{
	ft_printf("abc %25.5d", 25);
	printf("dash = %d\n", check.dash);
}