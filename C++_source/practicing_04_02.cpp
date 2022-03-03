#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 100
#define MAXQSIZE 100
#define STACKINCREMENT 10


typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct {//顺序队列的表示 
	BiTree *base;
	int front;
	int rear;
}SqQueue;

typedef struct SqStack{
	BiTree *top;
	BiTree *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)//初始化顺序栈
{
	S.base=new BiTree[MAXSIZE];
	if(!S.base)exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 0;
}
int Push(SqStack &S,BiTree e)//入栈
{
	if(S.top-S.base==MAXSIZE)
	{
		S.base=(BiTree*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(BiTree));
	    if(!S.base) exit(-1);
		S.stacksize+=STACKINCREMENT;
		S.top = S.base+S.stacksize; 
	}
	*S.top++=e;
	return 0;
}
int Pop(SqStack &S,BiTree &e)//出栈
{
	if(S.top==S.base)
	{
		cout<<"栈空"<<endl;
		return -2;
	}
	e=*--S.top;
	return 0;
}
bool StackEmpty(SqStack &S)//判断栈是否为空
{
	if(S.base==S.top)
		return true;
	else
		return false;
}
BiTree GetTop(SqStack &S)//得到栈顶 
{
	BiTree e;
	if(S.base==S.top)exit(-1);
	e=*(S.top-1);
	return e;
}

int InitQueue(SqQueue &Q){//队列初始化 
	Q.base=new BiTree[MAXQSIZE];
	if(!Q.base)exit(-1);
	Q.front=0;
	Q.rear=0;
	return 0;
}
int EnQueue(SqQueue &Q,BiTree e){//循环队列的入队
	if((Q.rear+1)%MAXQSIZE==Q.front)return -1;//队满 
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 0;
}
int DeQueue(SqQueue &Q,BiTree &e){//出队
	if(Q.front==Q.rear)return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return 0;
}


int CreateBiTree(BiTree &T)//创建二叉树
{
	char ch;
	ch=getchar();
	if(ch=='#')
		T=NULL;
	else
	{
		T=new BiTNode;
		if(!T)exit(-1);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return 0;
}

int PreOrderTraverse(BiTree &T)//先序递归遍历
{
	if(T==NULL)return -1;
	else
	{
		cout<<T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return 0;
}

int InOrderTraverse(BiTree &T)//中序递归遍历
{
	if(T==NULL)return -1;
	else
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
	return 0;
}

int PostOrderTraverse(BiTree &T)//后序递归遍历
{
	if(T==NULL)return -1;
	else
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
	}
	return 0;
}

//非递归算法
int InOrderTraverse2(BiTree &T)
{
	SqStack S;
	InitStack(S);//建立一个栈
	BiTNode* p=T;
	BiTNode* q;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);//根结点进栈，遍历左子树
			p=p->lchild;
		}
		else
		{
			Pop(S,q);
			cout<<q->data;
			p=q->rchild;
		}
	}
	return 0;
}
int PreOrderTraverse2(BiTree &T)
{
	SqStack S;
	InitStack(S);//建立一个栈
	BiTNode* p=T;
	BiTNode* q;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			cout<<p->data;
			Push(S,p);//根结点进栈，遍历左子树
			p=p->lchild;
		}
		else
		{
			Pop(S,q);
			p=q->rchild;
		}
	}
	return 0;
}
int PostOrderTraverse2(BiTree T)
{
	SqStack S;
	InitStack(S);//建立一个栈
	BiTNode* p=T;
	BiTNode* q;
	BiTNode* m;
	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);//根结点进栈，遍历左子树
			p=p->lchild;
		}
		else
		{
			q = GetTop(S);
			p=q->rchild;
			if(!p){
				cout<<q->data;
				Pop(S,q);
				m=q;
				if(!StackEmpty(S)){
					q = GetTop(S);
					if(m!=q->lchild){
						q->rchild=NULL;
					}
				}
			}
		}
	}
	return 0;
}

//层序遍历
int LevelOrder(BiTree &T)
{
	BiTNode* p;
	SqQueue Q;
	InitQueue(Q);
	EnQueue(Q,T);
	while(Q.front!=Q.rear)
	{
		DeQueue(Q,p);
		cout<<p->data;
		if(p->lchild!=NULL)EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)EnQueue(Q,p->rchild);
	}
	return 0;
}

//复制二叉树
int CopyBiTree(BiTree &T,BiTree &NewT){
	if(T==NULL){
		NewT = NULL;
		return 0;
	}
	else{
		NewT = new BiTNode;
		NewT->data = T->data;
		CopyBiTree(T->lchild,NewT->lchild);
		CopyBiTree(T->rchild,NewT->rchild);
	}
	return 0;
}

int main()
{
	BiTree T,T1;
	cout<<"输入二叉树："<<endl;
	CreateBiTree(T);
	CopyBiTree(T,T1);

	cout<<"先序遍历:"<<endl;
	PreOrderTraverse(T);
	cout<<endl;

	cout<<"中序遍历:"<<endl;
	InOrderTraverse(T);
	cout<<endl;

	cout<<"后序遍历:"<<endl;
	PostOrderTraverse(T);
	cout<<endl;
	
	cout<<"非递归先序遍历:"<<endl;
	PreOrderTraverse2(T);
	cout<<endl;
	
	cout<<"非递归中序遍历:"<<endl;
	InOrderTraverse2(T);
	cout<<endl;

	cout<<"非递归后序遍历:"<<endl;
	PostOrderTraverse2(T1);
	cout<<endl;
	
	cout<<"层序遍历:"<<endl;
	LevelOrder(T);
	cout<<endl;
	
	return 0;
}
//测试用例：-+a##*b##-c##d##/e##f##
