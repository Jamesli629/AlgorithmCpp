//队列的链式存储
#include<iostream>
#include<stdlib.h>
using namespace std; 
#define MAXQSIZE 100

typedef struct QNode{
	int data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//链队列初始化 
int InitQueue(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	if(!Q.front)exit(-1);
	Q.front->next=NULL;
	return 0;
}

//销毁链队列 
int DestroyQueue(LinkQueue &Q){
	QNode * p;
	while(Q.front){
		p = Q.front->next;
		delete Q.front;
		Q.front = p;
	}
	return 0;
}

//入队
int EnQueue(LinkQueue &Q,int e){
	QNode *p=new QNode;
	if(!p)exit(-1);
	p->data = e;
	p->next=NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 0;
}

//出队
int DeQueue(LinkQueue &Q,int &e){
	if(Q.front==Q.rear)return -1;
	QNode* p;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear = Q.front;
	delete p;
	return 0;
}

//取队头元素 
int GetHead(LinkQueue &Q,int &e){
	if(Q.front==Q.rear)return -1;
	e=Q.front->next->data;
	return 0;
}



















 
int main(){
	return 0;
}
