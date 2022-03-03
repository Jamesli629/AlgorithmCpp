#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE,*PNODE;

//��������
PNODE create_list();//����������ͷ��㣩
PNODE create_list2();//��������û��ͷ��㣩
void showWholeList(PNODE);//�������������ͷ���)
void showWholeList2(PNODE pHead);//�����������(û��ͷ���)
bool is_empty(PNODE);//�ж��Ƿ�Ϊ��
int length_list(PNODE);//������
bool insert_list(PNODE,int,int);//�������ݵ�����ָ��λ��
bool delete_list(PNODE,int,int*);//ɾ������ָ��λ�õ�����
void sort_list(PNODE);//����

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
	//	cout<<"����Ϊ�գ�\n";
	//else
	//	cout<<"�����գ�\n";
	delete pHead;
	return 0;
}

PNODE create_list()//(��ͷ���)
{
	int i,val;
	int len;//����Ľ�����
	PNODE pHead=new Node;//����ͷָ�룬ָ��ͷ���
	if(!pHead)
	{
		cout<<"�ڴ����ʧ�ܣ�\n";
		exit(-1);
	}
	pHead->pNext=NULL;
	cout<<"������������ĸ��� len = "<<endl;
	cin>>len;
	PNODE pTail=pHead;//һ��ָ�������β��ָ��*
	pTail->pNext=NULL;

	for(i=0;i<len;++i)
	{
		cout<<"�����뵱ǰ����ֵ��\n";
		cin>>val;

		PNODE pNew=new NODE;
		if(!pNew)
		{
			cout<<"�ڴ����ʧ�ܣ�\n";
			exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	}
	return pHead;
}
PNODE create_list2()//(û��ͷ���)
{
	int i,val0,val,len;

	cout<<"������������ĸ��� len = "<<endl;
	cin>>len;
	PNODE pHead=new Node;
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
		cout<<"����������ĵ�һ��ֵ:\n";
		cin>>val0;
		pHead->data=val0;
		pHead->pNext=NULL;
	}
	PNODE pTail=pHead;//һ��ָ�������β��ָ��*
	pTail->pNext=NULL;

	for(i=1;i<len;++i)
	{
		cout<<"�����뵱ǰ����ֵ��\n";
		cin>>val;

		PNODE pNew=new NODE;
		if(!pNew)
		{
			cout<<"�ڴ����ʧ�ܣ�\n";
			exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	}
	return pHead;
}

void showWholeList(PNODE pHead)//(��ͷ���)
{
	PNODE p = pHead->pNext;//Ӧ���Ǵ��׽�㿪ʼ������p��ָ��ͷָ����ָ�����һ�����*
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->pNext;
	}
	cout<<endl;
	return;
}
void showWholeList2(PNODE pHead)//(û��ͷ���)
{
	PNODE p = pHead;//��Ϊû��ͷ��㣬���о�ֱ�ӿ�ʼ
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
		cout<<"��̬�ڴ����ʧ�ܣ�\n";
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