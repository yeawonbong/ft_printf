#include <stdio.h>
#include <stdarg.h>

int ft(va_list ap)
{
	printf("2nd = %c\n",va_arg(ap, char));
	return 0;
}
int test(const char *input, va_list ap, ...)
{
	va_list ap;
	va_start(ap, input);
	printf("in test = %d\n", va_arg(ap, int));
	return 0;
}
int main() 
{/*
	char i = '3';
	char *ptr = &i;
	long long num;

	num = (long long)ptr;

	printf("%llx\n", num);
	printf("%p\n", ptr);

	int i = 12345;
	int mi = -12345;
	char *st = "string";
	char c = 'a';
	printf("|%-10c|\n", c);
	printf("|!!>%-10d|\n", i);
	printf("|%-15.3s|\n", st);
	printf("%010%");
	printf("|%10c|\n", c);
	printf("|%-10.3s|\n", st);
	printf("|%.3%|\n");
	printf("|%-30p|", st);*/
	va_list ap;
  test("123",ap, 1,2,3);
	ft(ap);
	printf("1st = %c\n",va_arg(ap, int));
	return 0 ;
}