#include<bits/stdc++.h>
using namespace std;
struct node{
    string address;
    int data;
    string next;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string start="";
    int n;
    cin>>start>>n;
    node link[n];
    for(int i=0;i<n;i++){
        cin>>link[i].address>>link[i].data>>link[i].next;
    }
    for(int i=0;i<n;i++){
        if(start==link[i].address){
            
        }
    }
    return 0;
}