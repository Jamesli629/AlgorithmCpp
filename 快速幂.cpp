#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastPower(ll base,ll power){//δ�Ż� 
	ll result=1;
	while(power>0){
		if(power%2==1){//ָ��Ϊ����ʱ 
			power-=1;
			result*=base;
		}
		else{//ָ��Ϊż��ʱ 
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
