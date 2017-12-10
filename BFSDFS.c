#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct node *G[20];
int n;
int visited[MAX];
struct Q
{
int data[MAX];
int R,F;
}Q;
struct node
{
struct node *next;
int vertex;
}node;
int empty(struct Q *p)
{
if(p->R==-1)
{
return(1);
}
return 0;
}
void BFS(int v)
{
int w,i,visited[MAX];
struct Q q;
struct node *p;
q.R=q.F=-1;
for(i=0;i<n;i++)
visited[i]=0;
enqueue(&q,v);
printf("\nvisit %d \n",v);
visited[v]=1;
while(!empty(&q))
{
v=dequeue(&q);
for(p=G[v];p!=NULL;p=p->next)
{
w=p->vertex;
if(visited[w]==0)
{
enqueue(&q,w);
visited[w]=1;
printf("\nvisit %d \n");
}
}
}
}
void DFS(int i)
{
struct node *p;
printf("%d",i);
p=G[i];
visited[i]=1;
while(p!=NULL)
{
i=p->vertex;
if(!visited[i])
DFS(i);
p=p->next;
}
}
int full(struct Q *p)
{
if(p->R==MAX-1)
return(1);
return 0;
}
void enqueue(struct Q *p,int x)
{
if(p->R==-1)
{
p->R=p->F=0;
p->data[p->R]=x;
}
else
{
p->R=p->R+1;
p->data[p->R]=x;
}
}
int dequeue(struct Q *p)
{
int x;
x=p->data[p->F];
if(p->R==p->F)
{
p->R=-1;
p->F=-1;
}
else
{
p->F=p->F+1;
}
return(x);
}
void readgraph()
{
int i,vi,vj,e;
printf("enter no. of vertices\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
G[i]=NULL;
}
printf("enter the no. of edges\n");
scanf("%d",&e);
for(i=0;i<e;i++)
{
printf("enter the edge");
scanf("%d %d",&vi,&vj);
insert(vi,vj);
insert(vj,vi);
}
}
void insert(int vi,int vj)
{
struct node *p,*q;
q=(struct node *)malloc(sizeof(struct node));
q->vertex=vj;
q->next=NULL;
if(G[vi]==NULL)
{
G[vi]=q;
}
else
{
p=G[vi];
while(p->next!=NULL)
{
p=p->next;
p->next=q;
}
}
}

//void enqueue(Q *,int);
//int dequeue(Q *);
//int empty(Q *);
//int full(Q *);
//void BFS(int);
//void readgraph();
//void insert(int,int);
//void DFS(int);


int main()
{
int i,op;
do
{
printf("enter choice\n1.create\n2.BFS\n3.DFS\n4.quit\n");
scanf("%d",&op);
switch(op)
{
case 1:readgraph();break;
case 2:printf("enter the starting node\n");
scanf("%d",&i);
BFS(i);break;
case 3:for(i=0;i<n;i++)
visited[i]=0;
printf("enter the starting node\n");
scanf("%d",&i);
DFS(i);break;

}
}while(op!=4);
return 0;
}

