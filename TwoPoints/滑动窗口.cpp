//版权声明：本文为CSDN博主「lady_killer9」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/lady_killer9/article/details/110246226
#include<bits/stdc++.h>
using namespace std;
int findminstring(string s){
    int n=s.length();
    if(n==0)return 0;
    int l=0;
    int cnt=0;
    unordered_set<char>m;
    for(int r=0;r<n;++r){
        if(m.find(s[r])==m.end())m.insert(s[r]);//没找到
        else{
            cnt=cnt>m.size()?cnt:m.size();
            while(m.find(s[r])!=m.end())
            {
                m.erase(s[l]);
                ++l;
            }
            m.insert(s[r]);
        }
    }
    cnt=cnt>n-l?cnt:n-l;
    return cnt;
}
int main(){
    string s;
    while (cin>>s)
    {
        cout<<findminstring(s)<<endl;
    }
    return 0;  
}