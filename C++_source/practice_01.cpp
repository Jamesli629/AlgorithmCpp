#include<iostream>
using namespace std;
const LIST_INIT_SIZE=100; //���Ա�ĳ�ʼ�洢�ռ�
const LISTINCREMENT=10;  //���Ա�������ռ�

class List
{public:
	int * elem;
	int length;
	int ListSize;

	int createList(int n);
	void enter();
	void putOut();
	int Insert(int i,int e);
	int ListDelete(int i);
	int getElem(int i);
	int getMaxElem();
	int getMinElem();
	int findEquals(int e);
	void reverseList();
};
int List::createList(int n)
{
	length=n;
	elem=new int[length];
	if(!elem) return 1;    //�洢����ʧ��
	ListSize=n*sizeof(int);
	cout<<"�����ɹ���"<<endl;
	return 0;
}
void List::enter()
{
	cout<<"��ʼ���룡"<<endl;
	for(int i=0;i<length;++i)
		cin>>elem[i];
	cout<<"������ɣ�"<<endl;
}
void List::putOut()
{
	for(int i=0;i<length;++i)
		cout<<elem[i]<<" ";
	cout<<endl;
	cout<<"�����ɣ�"<<endl;
}
int List::Insert(int i,int e)
{
	int newsize,*newbase;
	int *q,*p;
	if(i<1||i>length+1)  return 1; // i�Ƿ�
	newsize=ListSize+LISTINCREMENT;
	newbase=(int *)realloc(elem,newsize*sizeof(int));
    if(!newbase) exit(2); //��չʧ��
    elem=newbase; 
	ListSize+=LISTINCREMENT;
	q=elem+i-1;
	for(p=elem+length-1;p>=q;p--)
		*(p+1)=*p;
	*q=e;
	length++;
	cout<<"����ɹ���"<<endl;
	return 0;
}
int List::ListDelete(int i)
{
	int *p;
	if(i<1||i>length) return 1;  //i�Ƿ�
	p=&(elem[i-1]);
	for(p++;p<=elem+length-1;p++)
		*(p-1)=*p;
	length--;
	cout<<"ɾ���ɹ���"<<endl;
	return 0;
}
int List::getElem(int i)
{
	int *p;
	if(i<1||i>length) return 1;  //i�Ƿ�
	p=&(elem[i-1]);
	return *p;

}
int List::getMaxElem()
{
	int *p;
	p=elem;
	for(int i=0;i<length;i++)
		if(elem[i]>*p)p=elem+i;
	return *p;
}
int List::getMinElem()
{
	int *p;
	p=elem;
	for(int i=0;i<length;i++)
		if(elem[i]<*p)p=elem+i;
	return *p;
}
int List::findEquals(int e)
{
	for(int i=0;i<length;i++)
		if(elem[i]==e)return i+1;
	cout<<"δ�ҵ�ƥ���Ԫ�أ�"<<endl;
	return 0;
}
void List::reverseList()
{
	int *p,*q,temp1,temp2;
	p=elem;
	q=elem+length-1;
	while(p<q)
	{
		temp1=*p;
		temp2=*q;
		*p=temp2;
		*q=temp1;
		p++;
		q--;
	}
}



int main()
{
	List L1;
	int num;
	cout<<"��������Ҫ������˳���ĳ��ȣ�"<<endl;
	cin>>num;
	L1.createList(num);

	L1.enter();

	L1.putOut();


	cout<<"������Ҫ���������λ�ú�����"<<endl;
	int location1,number;
	cin>>location1>>number;
	L1.Insert(location1,number);
	L1.putOut();

	cout<<"������Ҫɾ�����������"<<endl;
	int location2;
	cin>>location2;
	L1.ListDelete(location2);
	L1.putOut();

	cout<<"��Ҫ�õ��ڼ�������Ԫ�أ�"<<endl;
	int location3;
	cin>>location3;
	cout<<"Ԫ��Ϊ��"<<L1.getElem(location3)<<endl;

	cout<<"˳���������Ԫ��Ϊ��";
	cout<<L1.getMaxElem()<<endl;
	cout<<"˳�������С��Ԫ��Ϊ��";
	cout<<L1.getMinElem()<<endl;

	cout<<"������Ҫ���ҵ�Ԫ��"<<endl;
	int finds;
	cin>>finds;
	cout<<"Ԫ�����Ϊ��"<<L1.findEquals(finds)<<endl;

	cout<<"����ǰ��"<<endl;
	L1.putOut();
	
	L1.reverseList();
	cout<<"���ú�"<<endl;
	L1.putOut();
	delete[] L1.elem;


    return 0;
}