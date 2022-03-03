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

typedef struct {//˳����еı�ʾ 
	BiTree *base;
	int front;
	int rear;
}SqQueue;

typedef struct SqStack{
	BiTree *top;
	BiTree *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)//��ʼ��˳��ջ
{
	S.base=new BiTree[MAXSIZE];
	if(!S.base)exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 0;
}
int Push(SqStack &S,BiTree e)//��ջ
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
int Pop(SqStack &S,BiTree &e)//��ջ
{
	if(S.top==S.base)
	{
		cout<<"ջ��"<<endl;
		return -2;
	}
	e=*--S.top;
	return 0;
}
bool StackEmpty(SqStack &S)//�ж�ջ�Ƿ�Ϊ��
{
	if(S.base==S.top)
		return true;
	else
		return false;
}
BiTree GetTop(SqStack &S)//�õ�ջ�� 
{
	BiTree e;
	if(S.base==S.top)exit(-1);
	e=*(S.top-1);
	return e;
}

int InitQueue(SqQueue &Q){//���г�ʼ�� 
	Q.base=new BiTree[MAXQSIZE];
	if(!Q.base)exit(-1);
	Q.front=0;
	Q.rear=0;
	return 0;
}
int EnQueue(SqQueue &Q,BiTree e){//ѭ�����е����
	if((Q.rear+1)%MAXQSIZE==Q.front)return -1;//���� 
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 0;
}
int DeQueue(SqQueue &Q,BiTree &e){//����
	if(Q.front==Q.rear)return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return 0;
}


int CreateBiTree(BiTree &T)//����������
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

int PreOrderTraverse(BiTree &T)//����ݹ����
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

int InOrderTraverse(BiTree &T)//����ݹ����
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

int PostOrderTraverse(BiTree &T)//����ݹ����
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

//�ǵݹ��㷨
int InOrderTraverse2(BiTree &T)
{
	SqStack S;
	InitStack(S);//����һ��ջ
	BiTNode* p=T;
	BiTNode* q;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);//������ջ������������
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
	InitStack(S);//����һ��ջ
	BiTNode* p=T;
	BiTNode* q;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			cout<<p->data;
			Push(S,p);//������ջ������������
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
	InitStack(S);//����һ��ջ
	BiTNode* p=T;
	BiTNode* q;
	BiTNode* m;
	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);//������ջ������������
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

//�������
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

//���ƶ�����
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
	cout<<"�����������"<<endl;
	CreateBiTree(T);
	CopyBiTree(T,T1);

	cout<<"�������:"<<endl;
	PreOrderTraverse(T);
	cout<<endl;

	cout<<"�������:"<<endl;
	InOrderTraverse(T);
	cout<<endl;

	cout<<"�������:"<<endl;
	PostOrderTraverse(T);
	cout<<endl;
	
	cout<<"�ǵݹ��������:"<<endl;
	PreOrderTraverse2(T);
	cout<<endl;
	
	cout<<"�ǵݹ��������:"<<endl;
	InOrderTraverse2(T);
	cout<<endl;

	cout<<"�ǵݹ�������:"<<endl;
	PostOrderTraverse2(T1);
	cout<<endl;
	
	cout<<"�������:"<<endl;
	LevelOrder(T);
	cout<<endl;
	
	return 0;
}
//����������-+a##*b##-c##d##/e##f##
