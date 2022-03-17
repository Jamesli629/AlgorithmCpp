//一维差分
#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]-a[i-1];
    }
    int l,r,c;
    while(m--){
        scanf("%d%d%d",&l,&r,&c);
        b[l]+=c;                  //一维差分的主要两个步骤
        b[r+1]-=c;
    }
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+b[i];//求b数组的前缀和并存放到b数组中
        printf("%d",b[i]);
    }
    return 0;
}