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
//int bfs(int[][j],int,int);
int dfs(int[][j],int,int);
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
printf("Traversed path for D.F.S :  ");
result=dfs(a,v,p);
}

/*The input graph,number of vertices and the target node are passed as parameters*/
int dfs(int a[max][max],int v,int p)
{
int s,i,t,j,open[max],status[max],f;
void push(int[],int,int*); 
int stack_empty(int*);
//f=0;/*If search will be successful then value of f will be changed to 1*/
int top=0;
for(i=0;i<v;i++)
{
status[i]=ready;/*Initially all the nodes are in ready state*/
}
s=p;/*Searchig starts from the first node of the graph*/

push(open,s,&top);/*Insert the starting node in the stack*/
while(stack_empty(&top)==False)/*Searching will be considered until stack is empty*/
{
t=pop(open,&top);/*t contains the node just deleted from the stack*/
printf("v%d->",t);
/*The state of the deleted node becomes visited*/
status[t]=visited;
for(j=0;j<v;j++)
{
if(a[t][j]!=0)
{

if(status[j]!=visited)
{
push(open,j,&top);/*Insert only that successors of t which are not already visited*/
status[j]=visited;/*State of all successors become visited*/
}

}
}
}

return;
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
 
