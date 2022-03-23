//˳��ջ�ı�ʾ
#define MAXSIZE 100
#define STACKINCREMENT 10
typedef struct SqStack{
	int *top;
	int *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)//��ʼ��˳��ջ
{
	S.base=new int[MAXSIZE];
	if(!S.base)exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 0;
}

bool StackEmpty(SqStack &S)//�ж�ջ�Ƿ�Ϊ��
{
	if(S.base==S.top)
		return true;
	else
		return false;
}

int StackLength(SqStack &S)//��˳��ջ�ĳ���
{
	return S.top-S.base;
}

int ClearStack(SqStack &S)//���˳��ջ
{
	if(S.base)
		S.top=S.base;
	return 0;
}

int DestroyStack(SqStack &S)//����˳��ջ
{
	if(S.base)
	{
		delete[] S.base;
		S.stacksize=0;
		S.base=S.top=NULL;
	}
	return 0;
}

int Push(SqStack &S,int e)//��ջ
{
	if(S.top-S.base==MAXSIZE)
	{
		S.base=(int*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
	    if(!S.base) exit(-1);
		S.stacksize+=STACKINCREMENT;
		S.top = S.base+S.stacksize; 
	}
	*S.top++=e;
	return 0;
}

int Pop(SqStack &S,int &e)//��ջ
{
	if(S.top==S.base)
	{
		cout<<"ջ��"<<endl;
		return -2;
	}
	e=*--S.top;
	return 0;
}

int GetTop(SqStack &S,int &e)
{
	if(S.base==S.top)exit(-1);
	e=*(S.top-1);
	return 0;
}