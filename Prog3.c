#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

void main(int argc,char*argv[])
{
printf("Begin\n\n");
pid_t t;
	t=getpid();
	int a=sched_getscheduler(t);
	if(a==SCHED_FIFO)
	printf("FIFO scheduling\n");
	if(a==SCHED_RR)
	printf("RoundRobin scheduling\n");
	if(a==SCHED_OTHER)
	printf("Default scheduling\n");

	printf("policy=%d\n",a);
	struct sched_param p;
	p.sched_priority=20;
	//printf("%d",(int)p);
	a=SCHED_RR;

	int b=sched_setscheduler(t,a,&p);
	printf("The value of b is:%d\n",b);
	a=sched_getscheduler(t);
	if(a==SCHED_FIFO)
	printf("FIFO scheduling\n");
	if(a==SCHED_RR)
	printf("RoundRobin scheduling\n");
	if(a==SCHED_OTHER)
	printf("Default scheduling\n");
	
	printf("policy=%d",a);
	
}



