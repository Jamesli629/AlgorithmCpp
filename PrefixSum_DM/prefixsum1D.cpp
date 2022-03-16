//一维前缀和
#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m;
int arr[N],sum[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    sum[1]=arr[1];
    for(int i=2;i<=n;i++){       //一维前缀和数组
        sum[i]=sum[i-1]+arr[i];
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}