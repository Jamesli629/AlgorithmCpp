#include<bits/stdc++.h>
using namespace std;

//方阵乘法
#define ll long long
const int N=10;//这个数过大时，会报Segmentation fault错误
const ll MOD=1e9+7;
int n;
struct Matrix{
    ll a[N][N];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    void init(){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=(i==j);
    }
    Matrix operator*(const Matrix &B)const
    {//矩阵相乘
        Matrix C;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    C.a[i][j]=(C.a[i][j]+1ll*a[i][k]*B.a[k][j]) % MOD;
        return C;
    }
    Matrix operator^(const ll &t)const
    {//矩阵快速幂
        Matrix A=(*this),res;
        res.init();
        ll p=t;
        while(p){
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};

int main(){
    Matrix base;
    ll m;
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&base.a[i][j]);
        }
    }
    base = base ^ m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%lld%c",base.a[i][j],(j==n-1?'\n':' '));
        }
    }
}
