//链栈的实现
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;



//链栈的初始化
int InitStack(LinkStack &S)
{
	S=NULL;
	return 0;
}

//判断栈是否为空
bool StackEmpty(LinkStack &S)
{
	if(S==NULL)
		return true;
	else
		return false;
}

//入栈
int Push(LinkStack &S,int e)
{
	StackNode* p=new StackNode;
	p->data=e;
	p->next=S;
	S=p;
	return 0;
}

//出栈
int Pop(LinkStack &S,int &e)
{
	if(S==NULL)exit(-1);
	StackNode* p=S;
	e=S->data;
	S=S->next;
	delete p;
	return 0;
}

//取栈顶元素
int GetTop(LinkStack &S)
{
	if(S!=NULL)
		return S->data;
	else
	{
		cout<<"栈空！"<<endl;
		exit(-1);
	}		
}

//进制转换
void convert(int N,int d)//将十进制N转换成d进制数输出
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

//括号匹配
void match()
{
}


int main()
{
	convert(10,8);
	return 0;
}