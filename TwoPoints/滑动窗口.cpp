//版权声明：本文为CSDN博主「lady_killer9」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/lady_killer9/article/details/110246226
//部分转载
#include<bits/stdc++.h>
using namespace std;
int findmaxstring1(string s){
    int n=s.length();
    if(n==0)return 0;
    int l=0;
    int cnt=0;//记录最长不重复子串
    unordered_set<char>m;
    for(int r=0;r<n;++r){
        if(m.find(s[r])==m.end())m.insert(s[r]);//右侧对应的字符没找到，就放入set中
        else{                            //找到重复的字符
            cnt=cnt>m.size()?cnt:m.size();//更新长度
            while(m.find(s[r])!=m.end())//左边界向右移动直到没有重复的字符
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
int findmaxstring2(string s){
    int num=s.size();
    unordered_map<char,int>m;
    int cnt=0,l=0,r=0;
    while(r<num){
        m[s[r]]++;
        while(m[s[r]]==2){
            m[s[l++]]--;
        }
        r++;
        cnt=max(cnt,r-l);
    }
    return cnt;
}
int main(){
    string s;
    while (cin>>s)
    {
        cout<<findmaxstring2(s)<<endl;
    }
    return 0;  
}