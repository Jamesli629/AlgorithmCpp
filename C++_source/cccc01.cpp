#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	cin>>N;
	string str[N];
	double weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
//	double wei[17];//ШЈжи 
//	for(int j=0;j<17;j++)
//	{
//		wei[j]=weight[j]/100;
//	}
	for(int i=0;i<N;i++)
	{
		int sum=0;
		cin>>str[i];
		for(int k=0;k<17;k++)
		{
			cout<<str[i][k]<<" "<<weight[k]<<endl;
			sum+=str[i][k]*weight[k];
		}
		cout<<sum<<endl;
		int jiaoyan = sum%11;
		cout<<jiaoyan<<endl;
	}

	return 0;
}
