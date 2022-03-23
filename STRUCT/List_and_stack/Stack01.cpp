//顺序栈的表示
#define MAXSIZE 100
#define STACKINCREMENT 10
typedef struct SqStack{
	int *top;
	int *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)//初始化顺序栈
{
	S.base=new int[MAXSIZE];
	if(!S.base)exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 0;
}

bool StackEmpty(SqStack &S)//判断栈是否为空
{
	if(S.base==S.top)
		return true;
	else
		return false;
}

int StackLength(SqStack &S)//求顺序栈的长度
{
	return S.top-S.base;
}

int ClearStack(SqStack &S)//清空顺序栈
{
	if(S.base)
		S.top=S.base;
	return 0;
}

int DestroyStack(SqStack &S)//销毁顺序栈
{
	if(S.base)
	{
		delete[] S.base;
		S.stacksize=0;
		S.base=S.top=NULL;
	}
	return 0;
}

int Push(SqStack &S,int e)//入栈
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

int Pop(SqStack &S,int &e)//出栈
{
	if(S.top==S.base)
	{
		cout<<"栈空"<<endl;
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