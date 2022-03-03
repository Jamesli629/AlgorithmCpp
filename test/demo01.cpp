#include<iostream>
using namespace std;
int gcd(int m,int n){
	if(n==0)return m;
	else{
		int r=gcd(n,m % n);
	}
}
int main()
{
	cout<<gcd(16,8)<<endl;
	return 0;
 } 
