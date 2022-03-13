//二分答案
//蓝桥杯真题：分巧克力
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,h[N],w[N];
bool check(int m){
    long long c=0;
    for(int i=0;i<n;i++){
        c+=(long long)(h[i]/m)*(w[i]/m);
    }
    return c>=k?true:false;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d",&h[i],&w[i]);
    }
    int ans=1;
    int l=1,r=100000;
    while(l<=r){
        int m=l+(r-l)/2;
        if(check(m)){
            ans=m;
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    printf("%d",ans);
    return 0;
}