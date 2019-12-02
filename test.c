#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a>b?a:b;
}

void knapsack(int w[100], int p[100], int m, int n, int v[100][100])
{
    int i,j;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                v[i][j]=0;
            else if(j<w[i])
                v[i][j]= v[i-1][j];
            else
                v[i][j]= max(v[i-1][j], p[i]+ v[i-1][j-w[i]]);

          //  printf("%d\t", v[i][j]);
        }

        printf("\n");
    }
}

void optimal(int n, int v[100][100], int w[100], int m)
{
    int i,j,d;

    i=n;
    j=m;

    while(i!=0 && j!=0)
    {

        if(v[i][j]==0)
            printf("\n no solution\n");
        if(v[i][j]!=v[i-1][j])
        {
            printf("%d\t", i);
            j=j-w[i];
        }
        i--;
    }
}
int main()
{
    int w[100], p[100], i, n,m, v[100][100],cap;

    printf("n:\n");
    scanf("%d",&n);

    printf("weights:\n\n");
    for(i=1;i<=n;i++)
    scanf("%d", &w[i]);

    printf("profits:\n\n");
    for(i=1;i<=n;i++)
    scanf("%d", &p[i]);

    printf("capacity:\n\n");
    scanf("%d", &m);

    knapsack(w,p,m,n,v);
    optimal(n,v,w,m);

    for(i=0;i<=n;i++)
    {
      for(int j=0;j<=m;j++)
      {
        printf("%d ",v[i][j] );
      }printf("\n" );
    }

    return 0;
}
