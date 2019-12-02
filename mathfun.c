#include<stdio.h>
int add(int a, int b){return (a+b);}
int mul(int a, int b){return (a*b);}
void* division(int a , int b){
	if(a==0 || b==0)
		printf("devide by zero error\n");
	return (a/b);
}
int sub(int a, int b){return (a-b);}