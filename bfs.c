/*C program to implement B.F.S and D.F.S for any graph */

#include<stdio.h>
#include<stdlib.h>
#define max 10
enum{ready,visited};
enum{True,False};
int main()
{
int a[max][max],v,i,j,c[max],odd=0,result,p=0;
char chr;
int bfs(int[][j],int,int);

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
for(j=0;j<v;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
printf("Traversed path for B.F.S :  ");
result=bfs(a,v,p);
}


int bfs(int a[max][max],int v,int g)
{
int s,i,t,j,open[max],status[max],f;
void insert(int[],int,int*);
int delete(int[],int*);
int queue_empty(int*,int*);
f=0;/*If search will be successful then value of f will be changed to 1*/
int front=0;
int rear=0;
for(i=0;i<v;i++)
status[i]=ready;/*Initially all the nodes are in ready state*/
s=0;/*Searchig starts from the first node of the graph*/

insert(open,s,&rear);/*Insert the starting node in the queue*/
while((queue_empty(&front,&rear))==False)/*Searching will be considered until queue is empty*/
{
t=delete(open,&front);/*t contains the node just deleted from the queue*/
printf("v%d->",t);
status[t]=visited;/*The state of the deleted node becomes visited*/
for(j=0;j<v;j++)
{
if(a[t][j]==1)
{

if(status[j]!=visited)
{
insert(open,j,&rear);/*Insert only that successors of t which are not already
visited*/
status[j]=visited;/*State of all successors become visited*/
}
}
}

}
return;
}
void insert(int queue[],int data,int* rear)
{
if(*rear>=max)
{
printf("Error overflow");
return;
}
queue[*rear]=data;
(*rear)++;
}
int delete(int queue[],int* front)
{
int data;
data=queue[*front];
(*front)++;
return data;
}

int queue_empty(int* front,int* rear)
{
if(*front==*rear)
return True;
else
return False;
}
