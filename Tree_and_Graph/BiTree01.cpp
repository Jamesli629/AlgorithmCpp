//二叉树
 
//二叉树顺序存储的表示
#define MAXSIZE 100
typedef int SqBiTree[MAXSIZE] SqBiTree bt;

//二叉树链式存储的表示
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree; 

//遍历二叉树***
//递归算法 
int PreOrderTraverse(BiTree &T)//先序递归遍历
{
	if(T==NULL)return -1;
	else
	{
		cout<<T->data;//对结点的操作 
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return 0;
}

int InOrderTraverse(BiTree &T)//中序递归遍历
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

int PostOrderTraverse(BiTree &T)//后序递归遍历
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

//非递归算法
//1.中序遍历 
int InOrderTraverse2(BiTree &T)
{
	InitStack(S);//建立一个栈
	BiTNode* p=T;
	BiTNode* q;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);//根结点进栈，遍历左子树
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
	InitStack(S);//建立一个栈
	BiTNode* p=T;
	BiTNode* q;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);//根结点进栈，遍历左子树
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













