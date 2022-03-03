#include<iostream>
using namespace std;
const LIST_INIT_SIZE=100; //线性表的初始存储空间
const LISTINCREMENT=10;  //线性表的增量空间

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
	if(!elem) return 1;    //存储分配失败
	ListSize=n*sizeof(int);
	cout<<"创建成功！"<<endl;
	return 0;
}
void List::enter()
{
	cout<<"开始输入！"<<endl;
	for(int i=0;i<length;++i)
		cin>>elem[i];
	cout<<"输入完成！"<<endl;
}
void List::putOut()
{
	for(int i=0;i<length;++i)
		cout<<elem[i]<<" ";
	cout<<endl;
	cout<<"输出完成！"<<endl;
}
int List::Insert(int i,int e)
{
	int newsize,*newbase;
	int *q,*p;
	if(i<1||i>length+1)  return 1; // i非法
	newsize=ListSize+LISTINCREMENT;
	newbase=(int *)realloc(elem,newsize*sizeof(int));
    if(!newbase) exit(2); //扩展失败
    elem=newbase; 
	ListSize+=LISTINCREMENT;
	q=elem+i-1;
	for(p=elem+length-1;p>=q;p--)
		*(p+1)=*p;
	*q=e;
	length++;
	cout<<"插入成功！"<<endl;
	return 0;
}
int List::ListDelete(int i)
{
	int *p;
	if(i<1||i>length) return 1;  //i非法
	p=&(elem[i-1]);
	for(p++;p<=elem+length-1;p++)
		*(p-1)=*p;
	length--;
	cout<<"删除成功！"<<endl;
	return 0;
}
int List::getElem(int i)
{
	int *p;
	if(i<1||i>length) return 1;  //i非法
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
	cout<<"未找到匹配的元素！"<<endl;
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
	cout<<"请输入你要创建的顺序表的长度："<<endl;
	cin>>num;
	L1.createList(num);

	L1.enter();

	L1.putOut();


	cout<<"请输入要插入的数的位置和数："<<endl;
	int location1,number;
	cin>>location1>>number;
	L1.Insert(location1,number);
	L1.putOut();

	cout<<"请输入要删除的数的序号"<<endl;
	int location2;
	cin>>location2;
	L1.ListDelete(location2);
	L1.putOut();

	cout<<"你要得到第几个数的元素？"<<endl;
	int location3;
	cin>>location3;
	cout<<"元素为："<<L1.getElem(location3)<<endl;

	cout<<"顺序表中最大的元素为：";
	cout<<L1.getMaxElem()<<endl;
	cout<<"顺序表中最小的元素为：";
	cout<<L1.getMinElem()<<endl;

	cout<<"请输入要查找的元素"<<endl;
	int finds;
	cin>>finds;
	cout<<"元素序号为："<<L1.findEquals(finds)<<endl;

	cout<<"逆置前："<<endl;
	L1.putOut();
	
	L1.reverseList();
	cout<<"逆置后："<<endl;
	L1.putOut();
	delete[] L1.elem;


    return 0;
}