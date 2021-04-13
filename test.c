#include <stdio.h>
int main() 
{
	char i = '3';
	char *ptr = &i;
	long long num;

	num = (long long)ptr;

	printf("%llx\n", num);
	printf("%p\n", ptr);

/*  int i = 123;
  int j = -123;
  double f = 3.141592;
  printf("|%05.10d|\n", i);
*/

}