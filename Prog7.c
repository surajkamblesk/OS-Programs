#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int size,h=0,i=0,a[20],b[20],original_size,maxsize;
int allocate()
{//save sizes allocated to array
  int req;

  //int i=0;
int t,u,z=0;
  int actual=original_size;
      if(size<=0)
      {
      printf("No space available\n");
      exit(0);
      }
      printf("\nEnter required allocation size\n" );
      scanf("%d",&req);
      if(req<=maxsize){
      int small;
      int valid=0;
      z=0;
      while((t=actual/pow(2,z))>=req)
      {
          u=t;
          z+=1;
      }//t is lesser than req
      //printf("%d is the size required\n",u);
      size-=u;
      a[i++]=u;
      b[h++]=req;
      //printf("%d size \n",size);
      z=0;
      while((size/pow(2,z))>=1)
      {
          z+=1;
      //    printf("z is %d",z);
      }
      maxsize=pow(2,z-1);
    //  printf("%d maxsize \n",maxsize);

      }
      else
      {
          printf("Cannot allocate. Memory Full\n");
          exit(0);
      }


}
void deallocate(int n)
{//deallocate the required size so as to add space to memory. search memory for reuired size, and delete it
  if(i==0)
{  printf("memory not yet allocated\n" ); return;}
int flag=0;
  for(int j=0;j<=i;j++)
  {

    if(a[j]==n)
    {
      flag=1;
      for(int k=j;k<i;k++)
      {
        a[k]=a[k+1];//shift backwards by one essentially deleting the entity
        b[k]=b[k+1];
      }
      size=size+n;//assume memory internally shifted upwards cause solving it otherwise is madness
	break;//extra shifting if more than one occurance of the same number
    }

  }
  if(flag==0)
  printf("Not found in memory\n");

}

int main()
{
  printf("Enter memory size\n");
  scanf("%d",&size);
  original_size=size;
  maxsize=size;
  int mem;
  int choice;
  while (1)
  {


    printf("Enter 1 to allocate,2 to deallocate\n");
    scanf("%d",&choice );
    switch (choice) {
      case 1:allocate();
      break;
      case 2:printf("Enter memory size to deallocate\n");
      scanf("%d",&mem);
      deallocate(mem);
      break;
    }
    //contents of a and b
  //  printf("i=%d\n",i );
    printf("Required\t\tAllocated\n" );
    for(int k=0;k<=i;k++)
    {
      printf("%d\t\t\t%d\n",b[k],a[k]);
    }
  }
}
