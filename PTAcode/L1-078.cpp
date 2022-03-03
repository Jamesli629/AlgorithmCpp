#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    string s[n];
    cin.ignore();
    for(int i=0;i<n;++i){
        getline(cin,s[i]);
    }
    int loc=-1;
    for(int i=0;i<n;i++){
        if(m==0){
            loc = i;
            break;
        }
        if(s[i].find("qiandao")<s[i].length() || s[i].find("easy")<s[i].length()){
            continue;
        }
        else{
            m--;
        }
    }
    if(loc==-1)printf("Wo AK le\n");
    else cout<<s[loc]<<endl;
    return 0;
}