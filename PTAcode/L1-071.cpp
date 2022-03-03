#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        string s,ans="";
        cin>>s;
        for(char c:s){
            if(c=='y'){
                ans = ans +"0";
            }
            else{
                ans = ans +"1";
            }
        }
        int res=0,cnt=ans.length()-1;
        for(char c:ans){
            if(c=='1')res+=pow(2,cnt);
            cnt--;
        }
        cout<<res+1<<endl;
    }
    return 0;
}
