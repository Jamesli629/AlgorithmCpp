/*
	Name: L1-002
	Copyright: 
	Author: 爱吃胖头鱼
	Date: 14/01/22 14:14
	Description: 
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,h;
    char x;
    cin>>n>>x;
    h=sqrt((n+1)/2);                             //hΪ(H+1)/2������ƽ������H��ʾɳ©�ĸ߶� 
    for(int i=h;i>=1;i--)
    {
    	for(int j=0;j<h-i;j++)cout<<" ";
    	for(int j=0;j<2*i-1;j++)cout<<x;
    	cout<<endl;
	}
	for(int i=2;i<=h;i++)
	{
		for(int j=0;j<h-i;j++)cout<<" ";
    	for(int j=0;j<2*i-1;j++)cout<<x;
    	cout<<endl;
	}
	cout<<n-(2*h*h-1)<<endl;
    return 0;
}
