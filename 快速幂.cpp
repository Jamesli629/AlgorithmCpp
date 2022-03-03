#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastPower(ll base,ll power){//未优化 
	ll result=1;
	while(power>0){
		if(power%2==1){//指数为奇数时 
			power-=1;
			result*=base;
		}
		else{//指数为偶数时 
			power/=2;
			base*=base;
		}
	}
	return result;
}
ll qpower(ll base);
int main(){
	return 0;
}
