#include<stdio.h>
#include<stdlib.h>
#include"mathfun.c"
void main()
{
	int a,b;
	printf("enter a and b\n");
	scanf("%d%d",&a,&b);
	printf("a+b = %d\n",add(a,b));
	printf("a-b = %d\n",sub(a,b));
	printf("a/b = %lf\n",division(a,b));
	printf("a*b = %d\n",mul(a,b));



}