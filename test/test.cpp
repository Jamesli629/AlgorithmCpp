#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int arr[N];
int n,c;
int upBound(int key){
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]>key){
            ans = m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;
}
int lowBound(int key){
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]>=key){
            ans = m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;
}
int count(int num){
    return upBound(num)-lowBound(num);
}
int main(){
    long long ans = 0;
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        int b=arr[i]-c;
        long long res=count(b);
        ans+=res;
    }
    cout<<ans;
    return 0;
}