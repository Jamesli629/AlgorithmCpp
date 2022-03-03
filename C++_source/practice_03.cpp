#include<iostream>
#include<cmath>
using namespace std;

#define MAXSIZE 100
#define STACKINCREMENT 10

typedef struct SqStack1{
	char *top;
	char *base;
	int stacksize;
}SqStack1;
typedef struct SqStack2{
	int *top;
	int *base;
	int stacksize;
}SqStack2;

int InitStack1(SqStack1 &S)//初始化顺序栈
{
	S.base=new char[MAXSIZE];
	if(!S.base)exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 0;
}
int InitStack2(SqStack2 &S)//初始化顺序栈
{
	S.base=new int[MAXSIZE];
	if(!S.base)exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 0;
}

int Push1(SqStack1 &S,char e)//入栈
{
	if(S.top-S.base==MAXSIZE)
	{
		S.base=(char*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(char));
	    if(!S.base) exit(-1);
		S.stacksize+=STACKINCREMENT;
		S.top = S.base+S.stacksize; 
	}
	*S.top++=e;
	return 0;
}
int Push2(SqStack2 &S,int e)//入栈
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

int Pop1(SqStack1 &S,char &e)//出栈
{
	if(S.top==S.base)
	{
		cout<<"栈空"<<endl;
		return -2;
	}
	e=*--S.top;
	return 0;
}
int Pop2(SqStack2 &S,int &e)//出栈
{
	if(S.top==S.base)
	{
		cout<<"栈空"<<endl;
		return -2;
	}
	e=*--S.top;
	return 0;
}

char GetTop1(SqStack1 &S)
{
	char e;
	if(S.base==S.top)exit(-1);
	e=*(S.top-1);
	return e;
}
int GetTop2(SqStack2 &S)
{
	int e;
	if(S.base==S.top)exit(-1);
	e=*(S.top-1);
	return e;
}

int Operate2(int a,char theta,int b)
{
	int result;
	switch(theta){
		case'+':
			result=a+b;
			break;
		case'-':
			result=a-b;
			break;
		case'*':
			result=a*b;
			break;
		case'/':
			result=a/b;
			break;
		case'^':
			result=pow(a,b);
			break;
	}
	return result;
}

char Precede(char syb,char c)
{
	char result;
	switch(syb){
		case'+':
			switch(c){
				case'+':
					result='>';
					break;
				case'-':
					result='>';
					break;
				case'*':
					result='<';
					break;
				case'/':
					result='<';
					break;
				case'(':
					result='<';
					break;
				case')':
					result='>';
					break;
				case'#':
					result='>';
					break;
				case'^':
					result='<';
					break;
			}
			break;
		case'-':
			switch(c){
				case'+':
					result='>';
					break;
				case'-':
					result='>';
					break;
				case'*':
					result='<';
					break;
				case'/':
					result='<';
					break;
				case'(':
					result='<';
					break;
				case')':
					result='>';
					break;
				case'#':
					result='>';
					break;
				case'^':
					result='<';
					break;
			}
			break;
		case'*':
			switch(c){
				case'+':
					result='>';
					break;
				case'-':
					result='>';
					break;
				case'*':
					result='<';
					break;
				case'/':
					result='<';
					break;
				case'(':
					result='<';
					break;
				case')':
					result='>';
					break;
				case'#':
					result='>';
					break;
				case'^':
					result='<';
					break;
			}
			break;
		case'/':
			switch(c){
				case'+':
					result='>';
					break;
				case'-':
					result='>';
					break;
				case'*':
					result='<';
					break;
				case'/':
					result='<';
					break;
				case'(':
					result='<';
					break;
				case')':
					result='>';
					break;
				case'#':
					result='>';
					break;
				case'^':
					result='<';
					break;
			}
			break;
		case'(':
			switch(c){
				case'+':
					result='<';
					break;
				case'-':
					result='<';
					break;
				case'*':
					result='<';
					break;
				case'/':
					result='<';
					break;
				case'(':
					result='<';
					break;
				case')':
					result='=';
					break;
				case'^':
					result='<';
					break;
			}
			break;
		case')':
			switch(c){
				case'+':
					result='>';
					break;
				case'-':
					result='>';
					break;
				case'*':
					result='>';
					break;
				case'/':
					result='>';
					break;
				case')':
					result='>';
					break;
				case'#':
					result='>';
					break;
				case'^':
					result='>';
					break;
			}
			break;
		case'#':
			switch(c){
				case'+':
					result='<';
					break;
				case'-':
					result='<';
					break;
				case'*':
					result='<';
					break;
				case'/':
					result='<';
					break;
				case'(':
					result='<';
					break;
				case'#':
					result='=';
					break;
				case'^':
					result='<';
					break;
			}
			break;
		case'^':
			switch(c){
				case'+':
					result='>';
					break;
				case'-':
					result='>';
					break;
				case'*':
					result='>';
					break;
				case'/':
					result='>';
					break;
				case'(':
					result='<';
					break;
				case')':
					result='>';
					break;
				case'#':
					result='>';
					break;
				case'^':
					result='>';
					break;
			}
			break;
	}
	return result;
}

void display1(SqStack1 S)
{
	if(S.top==S.base)
	{
		cout<<"栈空！"<<endl;
		exit(-1);
	}
	cout<<"optr:";
	while(!(S.top==S.base))
	{
		
		cout<<*(--S.top)<<" ";
	}
	cout<<endl;
}
void display2(SqStack2 S)
{
	if(S.top==S.base)
	{
		cout<<"栈空！"<<endl;
		exit(-1);
	}
	cout<<"opnd:";
	while(!(S.top==S.base))
	{
		
		cout<<*(--S.top)<<" ";
	}
	cout<<endl;
}

int EvaluateExpression()
{
	SqStack1 optr;
	SqStack2 opnd;
	char c,x,theta;
	int a,b;
	InitStack1(optr);Push1(optr,'#');
	InitStack2(opnd);c=getchar();
	while(c!='#' || GetTop1(optr)!='#')
	{
		if(isdigit(c)){
			int temp;
			temp=int(c)-48;
			while(isdigit(c))
			{
				c=getchar();
				if(isdigit(c))
					temp=temp*10+int(c)-48;
				else
					break;
			}
			//cout<<temp<<endl;
			Push2(opnd,temp);
			display1(optr);
			display2(opnd);
		}
		else
			switch(Precede(GetTop1(optr),c)){
				case'<':
					Push1(optr,c);
					c=getchar();
					display1(optr);
					display2(opnd);
					break;
				case'=':
					Pop1(optr,x);
					c=getchar();
					display1(optr);
					display2(opnd);
					break;
				case'>':
					Pop1(optr,theta);
					Pop2(opnd,b);
					Pop2(opnd,a);
					Push2(opnd,Operate2(a,theta,b));
					display1(optr);
					display2(opnd);
					break;
			}
	}
	return GetTop2(opnd);
}


int main()
{
	cout<<"请输入算术表达式:"<<endl;
	cout<<"结果为:"<<EvaluateExpression()<<endl;
	return 0;
}