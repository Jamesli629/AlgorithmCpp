#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
//暴力字符串匹配
/*
int search(string pat,string txt){
    int m=pat.length();
    int n=txt.length();
    for(int i=0;i<n-m;++i){
        int j;
        for(j=0;j<m;j++){
            if(pat[j]!=txt[i+j])
                break;
        }
        if(j==m)return i;
    }
    return -1;
}
*/
int dp[MAX][MAX];//dp数组只和pat有关
string pat;
void KMP(string pat){//通过pat构建dp数组，O（M）

}
int search(string txt){//借助dp数组去匹配txt，O（N）

}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<search(s1)<<endl;
    return 0;
}