#include<stdio.h>
struct test
{
	int i;
	char *c;
};
struct test st[]={{5,"become"},{4,"better"},{6,"jungle"},{8,"ancestor"},{7,"broltr"}};
void main()
{
	struct test *p=st;
	p+=1;
	printf("%s",++(p++->c));
	printf(" %c",*++p->c);
printf(" %d",p[0].i);
	printf(" %s",p->c); 
	
}
