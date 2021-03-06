//队列的顺序实现
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXQSIZE 100

typedef struct {//顺序队列的表示 
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q){//队列初始化 
	Q.base=new int[MAXQSIZE];
	if(!Q.base)exit(-1);
	Q.front=0;
	Q.rear=0;
	return 0;
}

int QueueLength(SqQueue &Q){//队列的长度 
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//循环队列的入队
int EnQueue(SqQueue &Q,int e){
	if((Q.rear+1)%MAXQSIZE==Q.front)return -1;//队满 
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 0;
}

//出队
int DeQueue(SqQueue &Q,int &e){
	if(Q.front==Q.rear)return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return 0;
}

//取队头元素
int GetHead(SqQueue &Q){
	if(Q.front!=Q.rear)return Q.base[Q.front];
}

int main(){
	return 0;
}

