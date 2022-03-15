#include<bits/stdc++.h>
using namespace std;
//c是商，r是余数
/**
 * 高精度除法
 * 被除数是高精度，除数不是
 * 从最高位开始计算，这和其他的高精度算法不一样
 */ 
vector<int> div(vector<int>A,int b,int &r){
    vector<int>C;
    r=0;
    for(int i=A.size()-1;i>=0;i--){
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0){
        C.pop_back();
    }
    return C;
}
int main(){
    string a;
	int b;
	cin>>a>>b;
	vector<int> A;
	for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
	int r;//余数 
    vector<int> C=div(A,b,r);
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    cout<<endl<<r<<endl;
    return 0;
}

//参考原文链接：https://blog.csdn.net/wmy0217_/article/details/104269844