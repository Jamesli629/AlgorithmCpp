/*
	Name: ͼ�ı��� 
	Author: ��س� 
	Date: 15/12/21 18:33
	Description: ͼ�ĵݹ���ȹ�ȱ����ͷǵݹ���ȱ���
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
#define MVNum 100
#define MAX 100
#define MAXQSIZE 100

//˳��ջ�ı�ʾ
#define MAXSIZE 100
#define STACKINCREMENT 10
typedef struct SqStack{
	int *top;
	int *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)//��ʼ��˳��ջ
{
	S.base=new int[MAXSIZE];
	if(!S.base)exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 0;
}

bool StackEmpty(SqStack &S)//�ж�ջ�Ƿ�Ϊ��
{
	if(S.base==S.top)
		return true;
	else
		return false;
}

int StackLength(SqStack &S)//��˳��ջ�ĳ���
{
	return S.top-S.base;
}
int Push(SqStack &S,int e)//��ջ
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

int Pop(SqStack &S,int &e)//��ջ
{
	if(S.top==S.base)
	{
		cout<<"ջ��"<<endl;
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
typedef struct {//˳����еı�ʾ 
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q){//���г�ʼ�� 
	Q.base=new int[MAXQSIZE];
	if(!Q.base)exit(-1);
	Q.front=0;
	Q.rear=0;
	return 0;
}

int QueueLength(SqQueue &Q){//���еĳ���
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//ѭ�����е����
int EnQueue(SqQueue &Q,int e){
	if((Q.rear+1)%MAXQSIZE==Q.front)return -1;//���� 
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 0;
}

//����
int DeQueue(SqQueue &Q,int &e){
	if(Q.front==Q.rear)return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return 0;
}
typedef  int InfoType;
typedef  int VertexType;

typedef struct ArcNode{//�ߵĽ��ṹ
	int adjvex;  //��������ָ��Ķ����λ��
	struct ArcNode *nextarc;
	InfoType info;  //�ߵ�������Ϣ 
}ArcNode;
typedef struct VNode{//����Ľ��ṹ 
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum];//AdjList��ʾ�ڽӱ�����

typedef struct{//ͼ�ı�ʾ�ṹ 
	AdjList vertices;    //��Ÿ���������ڽӱ�
	int vernum,arcnum;   //��ǰͼ�Ķ������ͻ��� 
}ALGraph;

//���ڽӱ���ͼ���㷨˼�룺
//1.�����ܵĶ������ͱ���
//2.��������� ��1�����붥������Ϣ��2����ͷ��ָ��ΪNULL
//3.�����ڽӱ� ��1���ҵ��ñߵ������ڽӵ㣨2�������߽�㣨3�����߽����뵽�����Ӧ���ڽӱ���
int LocateVex(ALGraph G,VertexType v)//��ͼ���ҵ�v��Ӧ���±�
{
	int locate=-1;
	for(int i=0;i<G.vernum;++i)
	{
		if(G.vertices[i].data==v)locate = i;
	}
	return locate;
}
int CreateUDG(ALGraph &G,string *map)//����ͼ
{
	cout<<"������ͼ���ܶ��������ܱ�����"<<endl;
	cin>>G.vernum>>G.arcnum;
	cout<<"�����붥�����Ϣ��"<<endl;
	for(int i=0;i<G.vernum;++i)//��������� 
	{
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}
	cout<<"���������������������(��������Ӧ������):"<<endl;
	for(int k=0;k<G.arcnum;++k)
	{
		VertexType v1,v2;//����������������
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
	cout<<"ͼ���ڽӱ�����:"<<endl;
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
//�ݹ�ʵ��������ȱ��� 
int DFS1(ALGraph G,int v,string *map)//��ӡ�߼� 
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
int DFS2(ALGraph G,int v,string *map)//��ӡ���� 
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

//������ȱ��� 
int BFS1(ALGraph G,int v,string *map)//��ӡ���� 
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
			if(visit[p->adjvex]==0)//δ�����ʹ�
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
int BFS2(ALGraph G,int v,string *map)//��ӡ�߼� 
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
int DFS3(ALGraph G,int v,string *map)//��ջʵ��������ȱ��� 
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
	string map[25]={"��³ľ��","������","���ͺ���","����",
	                "����","����","����","���",
					"����","����","����","֣��",
					"����","�ɶ�","�人","�Ϻ�",
					"����","����","����","�ϲ�",
					"����","����","����","����","����"};
	int v;
	ALGraph G;
	CreateUDG(G,map);
	PrintGraph(G,map);
	cout<<"�������������ʼλ��(�±�)��"<<endl;
	cin>>v;
	BFS1(G,v,map);
	BFS2(G,v,map);
	DFSTraverse2(G,v,map);
	DFSTraverse1(G,v,map);
	DFS3(G,v,map);
	return 0;
}
