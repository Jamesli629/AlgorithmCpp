#include<bits/stdc++.h>
using namespace std;
int n;
int c[1005];

int lowbit(int x){
    return x & -x;
}

void add(int i,int k){//在i的位置上加k
    while(i<=n){
        c[i]+=k;
        i+=lowbit(i);
    }
}

int asksum(int i){//求1到i的和
    int res=0;
    while (i>0)
    {
        res+=c[i];
        i-=lowbit(i);
    }
    return res;
}