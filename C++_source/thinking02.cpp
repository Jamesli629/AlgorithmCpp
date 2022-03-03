#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct LNode {
   int value;
   int key;
   struct LNode *next;
} LNode, *LinkList;

LinkList createList (LinkList &pHead)
{
	int val,len;
	cout<<"������ԭʼ���ĸ���:\n";
	cin>>len;
	if(len<=0)
		exit(-1);
	else
	{
		cout<<"����������\n";
		pHead=new LNode;
		pHead->value=1;
		cin>>pHead->key;
		pHead->next=NULL;
		LNode* pTail=pHead;//һ��ָ�������β��ָ��*
		for(int i=1;i<len;++i)
		{
			cin>>val;
			LNode* pNew=new LNode;
			if(!pNew)exit(-1);
			pNew->value=i+1;
			pNew->key=val;
			pNew->next=pTail->next;
			pTail->next=pNew;
			pTail=pNew;
		}
		pTail->next=pHead;	
	}
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

void delete_list(LinkList &pHead,int &m)
{
	int len=length_list(pHead);
	int code;
	LNode *p=pHead;
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
	code = q->key;
	cout<<q->value<<" ";
	p->next=q->next;
	delete q;
	while(p->next!=NULL)
		delete_list(p->next,code);
	return;
}

void showWholeList2(LinkList &pHead)//չʾ����ÿ����������
{
	LinkList p = pHead;
	int times=length_list(pHead);
	for(int i=0;i<=times;i++)
	{
		cout<<p->key<<" ";
		p=p->next;
	}
	cout<<endl;
	return;
}

int main()
{
	int *val=new int;
	LinkList pHead;
	pHead=createList(pHead);
	showWholeList2(pHead);
	int num;
	cout<<"�������ʼ��m="<<endl;
	cin>>num;
	delete_list(pHead,num);
	delete pHead;
	return 0;
}