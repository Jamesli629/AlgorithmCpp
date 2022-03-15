#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int>a,vector<int>b){
    if(a.size()!=b.size())return a.size()>b.size();
    for(int i=a.size();i>=0;i--){
        if(a[i]!=b[i]){
            return a[i]>b[i];
        }
    }
    return true;
}
/**
 * 高精度减法
 * 大减小
 */
vector<int> sub(vector<int>a,vector<int>b){//前提条件：a>b
    vector<int>c;
    for(int i=0,x=0;i<=a.size()-1;i++){
        x=a[i]-x;
        if(i<b.size())x-=b[i];
        c.push_back((x+10)%10);
        if(x<0)x=1;//借位
        else x=0;
    }
    while(c.size()>1 && c.back()==0)c.pop_back();//将多余的0去掉
    return c;
}
int main(){
    string a,b;
    cin>>a>>b;
    vector<int>A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
    if(cmp(A,B)){
        vector<int>C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    }
    else{                             //当A<B时，加负号
        vector<int>C=sub(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    }
    return 0;
}

//参考原文链接：https://blog.csdn.net/wmy0217_/article/details/104269844