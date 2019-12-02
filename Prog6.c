#include <stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
  int size,page;
  printf("Enter memory size\n");
  scanf("%d",&size );//32 bit
  printf("Enter page size");
  scanf("%d",&page);//4kb
  long memory=pow(2,size),req;
  printf("Enter request\n" );
  scanf("%ld",&req );
//Do it for multiple requests.....
  if(req>memory)
  printf("Memory cannot be allocated for the process\n" );

  else
  {
    //find no of pages
    int n_page=req/page;
    int offset=req%page;
    printf("The number of pages is %d and offset is %d\n",n_page,offset );
  }
}
