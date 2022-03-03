#include<iostream>
#include<stdlib.h>
using namespace std;
#define Maxsize 20
#define Addsize 10
//˳����Ľṹ��
typedef struct{
	int *elem;
	int length;
}Sqlist;
//Sqlist L;
//L.elem=new int[L.length];

int InitList(Sqlist &L)//��ʼ��˳���
{
	L.elem=new int[Maxsize];
	if(!L.elem)exit(-1);
	L.length=0;
	return 0;
}

void DestroyList(Sqlist &L)//����˳���
{
	if(L.elem)delete[] L.elem;
}

void ClearList(Sqlist &L)//���˳���
{
	L.length=0;
}

int GetLength(Sqlist &L)//˳�������
{
	return (L.length);
}

bool isEmpty(Sqlist &L)//�ж��Ƿ�Ϊ��
{
	if(L.length==0)
		return true;
	else
		return false;
}

int GetElem(Sqlist &L,int i,int &e)//�õ����Ϊi��Ԫ�ص�ֵ
{
	if(i<1 || i>L.length)return -1;//�ж�i�Ƿ���Ч
	e=L.elem[i-1];
	return 0;
}

int LocateElem(Sqlist &L,int e)//�ҵ�ֵΪe��Ԫ�ص���ţ������±꣩
{
	for(int i=0;i<L.length;++i)
		if(L.elem[i]==e)return i+1;
	cout<<"δ�ҵ���"<<endl;
	return 0;
}

int insertList(Sqlist &L,int i,int e)//����
{
	int newSize,*newbase;
	if(i<1||i>L.length+1)exit(-1);
	newSize=Maxsize+Addsize;
	newbase=(int *)realloc(L.elem,newSize*(sizeof(int)));
	if(!newbase)exit(-1);
	L.elem=newbase;
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	L.length++;
	return 0;
		
}

int deleteList(Sqlist &L,int i,int &e)//ɾ��
{
	if(i<1 || i>L.length)exit(-1);
	e=L.elem[i-1];
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return 0;

}

