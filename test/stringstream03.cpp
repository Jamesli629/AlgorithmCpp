#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    string line;
    vector<string>words;
    string word;
    getline(cin,line);//input
    stringstream ss(line);//explicit construct
    while(ss>>word)
	    words.push_back(word);//add record
    vector<string>::iterator it = words.begin();
    while(it!=words.end())//out put
	    cout << *it++<<endl;
    return 0;
}