/*
	Name: 图的遍历 
	Author: 李柏潮 
	Date: 15/12/21 18:33
	Description: 图的递归深度广度遍历和非递归深度遍历
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
#define MVNum 100
#define MAX 100
#define MAXQSIZE 100

//顺序栈的表示
#define MAXSIZE 100
#define STACKINCREMENT 10
typedef struct SqStack{
	int *top;
	int *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)//初始化顺序栈
{
	S.base=new int[MAXSIZE];
	if(!S.base)exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 0;
}

bool StackEmpty(SqStack &S)//判断栈是否为空
{
	if(S.base==S.top)
		return true;
	else
		return false;
}

int StackLength(SqStack &S)//求顺序栈的长度
{
	return S.top-S.base;
}
int Push(SqStack &S,int e)//入栈
{
	if(S.top-S.base==MAXSIZE)
	{
		S.base=(int*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
	    if(!S.base) exit(-1);
		S.stacksize+=STACKINCREMENT;
		S.top = S.base+S.stacksize; 
	}
	*S.top++=e;
	return 0;
}

int Pop(SqStack &S,int &e)//出栈
{
	if(S.top==S.base)
	{
		cout<<"栈空"<<endl;
		return -2;
	}
	e=*--S.top;
	return 0;
}
int GetTop(SqStack &S,int &e)
{
	if(S.base==S.top)exit(-1);
	e=*(S.top-1);
	return 0;
}
typedef struct {//顺序队列的表示 
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q){//队列初始化 
	Q.base=new int[MAXQSIZE];
	if(!Q.base)exit(-1);
	Q.front=0;
	Q.rear=0;
	return 0;
}

int QueueLength(SqQueue &Q){//队列的长度
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//循环队列的入队
int EnQueue(SqQueue &Q,int e){
	if((Q.rear+1)%MAXQSIZE==Q.front)return -1;//队满 
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 0;
}

//出队
int DeQueue(SqQueue &Q,int &e){
	if(Q.front==Q.rear)return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return 0;
}
typedef  int InfoType;
typedef  int VertexType;

typedef struct ArcNode{//边的结点结构
	int adjvex;  //这条边所指向的顶点的位置
	struct ArcNode *nextarc;
	InfoType info;  //边的其他信息 
}ArcNode;
typedef struct VNode{//顶点的结点结构 
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum];//AdjList表示邻接表类型

typedef struct{//图的表示结构 
	AdjList vertices;    //存放各个顶点的邻接表
	int vernum,arcnum;   //当前图的顶点数和弧数 
}ALGraph;

//用邻接表创建图的算法思想：
//1.输入总的顶点数和边数
//2.建立顶点表 （1）输入顶点表的信息（2）表头的指针为NULL
//3.创建邻接表 （1）找到该边的两个邻接点（2）创建边结点（3）将边结点插入到顶点对应的邻接表中
int LocateVex(ALGraph G,VertexType v)//从图中找到v对应的下标
{
	int locate=-1;
	for(int i=0;i<G.vernum;++i)
	{
		if(G.vertices[i].data==v)locate = i;
	}
	return locate;
}
int CreateUDG(ALGraph &G,string *map)//无向图
{
	cout<<"请输入图的总顶点数和总边数："<<endl;
	cin>>G.vernum>>G.arcnum;
	cout<<"请输入顶点的信息："<<endl;
	for(int i=0;i<G.vernum;++i)//创建顶点表 
	{
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}
	cout<<"请输入边依附的两个顶点(城市所对应的数字):"<<endl;
	for(int k=0;k<G.arcnum;++k)
	{
		VertexType v1,v2;//边依附的两个顶点
		cin>>v1>>v2;
		int i = LocateVex(G,v1); 
		int j = LocateVex(G,v2);
		ArcNode *p1,*p2;
		p1 = new ArcNode;
		p1->adjvex=j;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;
		p2 = new ArcNode;
		p2->adjvex=i;
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;
	}
	return 0;
}

void PrintGraph(ALGraph &G,string *map)
{
	cout<<"图的邻接表如下:"<<endl;
	for(int i=0;i<G.vernum;++i)
	{
		cout<<i<<map[i]<<" ";
		ArcNode *p=G.vertices[i].firstarc;
		while(p!=NULL)
		{
			cout<<p->adjvex<<" ";
			p=p->nextarc;
		}
		cout<<endl;
	}
}
int visited[MAX];
//递归实现深度优先遍历 
int DFS1(ALGraph G,int v,string *map)//打印边集 
{
	ArcNode *p;
	int w;
	visited[v]=1;
	p=G.vertices[v].firstarc;
	while(p!=NULL)
	{
		w=p->adjvex;
		if(visited[w]==0){
			cout<<map[v]<<"->"<<map[w]<<endl;
			DFS1(G,w,map);
		}
		p=p->nextarc;
	}
	return 0;
}
int DFS2(ALGraph G,int v,string *map)//打印序列 
{
	ArcNode *p;
	int w;
	visited[v]=1;
	cout<<map[v]<<" ";
	p=G.vertices[v].firstarc;
	while(p!=NULL)
	{
		w=p->adjvex;
		if(visited[w]==0){
			DFS2(G,w,map);
		}
		p=p->nextarc;
	}
	return 0;
}
int DFSTraverse1(ALGraph G,int v,string *map)
{
	cout<<"DFS:"<<endl;
	for(int i=0;i<G.vernum;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<G.vernum;i++)
	{
		if(visited[i]==0)DFS1(G,v,map);
	}
	cout<<endl;
	return 0;
}
int DFSTraverse2(ALGraph G,int v,string *map)
{
	cout<<"DFS:"<<endl;
	for(int i=0;i<G.vernum;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<G.vernum;i++)
	{
		if(visited[i]==0)DFS2(G,v,map);
	}
	cout<<endl;
	return 0;
}

//广度优先遍历 
int BFS1(ALGraph G,int v,string *map)//打印序列 
{
	cout<<"BFS:"<<endl;
	int w,i;
	ArcNode *p;
	SqQueue queue;
	InitQueue(queue);
	int visit[30];
	for(int i=0;i<G.vernum;i++)
	{
		visit[i]=0;
	}
	cout<<map[v]<<" ";
	visit[v]=1;
	EnQueue(queue,v);
	while(QueueLength(queue)!=0)
	{
		DeQueue(queue,w);
		p=G.vertices[w].firstarc;
		while(p!=NULL)
		{
			if(visit[p->adjvex]==0)//未被访问过
			{
				cout<<map[p->adjvex]<<" ";
				visit[p->adjvex]=1;
				EnQueue(queue,p->adjvex);
			}
			p=p->nextarc;
		}
	}
	cout<<endl;
	return 0;
}
int BFS2(ALGraph G,int v,string *map)//打印边集 
{
	cout<<"BFS:"<<endl;
	int w,i;
	ArcNode *p;
	SqQueue queue;
	InitQueue(queue);
	int visit[30];
	for(int i=0;i<G.vernum;i++)
	{
		visit[i]=0;
	}
	visit[v]=1;
	EnQueue(queue,v);
	while(QueueLength(queue)!=0)
	{
		DeQueue(queue,w);
		p=G.vertices[w].firstarc;
		while(p!=NULL)
		{
			if(visit[p->adjvex]==0)
			{
				cout<<map[w]<<"->"<<map[p->adjvex]<<endl;
				visit[p->adjvex]=1;
				EnQueue(queue,p->adjvex);
			}
			p=p->nextarc;
		}
	}
	cout<<endl;
	return 0;
}
int DFS3(ALGraph G,int v,string *map)//用栈实现深度优先遍历 
{
	int visit[30];
	for(int i=0;i<G.vernum;i++)
	{
		visit[i]=0;
	}
	int w,i,e;
	ArcNode *p;
	cout<<"DFS3:"<<endl;
	SqStack stack;
	InitStack(stack);
	cout<<map[v]<<" ";
	visit[v]=1;
	Push(stack,v);
	while(!StackEmpty(stack))
	{
		GetTop(stack,e);
		p=G.vertices[e].firstarc;
		while(p!=NULL)
		{
			if(visit[p->adjvex]==0)
			{
				cout<<map[p->adjvex]<<" ";
				visit[p->adjvex]=1;
				Push(stack,p->adjvex);
				p=G.vertices[p->adjvex].firstarc;
			}
			else
			{
				p=p->nextarc;
			}
		}
		if(p == NULL)
		{
			Pop(stack,e);
		}
	}
	cout<<endl;
	return 0;
}

int main()
{
	string map[25]={"乌鲁木齐","哈尔滨","呼和浩特","长春",
	                "北京","沈阳","西宁","天津",
					"大连","兰州","西安","郑州",
					"徐州","成都","武汉","上海",
					"昆明","贵阳","株洲","南昌",
					"福州","南宁","柳州","广州","深圳"};
	int v;
	ALGraph G;
	CreateUDG(G,map);
	PrintGraph(G,map);
	cout<<"请输入遍历的起始位置(下标)："<<endl;
	cin>>v;
	BFS1(G,v,map);
	BFS2(G,v,map);
	DFSTraverse2(G,v,map);
	DFSTraverse1(G,v,map);
	DFS3(G,v,map);
	return 0;
}
