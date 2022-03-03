#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
	char a[10];
	string s1;
	getline(cin,s1,'!');
	cout<<s1<<endl;
//	cout<<a<<endl;
//	cout<<a[0]<<endl;
//	cout<<a[1]<<endl;
//	cout<<strlen(a)<<endl;

	//string s;
	//cin>>s;
	//gets(s);无法输入 
	//cout<<s<<endl;
	//cout<<s[0]<<endl;
	//cout<<s.length()<<" "<<s.size()<<endl;
	//cout<<strlen(s)<<endl;是错误的 
	return 0;
}
