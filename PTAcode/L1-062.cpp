#include<bits/stdc++.h>
using namespace std;
bool islucky(string s){
    int num[6];
    for(int i=0;i<6;i++){
        num[i]=s[i]-'0';
    }
    if(num[0]+num[1]+num[2]==num[3]+num[4]+num[5]){
        return true;
    }
    else return false;
}
int main(){
    int n;
    scanf("%d",&n);
    string s;
    while(n--){
        cin>>s;
        if(islucky(s))printf("You are lucky!\n");
        else printf("Wish you good luck.\n");
    }
    return 0;
}