//循环链表
LinkList Connect(LinkList &Ta,LinkList &Tb)//将两个带尾指针的循环链表合并
{
	PNode *p=Ta->next;
	Ta->next=Tb->next->next;
	delete Tb->next;
	Tb->next=p;
	return Tb;
}






//双向链表
typedef struct DuLNode{
	int data;
	struct DuLNode *next,*prior;
}DuLNode,*DuLinkList;

void ListInsert_DuL(DuLinkList &L,int i,int e)//在双向链表中插入
{
	if(!(p=GetElem_DuL(L,i)))exit(-1);
	DuLNode *s=new DuLNode;
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return;
}

void ListDelete_DuL(DuLinkList &L,int i,int &e)//双向链表中删除
{
	if(!(p=GetElem_DuL(L,i)))exit(-1);
	e=p->data;
	p->prior-next=p->next;
	p->next->prior=p->prior;
	delete p;
	return;
}