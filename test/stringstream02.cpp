#include<sstream>
#include<iostream>
using namespace std;
int main(){
    string s="lbc 20 lyx 20";
    stringstream ss(s);
    string temp;
    while(ss>>temp){
        if(isdigit(temp[0])){
            int num=stoi(temp);
            string k=to_string(num);
            cout<<k<<endl;
        }
    }
    return 0;
}