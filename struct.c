#include <stdio.h>

struct employee
{
	char    name[20];
	char    resNum[13];
	int     pay;
} ;

int main()
{
	struct employee emp;

	printf("이름입력:"); scanf("%s", emp.name);
	printf("주민등록번호 입력:"); scanf("%s", emp.resNum);
	printf("급여정보 입력:"); scanf("%d", &(emp.pay));
	printf("--출력--\n");
	printf("이름:%s\n", emp.name);
	printf("주민등록번호:%s\n", emp.resNum);
	printf("급여정보:%d\n", emp.pay);
	return 0;
}