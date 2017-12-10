#include<stdio.h>
#include<conio.h>
#define max 10
const int inf=9999;

int minDistance(int a[max][max],int n)
{
int i,j,k;
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
	return a[max][max];
}
int minCost(int c[max],int n)
{
	int i,min=c[0];
	for(i=0;i<n;i++)
	{
	if(min>=c[i])
	min=c[i];
    }  
	return min;
	
}
int main()
{
	int v,i,j,Total=0;
	printf("Enter the no. of city: ");
	scanf("%d",&v);
	int a[v][v],cost[v],visited[v],b[v][v];
	printf("Enter the adjacency matrix: \n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		scanf("%d",&b[i][j]);
	}
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(b[i][j]==0)
			a[i][j]=inf;
			else
			a[i][j]=b[i][j];
		}
		visited[i]=0;
	}
	a[v][v]=minDistance(a,v);
	//minCost(0);
	printf("\nThe matrix is: \n\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		printf("%d\t",a[i][j]);
		
		printf("\n");
	}
	printf("\n\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			cost[j]=a[i][j];
		}
	    
	    if(visited[i]!=1)
	    {
		Total=Total+minCost(cost,v);
		printf("C%d->",i+1);
	    }
		visited[i]=1;
	}
	printf("C1");
	printf("\n\nThe total cost is: %d",Total);
	return 0;
}


