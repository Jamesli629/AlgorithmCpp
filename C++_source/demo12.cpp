#include<iostream>
using namespace std;
int main()
{
	void change1(int &,int &);
	void change2(int *,int *);
	int a,b,*point1,*point2;
	cout<<"please enter 2 numbers"<<endl;
	cin>>a>>b;
	cout<<"before change1: "<<"a="<<a<<" "<<"b="<<b<<endl;
	change1(a,b);
	cout<<"after change1: "<<"a="<<a<<" "<<"b="<<b<<endl;
	point1=&a;
	point2=&b;
	change2(point1,point2);
	cout<<"after change2: "<<"a="<<a<<" "<<"b="<<b<<endl;
	return 0;
}
void change1(int &x,int &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void change2(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}