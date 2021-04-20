#include "ft_printf.h"

int ft_printf(const char *input, ...) 
{
	struct checking *check;
	va_list	ap; //가변인자 포인터 선언
	char *toPrint;

	check = malloc(sizeof(struct checking));
	ft_memset(check, 0, sizeof(struct checking));
	va_start(ap, input); //가변인자 목록 포인터 설정
	while (*input)
	{
		if (*input && *input != '%')
			write(1, input++, 1); //바로 출력
		if (*input == '%')
		{
			input++;
			while (*input && (check->type = ft_strchr("scpdiuxxX%", *input)) == 0)
			{
				ft_check(input, ap, check);
				input++;
			} //type 들어가면 끝남.
			input++; //type 다음 가리키기
			toPrint = fill_toPrint(ap, toPrint, check);
			// write_toPrint(ap, toPrint)
		
			printf("\n%d\n", check->dash);
			printf("%d\n", check->space);
			printf("%d\n", check->zero);
			printf("%d\n", check->width);
			printf("%d\n", check->dot);
			printf("%d\n", check->precision);
			printf("%c\n", check->type);
			printf("|TOPRINT IS : %x\n", 29);
		}
	}
	free (check);
	// free (toPrint);
	return 0;
}

int main()
{
	ft_printf("abc%-15.3s", "hihihi");
}