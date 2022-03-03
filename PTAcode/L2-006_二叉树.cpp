// 代码作者：17级的林欣郁同学
#include<iostream>
using namespace std;

int h[31],z[31],c[10000];

void level(int root,int start,int end,int index)
{
	if(start>end)
	{
		return;
	}
	int p=start;
	while(p<end&&z[p]!=h[root])
	{
		p++;
	}
	c[index]=h[root];
	level(root-end+p-1,start,p-1,2*index+1);
	level(root-1,p+1,end,2*index+2);
}

int main()
{
	int n,i,count=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>h[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>z[i];
	}
	level(n-1,0,n-1,0);
	cout<<c[0];
	for(i=1,count=0;count<n-1;i++)
	{
		if(c[i]!=0) 
		{
			cout<<" "<<c[i];
			count++;
		}
	}
	cout<<endl;
	return 0;
}