#include<iostream>
using namespace std;
int main()
{
	void sort(int,int,int);
	void change(int &,int &);
	cout<<"请输入三个整数"<<endl;
	int a,b,c;
	cin>>a>>b>>c;
	sort(a,b,c);
	cout<<a<<b<<c<<endl;
	return 0;
}
void sort(int x,int y,int z)
{
	void change(int &,int &);
	if (y>x)change(x,y);
	if (y>z)change(y,z);
	if (z>x)change(z,x);
}
void change(int &num1,int &num2)
{
	int temp;
	temp=num1;
	num1=num2;
	num2=temp;
}