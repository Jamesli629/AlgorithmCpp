#include<iostream>
using namespace std;
int main()
{
	void sort(int str[],int n);
	void change(int &,int &);
	while(true){
		cout<<"请输入三个整数,输入三个0表示结束"<<endl;
	    int str[3];
	    for(int num=0;num<3;num++)
		{
			cin>>str[num];
		}
		if(str[0]==0 && str[1]==0 && str[2]==0) break;
		sort(str,3);
		for(int num2=0;num2<3;num2++)
		{
			cout<<str[num2]<<" ";
		}
		cout<<endl;

	}
	
	return 0;
}
void sort(int str[],int n)
{
	void change(int &,int &);
	int k;
	for(int i=0;i<n-1;i++)
	{
		k=i;
		for(int j=i+1;j<n;j++)
			if(str[j]>str[k])k=j;
		change(str[k],str[i]);

	}
}
void change(int &num1,int &num2)
{
	int temp;
	temp=num1;
	num1=num2;
	num2=temp;
}