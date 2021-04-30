#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *input, ...) 
{
	va_list		ap; //가변인자 포인터 선언	
	struct 		checking *check;
	char 		*toPrint;

	check = malloc(sizeof(struct checking));
	check->count = 0;
	va_start(ap, input); //가변인자 목록 포인터 설정
	while (*input)
	{
		if (*input != '%')
		{
			write(1, input++, 1); //바로 출력
			check->count++;
		}
		if (*input == '%')
		{
			//malloc 원래위치
			ft_memset(check, 0, sizeof(struct checking) - sizeof(int)); //check->count 빼고 0set
			check->precision = -1;
			input++; //%다음을 가리킴
			input = ft_check(input, ap, check);//type 다음 가리키게 끝남
			toPrint = fill_toPrint(ap, toPrint, check);
										if(1) 
										{										
											// printf("\n|DASH IS : %d\n", check->dash);
											// printf("|SPACE IS : %d\n", check->space);
											// printf("|ZERO IS : %d\n", check->zero);
											// printf("|WIDTH IS : %d\n", check->width);
											// // printf("%d\n", check->dot);
											// printf("|PRECISION IS : %d\n", check->precision);
											// printf("|TYPE IS : %c\n", check->type);
											// printf("|MINUS IS : %d\n", check->minus);
											// printf("|@TOPRINT IS : %s|\n", toPrint);
										}
			write_toPrint(toPrint, check);
			input++;
		}
	}
	//free (check);
	// free (toPrint);
	return (check->count);
}

// int main()
// {
// 	int *p = 0;
//     int a;
//     int b;

//     a = printf("|%0*.%|\n",4);
// //    a = printf("|%000-00*i|",X);
//     printf("\nprintf = %d", a);
//     printf("\n---------------\n");
//     b = ft_printf("|%0*.%|\n",4);
//     printf("\nft_printf = %d\n", b);
// }