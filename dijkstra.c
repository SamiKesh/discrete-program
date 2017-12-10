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
    printf("adjacency matrix of cost of edges\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(a[j][k]>a[j][i]+a[i][k])
                    a[j][k]=a[j][i]+a[i][k];
            }
        }
    }

printf("adjacency amatrix of lowest cost between the vertices\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
        printf("%d\t",a[i][j]);
    printf("\n");
}

return 0;
}
