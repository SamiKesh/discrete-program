#include<stdio.h>

const int inf=99999;

int main()
{
    int n,i,j,k;
    printf("enter number of vertices\n");
    scanf("%d",&n);
    int a[n][n],v[n][n];

printf("enter adjacency matrix\n");
for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&v[i][j]);
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(v[i][j]==0)
                a[i][j]=inf;
            else
                a[i][j]=v[i][j];
        }
    }

a[0][0]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(a[j][k]>a[j][i]+a[i][k])
                   {
                    if(j==k)
                    a[j][k]=0;
                    else
                    a[j][k]=a[j][i]+a[i][k];
                   }
            }
        }
    }


printf("\nadjacency amatrix of lowest cost between the vertices\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
        printf("%d\t",a[i][j]);
    printf("\n");
}

int b[n],max;
 for(i=0;i<n;i++)
    {
        max=0;
        for(j=0;j<n;j++)
        {
        if(a[i][j]>=max)
        max=a[i][j];
        }
        b[i]=max;
    }

printf("\n\nECCENTRICITIES OF VERTICES\n");
for(i=0;i<n;i++)
printf("%d\t",b[i]);
printf("\n");

int min=b[0],count=0;
char c[n];
for(i=0;i<n;i++)
    if(b[i]<=min)
{
    min=b[i];
}

for(i=0;i<n;i++)
if(b[i]==min)
{
c[i]='C';
count++;
}
else
c[i]='N';

printf("\n\nCENTRES OF GRAPH DENOTED BY C ARE \n");
for(i=0;i<n;i++)
printf("%c\t",c[i]);
printf("\n\nNO. OF CENTERS = %d\n",count);

return 0;
}

