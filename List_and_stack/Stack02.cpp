//��ջ��ʵ��
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;



//��ջ�ĳ�ʼ��
int InitStack(LinkStack &S)
{
	S=NULL;
	return 0;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStack &S)
{
	if(S==NULL)
		return true;
	else
		return false;
}

//��ջ
int Push(LinkStack &S,int e)
{
	StackNode* p=new StackNode;
	p->data=e;
	p->next=S;
	S=p;
	return 0;
}

//��ջ
int Pop(LinkStack &S,int &e)
{
	if(S==NULL)exit(-1);
	StackNode* p=S;
	e=S->data;
	S=S->next;
	delete p;
	return 0;
}

//ȡջ��Ԫ��
int GetTop(LinkStack &S)
{
	if(S!=NULL)
		return S->data;
	else
	{
		cout<<"ջ�գ�"<<endl;
		exit(-1);
	}		
}

//����ת��
void convert(int N,int d)//��ʮ����Nת����d���������
{
	LinkStack S;
	InitStack(S);
	do{
		Push(S,N%d);
		N=N/d;
	}while(N!=0);
	while(!StackEmpty(S))
	{
		int e;
		Pop(S,e);
		cout<<e;
	}
	cout<<endl;
}

//����ƥ��
void match()
{
}


int main()
{
	convert(10,8);
	return 0;
}