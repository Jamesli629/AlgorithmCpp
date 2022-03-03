#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int *point1,*point2;
	cin>>a>>b;
	point1=&a;
	point2=&b;
	cout<<endl;
	cout<<"a="<<a<<"  "<<"b="<<b<<endl;
	cout<<*point1<<endl<<*point2<<endl;
	cout<<"==============================================="<<endl;
	int *p;
	p=point1;
	point1=point2;
	point2=p;
	cout<<"a="<<a<<"  "<<"b="<<b<<endl;
	cout<<*point1<<endl<<*point2<<endl;
	return 0;

}