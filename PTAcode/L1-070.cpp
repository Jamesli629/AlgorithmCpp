#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string>v;
    int cnt=0,cnt1=0;
    int locate = -1;
    while(true){
        cnt++;
        string s;
        getline(cin,s);
        if(s==".")break;
        else{
            v.push_back(s);
            if(s.find("chi1 huo3 guo1")!=string::npos){
                if(locate==-1){
                    locate=cnt;
                }
                cnt1++;
            }
        }
    }
    cout<<v.size()<<endl;
    if(cnt1==0)cout<<"-_-#\n";
    else cout<<locate<<" "<<cnt1<<endl;
	return 0;
}
