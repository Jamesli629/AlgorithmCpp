#include<iostream>
#include<vector>
using namespace std;

vector<int> add(vector<int>a,vector<int>b){
    vector<int>c;
    int x=0;
    for(int i=0;i<a.size()||i<b.size();++i){
        if(i<a.size())x+=a[i];
        if(i<b.size())x+=b[i];
        c.push_back(x%10);
        x/=10;
    }
    if(x)c.push_back(1);
    return c;
}
int main(){
    string a,b;
    cin>>a>>b;
    vector<int>A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
    vector<int> C=add(A,B);
	for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    cout<<endl;
    return 0;
}