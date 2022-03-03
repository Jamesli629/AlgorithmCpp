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
	cout<<"������ԭʼ���ĸ���:\n";
	cin>>len;
	LinkList pHead=new LNode;
	if(!pHead)
	{
		cout<<"�ڴ����ʧ�ܣ�\n";
		exit(-1);
	}
	if(len<=0)
	{
		exit(-1);
	}
	else
	{
		cout<<"����������ĵ�һ������:\n";
		cin>>val0;
		pHead->value=1;
		pHead->key=val0;
		pHead->next=NULL;
	}
	LinkList pTail=pHead;//һ��ָ�������β��ָ��*
	pTail->next=NULL;
	cout<<"����������\n";
	for(i=1;i<len;++i)
	{
		cin>>val;
		LinkList pNew=new LNode;
		if(!pNew)
		{
			cout<<"�ڴ����ʧ�ܣ�\n";
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

void showWholeList2(LinkList pHead)//(û��ͷ���)
{
	LinkList p = pHead;//��Ϊû��ͷ��㣬���о�ֱ�ӿ�ʼ
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
	cout<<"�������ʼ��m="<<endl;
	cin>>num;
	delete_list(pHead,num);
	cout<<endl;
	delete pHead;
	return 0;
}