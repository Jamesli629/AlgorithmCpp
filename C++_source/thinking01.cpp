#include<iostream>
using namespace std;

int *num;
int *key;
int len;
void createList()
{
	cout<<"请输入顺序表长度(len<=30)len=\n";
	cin>>len;
	num=new int[len];
	key=new int[len];
	cout<<"请输入密码\n";
	for(int i=0;i<len;++i)
	{
		num[i]=i+1;
		cin>>key[i];
	}
}
void work(int m)
{
	int count=0,i=0;
	while(len>1)
	{
		count = (m+count-1)%len;
		i=count;
		m=key[count];
		cout<<num[count]<<" ";
		for(i;i<len-1;++i)
		{
			num[i]=num[i+1];
			key[i]=key[i+1];

		}
		len--;
	}
	cout<<num[0]<<endl;
}

int main()
{
	int m;
	createList();
	cout<<"请输入m的初值"<<endl;
	cin>>m;
	work(m);
	delete[] num;
	delete[] key;
	return 0;
}