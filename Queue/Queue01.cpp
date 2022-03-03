//���е�˳��ʵ��
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXQSIZE 100

typedef struct {//˳����еı�ʾ 
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q){//���г�ʼ�� 
	Q.base=new int[MAXQSIZE];
	if(!Q.base)exit(-1);
	Q.front=0;
	Q.rear=0;
	return 0;
}

int QueueLength(SqQueue &Q){//���еĳ��� 
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//ѭ�����е����
int EnQueue(SqQueue &Q,int e){
	if((Q.rear+1)%MAXQSIZE==Q.front)return -1;//���� 
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 0;
}

//����
int DeQueue(SqQueue &Q,int &e){
	if(Q.front==Q.rear)return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return 0;
}

//ȡ��ͷԪ��
int GetHead(SqQueue &Q){
	if(Q.front!=Q.rear)return Q.base[Q.front];
}

int main(){
	return 0;
}

