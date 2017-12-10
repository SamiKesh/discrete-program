/*C program to implement relation for any graph */

#include<stdio.h>
#include<stdlib.h>
#define max 10
int main()
{
int a[max][max],v,i,j,c=0,c1=0,p=0,k,flag=0;
char chr;
printf("Enter the number of vertex : ");
scanf("%d",&v);
printf("enter adjacency matrix\n");
for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            scanf("%d",&a[i][j]);
        printf("\n");
    }
printf("The matrix is :-\n");
for(i=0;i<v;i++)
{
for(j=0;j<v;j++)
{
printf("%d ",a[i][j]);
}

printf("\n");
}
p=((v-1)*v);
for(i=0;i<v;i++)
{
	for(j=0;j<v;j++)
	{
		if(i==j)
		{
		if(a[i][j]==1)
		c++;
    	}
    	else
    	{
    		if(a[i][j]==a[j][i])
    		c1++;
		}
		if(a[i][j]==1)
		{
			for(k=0;k<v;k++)
			{
				if(a[j][k]==1)
				{
					if(a[k][i]!=1)
					{
						flag=1;
						break;
					}
				}
			}
		}
	}
}
if(c==v)
printf("\nRelation is Reflexive");
else
printf("\nRelation is not Reflexive");
if(c==0)
printf("\nRelation is Irreflexive");
else
printf("\nRelation is not Irreflexive");
if(c1==p)
printf("\nRelation is Symmetric");
else
printf("\nRelation is  Asymmetric");
if(flag==0)
printf("\nRelation is Transitive");
else
printf("\nRelation is not Transitive");
if(c==0 && c1!=p)
printf("\nRelation is Antisymmetric");
else
printf("\nRelation is Antisymmetric");
return 0;

}
