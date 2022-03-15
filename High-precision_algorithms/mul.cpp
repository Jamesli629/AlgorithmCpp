#include<iostream>
#include<vector>
using namespace std;
/**
 * 高精度乘法
 * 前提：一个是高精度，一个不是
 */ 
vector<int> mul(vector<int>A,int b){
    vector<int>c;
    int x=0;
    for(int i=0;i<A.size()||x;i++){
        if(i<A.size())x+=A[i]*b;
        c.push_back(x%10);
        x/=10;
    }
    return c;
}
int main(){
    string a;
	int b;
	cin>>a>>b;
	vector<int> A;
	for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
	vector<int> C=mul(A,b);
	for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    return 0;
}

//参考原文链接：https://blog.csdn.net/wmy0217_/article/details/104269844