#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct LNode {
   int value;
   int key;
   struct LNode *next;
} LNode, *LinkList;

LinkList createList ()
{
	int i,val,val0,len;
	cout<<"请输入原始结点的个数:\n";
	cin>>len;
	LinkList pHead=new LNode;
	if(!pHead)
	{
		cout<<"内存分配失败！\n";
		exit(-1);
	}
	if(len<=0)
	{
		exit(-1);
	}
	else
	{
		cout<<"请输入链表的第一个密码:\n";
		cin>>val0;
		pHead->value=1;
		pHead->key=val0;
		pHead->next=NULL;
	}
	LinkList pTail=pHead;//一个指向链表结尾的指针*
	pTail->next=NULL;
	cout<<"请输入密码\n";
	for(i=1;i<len;++i)
	{
		cin>>val;
		LinkList pNew=new LNode;
		if(!pNew)
		{
			cout<<"内存分配失败！\n";
			exit(-1);
		}
		pNew->value=i+1;
		pNew->key=val;
		pTail->next=pNew;
		pNew->next=NULL;
		pTail=pNew;
	}
	pTail->next=pHead;
	return pHead;
}

int length_list(LinkList &pHead)
{
	int len=1;
	LinkList p = pHead->next;
	while(p!=pHead)
	{
		++len;
		p=p->next;
	}
	return len;
}

void delete_list(LinkList &L,int &m)
{
	int len=length_list(L);
	LNode *p=L;
	if(m==1)
	{
		for(int i = 0;i<len-1;++i)
			p=p->next;
	}
	else
	{
		for(int j=0;j<m-2;++j)
			p=p->next;
	}
	
	LNode *q=p->next;
	int code = q->key;
	cout<<q->value<<" ";
	p->next=q->next;
	delete q;
	while(p->next!=NULL)
		delete_list(p->next,code);
	return;
}

void showWholeList2(LinkList pHead)//(没有头结点)
{
	LinkList p = pHead;//因为没有头结点，所有就直接开始
	int times=length_list(pHead);
	for(int i=0;i<=times;i++)
	{
		cout<<p->key<<" ";
		//cout<<p->value<<" ";
		p=p->next;
	}
	cout<<endl;
	return;
}

int main()
{
	int *val=new int;
	LinkList pHead=NULL;
	pHead=createList();
	showWholeList2(pHead);
	int num;
	cout<<"请输入初始的m="<<endl;
	cin>>num;
	delete_list(pHead,num);
	cout<<endl;
	delete pHead;
	return 0;
}