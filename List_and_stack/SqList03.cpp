//ѭ������
LinkList Connect(LinkList &Ta,LinkList &Tb)//��������βָ���ѭ������ϲ�
{
	PNode *p=Ta->next;
	Ta->next=Tb->next->next;
	delete Tb->next;
	Tb->next=p;
	return Tb;
}






//˫������
typedef struct DuLNode{
	int data;
	struct DuLNode *next,*prior;
}DuLNode,*DuLinkList;

void ListInsert_DuL(DuLinkList &L,int i,int e)//��˫�������в���
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

void ListDelete_DuL(DuLinkList &L,int i,int &e)//˫��������ɾ��
{
	if(!(p=GetElem_DuL(L,i)))exit(-1);
	e=p->data;
	p->prior-next=p->next;
	p->next->prior=p->prior;
	delete p;
	return;
}