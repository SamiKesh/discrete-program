/*C program to implement B.F.S and D.F.S for any graph */

#include<stdio.h>
#include<stdlib.h>
#define max 10
enum{ready,visited};
enum{True,False};
int main()
{
int a[max][max],v,i,j,g,result,ch;
char chr;
int bfs(int[][j],int,int);
int dfs(int[][j],int,int);
printf("Enter the number of vertex : ");
scanf("%d",&v);
printf("Enter the values of adjency matrix\n");
for(i=0;i<v;i++)
{
for(j=0;j<v;j++)
{
scanf("%d",&a[i][j]);
}
printf("\n");
}
printf("The matrix is :-\n");
for(i=0;i<v;i++)
{
for(j=0;j<v;j++)
{
printf("%d",a[i][j]);
}
printf("\n");
}
while(1)
{
printf("Enter the node you want to search : ");
scanf("%d",&g);/*Read target node from user*/
printf("\n..........Menu..........\n");
printf("1>.....Breadh First Search.....\n2>.....Depth First Search.....\n");
printf("Enter choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("Traversed path for B.F.S : ");
result=bfs(a,v,g);
break;
}
case 2:
{
printf("Traversed path for D.F.S :  ");
result=dfs(a,v,g);
break;
}
default:
{
printf("!!!!!Error!!!!!n!!!!!Invalid choice given!!!!!");
return;
}
}
if(result==1)/*result stores the output of graph searching i.e. successful or unsuccessful*/
printf("\nSearch successful,target node is found.n");
else
printf("\nSearch unsuccessful, entire graph is traversed but target node is not found.n");
printf("\nWant to continue?(give 1 for yes) : ");/*The program will continue until the user wants to exit*/
scanf("%d",&chr);
if(chr!=1)
{
printf("\nThe program will exit now.");
return 0;
}
}
}
/*The input graph,number of vertices and the target node are passed as parameters*/
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
if(s==g)/*Check whether starting node is our target*/
{
printf("v%d",s);
f=1;
return f;
}
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
if(j==g)/*Checking whether any successor node of t is our target*/
{
printf("v%d",j);
f=1;
return f;
}
if(status[j]!=visited)
{
insert(open,j,&rear);/*Insert only that successors of t which are not already
visited*/
status[j]=visited;/*State of all successors become visited*/
}
}
}

}
printf("b bb ");
return f;
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






/*The input graph,number of vertices and the target node are passed as parameters*/
int dfs(int a[max][max],int v,int g)
{
int s,i,t,j,open[max],status[max],f;
void push(int[],int,int*);
int pop(int[],int*);
int stack_empty(int*);
f=0;/*If search will be successful then value of f will be changed to 1*/
int top=0;
for(i=0;i<v;i++)
status[i]=ready;/*Initially all the nodes are in ready state*/
s=0;/*Searchig starts from the first node of the graph*/
if(s==g)/*Check whether starting node is our target*/
{
printf("v%d",s);
f=1;
return f;
}
push(open,s,&top);/*Insert the starting node in the stack*/
while(stack_empty(&top)==False)/*Searching will be considered until stack is empty*/
{
t=pop(open,&top);/*t contains the node just deleted from the stack*/
printf("v%d->",t);
status[t]=visited;/*The state of the deleted node becomes visited*/
for(j=0;j<v;j++)
{
if(a[t][j]==1)
{
if(j==g)/*Checking whether any successor node of t is our target*/
{
printf("v%d",j);
f=1;
return f;
}

if(status[j]!=visited)
{
push(open,j,&top);/*Insert only that successors of t which are not already visited*/
status[j]=visited;/*State of all successors become visited*/
}

}
}
}

return f;
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
