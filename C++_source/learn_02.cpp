#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE,*PNODE;

//函数声明
PNODE create_list();//创建链表（有头结点）
PNODE create_list2();//创建链表（没有头结点）
void showWholeList(PNODE);//遍历输出链表（有头结点)
void showWholeList2(PNODE pHead);//遍历输出链表(没有头结点)
bool is_empty(PNODE);//判断是否为空
int length_list(PNODE);//链表长度
bool insert_list(PNODE,int,int);//插入数据到链表指定位置
bool delete_list(PNODE,int,int*);//删除链表指定位置的数据
void sort_list(PNODE);//排序

int main()
{
	PNODE pHead=NULL;
	int *num=new int;
	pHead = create_list();
	showWholeList(pHead);

	sort_list(pHead);
	showWholeList(pHead);
	//cout<<insert_list(pHead,3,22)<<endl;
	//showWholeList(pHead);
	//cout<<delete_list(pHead,1,num)<<endl;
	//showWholeList(pHead);
	//if(is_empty(pHead))
	//	cout<<"链表为空！\n";
	//else
	//	cout<<"链表不空！\n";
	delete pHead;
	return 0;
}

PNODE create_list()//(有头结点)
{
	int i,val;
	int len;//链表的结点个数
	PNODE pHead=new Node;//生成头指针，指向头结点
	if(!pHead)
	{
		cout<<"内存分配失败！\n";
		exit(-1);
	}
	pHead->pNext=NULL;
	cout<<"请输入链表结点的个数 len = "<<endl;
	cin>>len;
	PNODE pTail=pHead;//一个指向链表结尾的指针*
	pTail->pNext=NULL;

	for(i=0;i<len;++i)
	{
		cout<<"请输入当前结点的值：\n";
		cin>>val;

		PNODE pNew=new NODE;
		if(!pNew)
		{
			cout<<"内存分配失败！\n";
			exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	}
	return pHead;
}
PNODE create_list2()//(没有头结点)
{
	int i,val0,val,len;

	cout<<"请输入链表结点的个数 len = "<<endl;
	cin>>len;
	PNODE pHead=new Node;
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
		cout<<"请输入链表的第一个值:\n";
		cin>>val0;
		pHead->data=val0;
		pHead->pNext=NULL;
	}
	PNODE pTail=pHead;//一个指向链表结尾的指针*
	pTail->pNext=NULL;

	for(i=1;i<len;++i)
	{
		cout<<"请输入当前结点的值：\n";
		cin>>val;

		PNODE pNew=new NODE;
		if(!pNew)
		{
			cout<<"内存分配失败！\n";
			exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	}
	return pHead;
}

void showWholeList(PNODE pHead)//(有头结点)
{
	PNODE p = pHead->pNext;//应该是从首结点开始，所以p就指向头指针所指向的下一个结点*
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->pNext;
	}
	cout<<endl;
	return;
}
void showWholeList2(PNODE pHead)//(没有头结点)
{
	PNODE p = pHead;//因为没有头结点，所有就直接开始
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->pNext;
	}
	cout<<endl;
	return;
}

bool is_empty(PNODE pHead)
{
	if(pHead->pNext==NULL)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	int len=0;
	PNODE p = pHead->pNext;
	while(p!=NULL)
	{
		++len;
		p=p->pNext;
	}
	return len;
}

bool insert_list(PNODE pHead,int pos,int val)
{
	int i=0;
	PNODE p=pHead;
	while(p!=NULL && i<pos-1)
	{
		p=p->pNext;
		++i;
	}
	if(i>pos-1 || p==NULL)return false;
	PNODE pNew=new Node;
	if(!pNew)
	{
		cout<<"动态内存分配失败！\n";
		exit(-1);
	}
	pNew->data=val;
	PNODE q=p->pNext;
	p->pNext=pNew;
	pNew->pNext=q;
	return true;
}

bool delete_list(PNODE pHead,int pos,int* pVal)
{
	int i=0;
	PNODE p=pHead;
	while(p->pNext!=NULL && i<pos-2)
	{
		p=p->pNext;
		++i;
	}
	if(i>pos-1 || p->pNext==NULL)return false;

	PNODE q=p->pNext;
	*pVal=q->data;
	p->pNext=p->pNext->pNext;
	delete q;
	q=NULL;
	
	return true;
}

void sort_list(PNODE pHead)
{
	int i,j,t;
	int len=length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
			if(p->data>q->data)
			{
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
}