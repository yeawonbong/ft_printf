#include "ft_printf.h"

int ft_printf(const char *input, ...) 
{
	struct checking *check;
	va_list	ap; //가변인자 포인터 선언
	char *toPrint;


	va_start(ap, input); //가변인자 목록 포인터 설정
	while (*input)
	{
		if (*input && *input != '%')
			write(1, input++, 1); //바로 출력
		if (*input == '%')
		{
			check = malloc(sizeof(struct checking));
			ft_memset(check, 0, sizeof(struct checking));
			check->precision = -1;
			input++;
			ft_check(input, ap, check);
			input++; //type 다음 가리키기
			toPrint = fill_toPrint(ap, toPrint, check);
										if(1) 
					/*test code--->*/	{										
											printf("\n|DASH IS : %d\n", check->dash);
											printf("|SPACE IS : %d\n", check->space);
											printf("|ZERO IS : %d\n", check->zero);
											printf("|WIDTH IS : %d\n", check->width);
											// printf("%d\n", check->dot);
											printf("|PRECISION IS : %d\n", check->precision);
											printf("|TYPE IS : %c\n", check->type);
											printf("|@TOPRINT IS : %s\n", toPrint);
										}
	//		write_toPrint(ap, toPrint, check);
			input++;
		}
	}
	free (check);
	// free (toPrint);
	return 0;
}

int main()
{
	ft_printf("abc%-010.10010d", -12345);
}