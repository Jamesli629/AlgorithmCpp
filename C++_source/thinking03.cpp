#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node{

	int coe;//ϵ��
	int exp;//ָ��
	struct Node * next;
}Node,*LinkNode;

void createList(LinkNode &L,int &n)
{
	L=new Node;
	if(!L)exit(-1);
	L->next=NULL;
	Node * tail=L; 
	if(!tail)exit(-1);
	for(int i=0;i<n;i++)
	{
		Node *p=new Node;
		if(!p)exit(-1);
		cout<<"������ϵ����ָ��\n";
		cin>>p->coe;
		cin>>p->exp;
		p->next=NULL;
		tail->next=p;
		tail=p;
	}
}

void add(LinkNode &L1,LinkNode &L2)
{
	Node *p1;
	Node *p2;
	Node *cur;
	p1=L1->next;
	p2=L2->next;
	cur=L1;
	while(p1 !=NULL && p2 !=NULL)
	{
		if(p1->exp < p2->exp)
		{
			cur->next=p1;//***Ҫ�Ƚ���������������ƶ�ָ��***
			cur=p1;
			p1=p1->next;
			cout<<"< ִ����һ��\n";
		}
		else if(p1->exp > p2->exp)
		{
			cur->next=p2;
			cur=p2;
			p2=p2->next;
			cout<<"> ִ����һ��\n";
		}
		else
		{
			int temp=p1->coe+p2->coe;
			if(temp!=0)
			{
				p1->coe=temp;
				cur->next=p1;
				cur=p1;
				p1=p1->next;
				p2=p2->next;
				cout<<"= ִ����һ��\n";
			}
			else
			{
				p1=p1->next;
				p2=p2->next;
				cout<<"��ȥ��һ��\n";
			}
		}
	}
	while(cur->next!=NULL)
	{
		if(p1==NULL)
		{
			cur->next=p2;
			cur=p2;
			p2=p2->next;
			cout<<"p2�ƶ���һ��\n";
		}
		else if(p2==NULL)//***if�������������Ҫ��{}***
		{
			cur->next=p1;
			cur=p1;
			p1=p1->next;
			cout<<"p1�ƶ���һ��\n";
		}		
	}
	cout<<"add success!\n";
}

void show(LinkNode &L)
{
	while(L->next)
	{
		L=L->next;
		cout<<L->coe<<" "<<L->exp<<endl;
	}
}
int main() 
{
	int num1=3;
	int num2=4;
	LinkNode L1,L2;
	createList(L1,num1);cout<<"1_success!\n";
	createList(L2,num2);cout<<"2_success!\n";
	add(L1,L2);cout<<"3_success!\n";
	show(L1);cout<<"4_success!\n";
	return 0;
}