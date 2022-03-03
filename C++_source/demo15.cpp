#include<iostream>
using namespace std;
int main()
{
	char str1[]="i love China!",str2[20],*p1,*p2;
	p1=str1;
	p2=str2;
	for(;*p1!='\0';p1++,p2++)
		*p2=*p1;
	*p2='\0';
	p1=str1;
	p2=str2;
	cout<<"str1 is "<<p1<<endl;//输出字符指针就是输出字符串
	cout<<"str2 is "<<*p2<<endl;//输出字符指针的间访就是输出单个字符
	return 0;
}