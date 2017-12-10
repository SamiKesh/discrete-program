/*C program to implement B.F.S and D.F.S for any graph */

#include<stdio.h>
#include<stdlib.h>
#define max 10
enum{ready,visited};
enum{True,False};
int main()
{
int a[max][max],v,i,j,c[max],odd=0,result,ch,c1=0,p=0,m=0;
char chr;
//int bfs(int[][j],int,int);
int dfs(int[][j],int,int,int);
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
	a[u1][u2]++;
	a[u2][u1]++;
}
printf("The matrix is :-\n");
for(i=0;i<v;i++)
{
	c[i]=0;
for(j=0;j<v;j++)
{
if(a[i][j]!=0)
{
if(i==j)
c[i]=c[i]+2;
else
c[i]=c[i]+1;
}
printf("%d ",a[i][j]);
printf("%d",c[i]);
}
if(c[i]%2!=0)
{
odd=odd+1;
p=i;
m=(c[i]+1)/2;
}
printf("\n");
}
printf("Traversed path for D.F.S :  ");
result=dfs(a,v,p,m);
printf("%d",odd);
if(v==result)
{
if(odd==0)
{
printf("v%d",p);	
printf("\nEuler circuit");
}
else if(odd==2)
{
for(i=0;i<v;i++)
{
if(c[i]%2!=0 && i!=p)
printf("v%d",i);
}	
printf("\nEuler Path");
}
else 
printf("\nNeither Euler Path nor euler circuit");
}
else
printf("\nThe graph is not connected %d",result);
}

/*The input graph,number of vertices and the target node are passed as parameters*/
int dfs(int a[max][max],int v,int p,int m)
{
int s,i,t,j,open[max],status[max],f,c1[max],c2=0;
void push(int[],int,int*); 
int stack_empty(int*);
//f=0;/*If search will be successful then value of f will be changed to 1*/
int top=0;
for(i=0;i<v;i++)
{
status[i]=ready;/*Initially all the nodes are in ready state*/
c1[i]=0;
}
s=p;/*Searchig starts from the first node of the graph*/

push(open,s,&top);/*Insert the starting node in the stack*/
while(stack_empty(&top)==False)/*Searching will be considered until stack is empty*/
{
t=pop(open,&top);/*t contains the node just deleted from the stack*/
printf("v%d->",t);
if(t==p&&(m-1)>0)
status[t]=ready;/*The state of the deleted node becomes visited*/
else
{
status[t]=visited;
c1[t]=1;
}
for(j=0;j<v;j++)
{
if(a[t][j]!=0)
{
	if(j==p)
	m--;
if(status[j]!=visited && j!=p)
{
push(open,j,&top);/*Insert only that successors of t which are not already visited*/
status[j]=visited;/*State of all successors become visited*/
c1[j]=1;
}
if(status[j]!=visited && j==p && m==0)
{
push(open,j,&top);/*Insert only that successors of t which are not already visited*/
status[j]=visited;/*State of all successors become visited*/
c1[j]=1;
m--;
}
a[t][j]=0;
}
}
}
for(i=0;i<v;i++)
{
if(c1[i]==1)
c2++;
}
return c2;
}
void push(int stack[],int data,int* top)
{
if(*top>=max)
{
printf("Error overflow");
return;
}
stack[*top]=data;
(*top)++;
}
int pop(int stack[],int *top)
{
int data;
(*top)--;
data=stack[*top];
return data;
}
int stack_empty(int *top)
{
if(*top==0)
return True;
else
return False;
}
 
