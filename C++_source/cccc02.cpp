#include<iostream>
using namespace std;
int main()
{
	int valA,valB,countA=0,countB=0;
	cin>>valA>>valB;
	int N;
	cin>>N;
	int num[N][4];
	for(int i=0;i<N;i++)
	{
		cin>>num[i][0]>>num[i][1]>>num[i][2]>>num[i][3];
	}
	for(int j=0;j<N;j++)
	{
		if(valA<0)
		{
			cout<<"A"<<endl;
			cout<<countB<<endl;
			break;
		}
		else if(valB<0)
		{
			cout<<"B"<<endl;
			cout<<countA<<endl;
			break;
		}
		else
		{
			int sum = num[j][0]+num[j][2];
			if(num[j][1]==sum && num[j][3]!=sum){
				valA--;
				countA++;
			}
			else if(num[j][1]!=sum && num[j][3]==sum){
				valB--;
				countB++;
			}
			else if(num[j][1]!=sum && num[j][3]!=sum)continue;
			else if(num[j][1]==sum && num[j][3]==sum)continue;
		}
	}
	return 0;
}
