
#include<stdio.h>
#include<conio.h>

#include<stdlib.h>
#define max 10
//enum{ready,visited};
//enum{True,False};
int main()
{
int a[max][max],v,i,j,c[max],f=0;
printf("Enter the number of vertex : ");
scanf("%d",&v);
int u1,u2,e;
printf("Enter the values of edges\n");
scanf("%d",&e);
for(i=0;i<v;i++)
{
for(j=0;j<v;j++)
{
a[i][j]=0;
}
}
for(i=0;i<e;i++)
{
	scanf("%d %d",&u1,&u2);
	a[u1][u2]=1;
	a[u2][u1]=1;
}
printf("The matrix is :-\n");
for(i=0;i<v;i++)
{
	c[i]=0;
for(j=0;j<v;j++)
{
if(a[i][j]==1)	
c[i]=c[i]+1;
printf("%d ",a[i][j]);
}
printf("\n");
}
for(i=0;i<v;i++)
{
	for(j=i+1;j<v;j++)
	{
		if((c[i]+c[j])<(v-1))
		{
		f=1;
		break;
	}
	}
	
}
if(f==0)
printf("Hamiltonian Circuit Exist");
else
printf("No Hamiltonian Path");
return 0;
}
