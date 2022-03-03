//����Ľ��Ĺ���
typedef struct Node{
	int data;
	struct Node *next;
}LNode,*LinkList;

//LinkList L;//��������L
//LNode *p//����ָ�����ָ��

int InitList(LinkList &L)//��ʼ��������
{
	L=new LNode;
	L->next=NULL;
	return 0;
}

bool isEmpty(LinkList &L)//�ж������Ƿ�Ϊ��
{
	if(L->next==NULL)
		return true;
	else
		return false;
}

int DestroyList(LinkList &L)//���ٵ�����
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

int ClearList(LinkList &L)//��յ�����
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

int ListLength(LinkList &L)//������
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

int GetElem(LinkList &L,int i,int &e)//ȡ��i����ֵ
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

LNode* LocateElem1(LinkList &L,int e)//���ң����ص�ַ
{
	PNode *p=L->next;
	while(p&&p->data!=e)
	{
		p=p->next;
	}
	return p;
}
int LocateElem2(LinkList &L,int e)//���ң��������
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

int insertList(LinkList &L,int i)//�ڵ�i��Ԫ��ǰ����
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

int deleteList(LinkList &L,int i,int &e)//ɾ����i��Ԫ��
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

void createList1(LinkList &L,int n)//����������ͷ�巨��
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

void createList2(LinkList &L,int n)//����������β�巨��
{
	L=new LNode;
	L->next=NULL;
	PNode *r=L;
	for(int i=0;i<n;i++)
	{
		PNode *p=new PNode;
		if(!p)exit(-1);
		cin>>p->data;
		p->next=r->next;//Ҳ����д��p->next=NULL;
		r->next=p;
		r=p;
	}
}
