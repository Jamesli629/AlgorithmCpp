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
	cout<<"str1 is "<<p1<<endl;//����ַ�ָ���������ַ���
	cout<<"str2 is "<<*p2<<endl;//����ַ�ָ��ļ�þ�����������ַ�
	return 0;
}