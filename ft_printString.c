#include "ft_printf.h"

char	*fillChar(va_list ap, char *toPrint)
{
	toPrint = (char*)malloc(sizeof(temp) + 1);
	toPrint[0] = va_arg(ap, int);
	toPrint[1] = '\0';
	return (toPrint);
}

char	*fillPtr(va_list ap, char *toPrint)
{
	long long	temp;

	toPrint = (char*)malloc(15);
	temp = va_arg(ap, long long);
	temp / 16
	toPrint[14] = '\0';

	return (toPrint);
}
