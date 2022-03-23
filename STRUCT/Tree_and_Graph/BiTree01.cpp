//������
 
//������˳��洢�ı�ʾ
#define MAXSIZE 100
typedef int SqBiTree[MAXSIZE] SqBiTree bt;

//��������ʽ�洢�ı�ʾ
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree; 

//����������***
//�ݹ��㷨 
int PreOrderTraverse(BiTree &T)//����ݹ����
{
	if(T==NULL)return -1;
	else
	{
		cout<<T->data;//�Խ��Ĳ��� 
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return 0;
}

int InOrderTraverse(BiTree &T)//����ݹ����
{
	if(T==NULL)return -1;
	else
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
	return 0;
}

int PostOrderTraverse(BiTree &T)//����ݹ����
{
	if(T==NULL)return -1;
	else
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
	}
	return 0;
}

//�ǵݹ��㷨
//1.������� 
int InOrderTraverse2(BiTree &T)
{
	InitStack(S);//����һ��ջ
	BiTNode* p=T;
	BiTNode* q;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);//������ջ������������
			p=p->lchild;
		}
		else
		{
			Pop(S,q);
			cout<<q->data;
			p=q->rchild;
		}
	}
	return 0;
}

int PreOrderTraverse2(BiTree &T)
{
	InitStack(S);//����һ��ջ
	BiTNode* p=T;
	BiTNode* q;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);//������ջ������������
			p=p->lchild;
		}
		else
		{
			Pop(S,q);
			p=q->rchild;
			if(!p)
			{
				cout<<q->data;
				p=q;	
			}	
		}
	}
	return 0;
}













