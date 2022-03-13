#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,key,arr[N];
/**
 * 二分查找
 * 前提条件：数组要是有序的
 * 时间复杂度：O(logn)
 * 
 */
int binarySearch(int arr[],int n,int key){//求等于key的最小下标
    int l=1;
    int r=n;
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==key){//==改成>=就是求第一个大于或等于key的下标（a）
            ans = mid;    //接上：==改成>就是求第一个大于key的下标（b）
            r=mid-1;      //求等于key值的个数：就可以用（a）式的值-（b）式的值
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}
bool cmp(int a,int b){
    return a<b;        //从小到大排序
}
int main(){
    cin>>n>>key;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+n+1,cmp);//防止输入不是有序的
    for(int i=1;i<=n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int res = binarySearch(arr,n,key);
    cout<<res<<endl;
    return 0;
}