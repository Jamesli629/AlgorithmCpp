//链表的结点的构造
typedef struct Node{
	int data;
	struct Node *next;
}LNode,*LinkList;

//LinkList L;//定义链表L
//LNode *p//定义指向结点的指针

int InitList(LinkList &L)//初始化单链表
{
	L=new LNode;
	L->next=NULL;
	return 0;
}

bool isEmpty(LinkList &L)//判断链表是否为空
{
	if(L->next==NULL)
		return true;
	else
		return false;
}

int DestroyList(LinkList &L)//销毁单链表
{
	PNode *p;
	while(L!=NULL)
	{
		p=L;
		L=L->next;
		delete p;
	}
	return 0;
}

int ClearList(LinkList &L)//清空单链表
{
	PNode *q,*p;
	p=L->next;
	while(p!=NULL)
	{
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;
	return 0;
}

int ListLength(LinkList &L)//链表长度
{
	int length=0;
	PNode *p=L->next;
	while(p)
	{
		length++;
		p=p->next;
	}
	return length;
}

int GetElem(LinkList &L,int i,int &e)//取第i个的值
{
	PNode *p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)exit(-1);
	e=p->data;
	return 0;
}

LNode* LocateElem1(LinkList &L,int e)//查找，返回地址
{
	PNode *p=L->next;
	while(p&&p->data!=e)
	{
		p=p->next;
	}
	return p;
}
int LocateElem2(LinkList &L,int e)//查找，返回序号
{
	PNode *p=L->next;
	int j=1;
	while(p&&p->data!=e)
	{
		p=p->next;
		j++;
	}
	if(p)return j;
	else return 0;
}

int insertList(LinkList &L,int i)//在第i个元素前插入
{
	int j=0;
	PNode *p=L;
	while(p && j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)exit(-1);
	PNode *s=new PNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 0;
}

int deleteList(LinkList &L,int i,int &e)//删除第i个元素
{
	int j=0;
	PNode *p=L;
	while(p->next && j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1)exit(-1);
	PNode *q=p->next;
	p->next=q->next;
	e=q->data;
	delete q;
	return 0;
}

void createList1(LinkList &L,int n)//建立单链表（头插法）
{
	L=new LNode;
	L->next=NULL;
	for(int i=0;i<n;i++)
	{
		PNode *p=new PNode;
		if(!p)exit(-1);
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}

void createList2(LinkList &L,int n)//建立单链表（尾插法）
{
	L=new LNode;
	L->next=NULL;
	PNode *r=L;
	for(int i=0;i<n;i++)
	{
		PNode *p=new PNode;
		if(!p)exit(-1);
		cin>>p->data;
		p->next=r->next;//也可以写成p->next=NULL;
		r->next=p;
		r=p;
	}
}
