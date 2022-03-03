#include <iostream>
#include <stdlib.h>
#define MaxSize 100
using namespace std;
char c;
//二叉树的定义
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTtree;
//栈
struct Stack{
	BiTtree *top;
	BiTtree *base;
	int stacksize;
};
void initStack(Stack &S){
	S.base=new BiTNode *[MaxSize];
	S.top=S.base;
	S.stacksize=MaxSize;
}
BiTNode *Gettop(Stack S){
	return *(S.top-1);
}
void Push(Stack &S,BiTNode *e){
	*S.top++=e;
}
void Pop(Stack &S,BiTNode *&e){
	e=*--S.top;
}
int StackEmpty(Stack S){
	if(S.top==S.base) return 1;
	else return 0;
}
//队列
struct SqQueue{
	BiTtree *base;
	int front;
	int rear;
};
void InitSqQueue(SqQueue &Q){
	Q.base=new BiTNode *[MaxSize];
	Q.front=Q.rear=0;
}
int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MaxSize)%MaxSize;
}
void EnQueue(SqQueue &Q,BiTNode *e){
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MaxSize;
}
void DeQueue(SqQueue &Q,BiTNode *&e){
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MaxSize;
}
//二叉树函数
void createBiTree(BiTtree &T){
	c=getchar();
	if(c!='\n'){
		if(c=='#') T=NULL;
		else {
			T=new BiTNode;
			T->data=c;
			createBiTree(T->lchild);
			createBiTree(T->rchild);
		}
	}
}       
void showXianXu(BiTtree T){
	if(T==NULL) return ;
	else{
		cout<<T->data;
		showXianXu(T->lchild);
		showXianXu(T->rchild);
	}
}
void showZhongXu(BiTtree T){
	if(T==NULL) return ;
	else{
		showZhongXu(T->lchild);
		cout<<T->data;
		showZhongXu(T->rchild);
	}
}
void showHouXu(BiTtree T){
	if(T==NULL) return ;
	else{
		showHouXu(T->lchild);
		showHouXu(T->rchild);
		cout<<T->data;
	}
}
void showXianXu2(BiTtree T){
	Stack S;
	initStack(S);
	BiTtree p=T;
	while(p||StackEmpty(S)!=1){
		if(p!=NULL){
			Push(S,p);
			cout<<p->data;
			p=p->lchild;
		}
		else {
			Pop(S,p);
			p=p->rchild;
		}
	}
}
void showZhongXu2(BiTtree T){
	Stack S;
	initStack(S);
	BiTtree p=T;
	while(p||StackEmpty(S)!=1){
		if(p!=NULL){
			Push(S,p);
			p=p->lchild;
		}
		else {
			Pop(S,p);
			cout<<p->data;
			p=p->rchild;
		}
	}
}
void showHouXu2(BiTtree T){
	Stack S;
	initStack(S);
	BiTtree p=T;
	BiTtree r=NULL;
	while(p||StackEmpty(S)!=1){
		if(p!=NULL){
			Push(S,p);
			p=p->lchild;
		}
		else{
			p=Gettop(S);
			if(p->rchild&&p->rchild!=r) p=p->rchild;
			else {
				Pop(S,p);
				cout<<p->data;
				r=p;
				p=NULL;//再次进行右子树的判断
			}
		}
	}
}
void showCengXu(BiTtree T){
	SqQueue Q;
	InitSqQueue(Q);
	BiTNode *p=T;
	if(p) EnQueue(Q,p);
	while(QueueLength(Q)!=0){
		DeQueue(Q,p);
		cout<<p->data;
		if(p->lchild){
			EnQueue(Q,p->lchild);
		} 
		if(p->rchild){
			EnQueue(Q,p->rchild);
		} 
	}
}
int main(){
	BiTtree T;
	createBiTree(T);
	cout<<"递归先序：";
	showXianXu(T);
	cout<<endl;
	cout<<"递归中序：";
	showZhongXu(T);
	cout<<endl;
	cout<<"递归后序：";
	showHouXu(T);
	cout<<endl;
	cout<<"非递归先序：";
	showXianXu2(T);
	cout<<endl;
	cout<<"非递归中序：";
	showZhongXu2(T);
	cout<<endl;
	cout<<"非递归后序：";
	showHouXu2(T);
	cout<<endl;
	cout<<"层序遍历：";
	showCengXu(T);
	cout<<endl;
	return 0;
}